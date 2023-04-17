#include "U8g2lib.h"
#include "bitmap.h"
#include <Arduino.h>
#include <ezButton.h>
#include <bits/stdc++.h>
#include <ArduinoJson.h>
#include <HardwareBLESerial.h>
// gps
// #include <NMEAGPS.h>
// #include <HardwareSerial.h>
// dual core stuff
#ifdef __cplusplus
#include <atomic>
#else
#include <stdatomic.h>
#endif

using namespace std;

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R2, /* clock=*/ 18, /* data=*/ 23, /* CS=*/ 5); // ESP32

// init ble
HardwareBLESerial &bleSerial = HardwareBLESerial::getInstance();

// arduinojson
StaticJsonDocument<300> incomingData;

// status
// call
struct callinfo : public std::mutex {
  String number;
  String name;
  bool state;
};
callinfo incomingCall = { };

//noti
struct notiinfo : public std::mutex{
  String src;
  String title;
  String body;
};
notiinfo currentNoti = { };

atomic<bool> isNotiNew;

// music
struct musicinfo : public std::mutex{
  String artist;
  String track;
};
musicinfo currentMusic = { };

// parser for incoming message
bool incomingParser(String str) {
  DeserializationError error = deserializeJson(incomingData, str);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return false;
  }
  return true;
}

TaskHandle_t ble;
void updateBle(void * pvParameters) {
  while (true) {
    // BLE stuff
    // this must be called regularly to perform BLE updates
    bleSerial.poll(); 

    while (bleSerial.availableLines() > 0) {
        Serial.print("Raw: ");
        char line[256]; 
        bleSerial.readLine(line, 256);
        String decodedMessage = String(line).substring(4, (strlen(line)-1));
        Serial.println(decodedMessage);

        if (incomingParser(decodedMessage)) {
            if (incomingData["t"].as<String>() == "musicinfo"){
                // saving data        
                currentMusic.lock(); 
                currentMusic.artist = incomingData["artist"].as<String>();
                currentMusic.track = incomingData["track"].as<String>();

                // displaying data
                Serial.print("[Music] ");
                Serial.print(currentMusic.artist); 
                Serial.print(" - "); 
                Serial.println(currentMusic.track);  
                currentMusic.unlock();
            }
            else if (incomingData["t"].as<String>() == "notify"){
                // saving data
                currentNoti.lock();
                currentNoti.src = incomingData["src"].as<String>();
                currentNoti.title = incomingData["title"].as<String>();
                currentNoti.body = incomingData["body"].as<String>();

                // displaying data
                Serial.print("[Notification] ");
                Serial.print(currentNoti.src); 
                Serial.print(": "); 
                Serial.println(currentNoti.title);
                Serial.println(currentNoti.body);
                isNotiNew.store(true);
                currentNoti.unlock();
            }
            else if (incomingData["t"].as<String>() == "call"){
                if (incomingData["cmd"].as<String>() == "incoming" && !incomingCall.state) {
                    // saving data
                    incomingCall.lock();
                    incomingCall.name = incomingData["name"].as<String>();
                    incomingCall.number = incomingData["number"].as<String>();
                    incomingCall.state = true;

                    // displaying data
                    Serial.print("[Incoming Call] ");
                    Serial.print(incomingCall.name);
                    Serial.print("("); Serial.print(incomingCall.number); Serial.println(")");
                    incomingCall.unlock();
                }
                else if (incomingData["cmd"].as<String>() == "end" && incomingCall.state) {
                    // saving data
                    incomingCall.lock();
                    incomingCall.state = false;
                    incomingCall.unlock();

                    // displaying data
                    Serial.print("Call ended");
                }
            }
        }
    }
  }
  // slow down dude - update notification
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
}

// init button
ezButton upbtn(21);
ezButton downbtn(19);

// init page
int page = 0;

// demo data
int gps_fix = 12;
String currentTime = "10:46";
String date = "Apr 16, 2023";
int gps_speed = 30;
String gps_heading = "North"; 


void drawFrame_home() {
  u8g2.drawXBMP(0, 0, 128, 64, frame_homepage);
}

void drawFrame_tab(String str) {
  u8g2.drawXBMP(0, 0, 128, 64, frame);
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(3, 9, str.c_str());
}

void drawInfo(int gps_fix, String currentTime, String date, int gps_speed, String gps_heading) {
  u8g2.setColorIndex(1);

  u8g2.setFont(u8g2_font_6x10_tr);
  String topLine = "Fix: " + String(gps_fix);
  u8g2.drawStr(3, 9, topLine.c_str());
  u8g2.drawStr(5, 50, date.c_str());
  u8g2.drawStr(96, 45, "km/h");
  // math time 
  int heading_len = gps_heading.length();
  int totalPixel = (heading_len*6)+(heading_len-1);
  int totalEmptySpace = 42 - totalPixel;

  u8g2.drawStr(89+round(totalEmptySpace/2), 55, gps_heading.c_str());

  u8g2.setFont(u8g2_font_crox5hb_tn);
  u8g2.drawStr(3, 37, currentTime.c_str());
  u8g2.drawStr(93, 35, String(gps_speed).c_str());

}

void drawMusicInfo() {
  u8g2.setFont(u8g2_font_6x12_te);
  currentMusic.lock();
  u8g2.drawStr(3, 16+10, (currentMusic.artist).c_str());
  u8g2.drawStr(3, 30+10, (currentMusic.track).c_str());
  currentMusic.unlock();
}

void drawCallInfo() {
  u8g2.setFont(u8g2_font_6x12_te);
  incomingCall.lock();
  u8g2.drawStr(3, 16+10, (incomingCall.name).c_str());
  u8g2.drawStr(3, 30+10, (incomingCall.number).c_str());
  incomingCall.unlock();
}

void drawRecentNoti() {
  u8g2.setFont(u8g2_font_6x12_te);
  currentNoti.lock();
  u8g2.drawStr(3, 16+10, (currentNoti.src).c_str());
  u8g2.drawStr(3, 26+10, (currentNoti.title).c_str());
  u8g2.drawStr(3, 36+10, (currentNoti.body).c_str());
  currentNoti.unlock();
}

void setup() {
  // enable onboard led
  pinMode(2, OUTPUT);
  // define varible state
  isNotiNew.store(false);
  // u8g.setFont(u8g_font_tpssb);  // no need to set the font, as we are not drawing any strings
  u8g2.setColorIndex(1);  // set the color to white
  u8g2.begin();
  Serial.begin(115200);
  if (!bleSerial.beginAndSetupBLE("panhdtw")) {
    while (true) {
      Serial.println("failed to initialize HardwareBLESerial!");
      delay(1000);
    }
  }
  // setup ble listener
  xTaskCreatePinnedToCore(updateBle, "", 10000, NULL, 1, &ble, 1);
}

void loop() {
  // tracking btn + switch page
  upbtn.loop();
  downbtn.loop();
  if (upbtn.isPressed()) {
    if (page == 2) page = 0;
    else page++;
  }
  else if (downbtn.isPressed()) {
    if (page == 0) page = 2;
    else page--;
  }

  // set appropriate page
  u8g2.firstPage();
  do {
    if (isNotiNew) {
      drawFrame_tab("Incoming-Notification");
      drawRecentNoti();
      continue;
    } else if (incomingCall.state) {
      drawFrame_tab("Incoming-Call");
      drawCallInfo();
      continue;
    }
    switch (page) {
      case 0: // homepage
        drawFrame_home();
        drawInfo(gps_fix, currentTime, date, gps_speed, gps_heading);
        break;
      case 1: // music player
        drawFrame_tab("Music");
        drawMusicInfo();
        break;
      case 2: // recent notification
        drawFrame_tab("Recent");
        drawRecentNoti();
      default: break;
    }
  } while ( u8g2.nextPage() );
  //  checking pause needed to read notification
  if (isNotiNew) {
    isNotiNew = false;
    delay(1500);  
  }
  u8g2.clearBuffer(); 
  delay(150);
}
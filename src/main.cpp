#include "U8g2lib.h"
#include "bitmap.h"
#include <Arduino.h>
#include <ezButton.h>
#include <bits/stdc++.h>
#include <ArduinoJson.h>
#include <HardwareBLESerial.h>
// gps
#include <NMEAGPS.h>
#include <HardwareSerial.h>
// dual core stuff
#ifdef __cplusplus
#include <atomic>
#else
#include <stdatomic.h>
#endif

using namespace std;

// lcd
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R2, /* clock=*/ 18, /* data=*/ 23, /* CS=*/ 5); // ESP32

// init ble
HardwareBLESerial &bleSerial = HardwareBLESerial::getInstance();

// init gps
NMEAGPS gps;
gps_fix fix;
HardwareSerial neogps(2);
// current gps info
struct GPSinfo{
  float speed;
  float latt;
  float longt; 
  float sat;
  int time;
};
GPSinfo currentGPS = { };


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

TaskHandle_t updateData;
void updatedata(void * pvParameters) {
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
  delay(200);
}

// init button
ezButton upbtn(21);
ezButton downbtn(19);

// init page
int page = 0;

// demo data
int gps_fixes = 12;
String currentTime = "10:46";
String date = "Apr 16, 2023";
int gps_speed = 30;


void drawFrame_home() {
  u8g2.drawXBMP(0, 0, 128, 64, frame_homepage);
}

void drawFrame_tab(String str) {
  u8g2.drawXBMP(0, 0, 128, 64, frame);
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(3, 9, str.c_str());
}

void drawInfo(int gps_fix, String currentTime, String date, int gps_speed) {
  u8g2.setColorIndex(1);

  u8g2.setFont(u8g2_font_5x7_tr);
  String topLine = "Sat: " + String(gps_fix);
  u8g2.drawStr(3, 9, topLine.c_str());
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(5, 50, date.c_str());
  u8g2.drawStr(95, 50, "km/h");
  // // math time 
  // int heading_len = gps.length();
  // int totalPixel = (heading_len*6)+(heading_len-1);
  // int totalEmptySpace = 42 - totalPixel;

  // u8g2.drawStr(89+round(totalEmptySpace/2), 55, gps.c_str());

  u8g2.setFont(u8g2_font_crox5hb_tn);
  u8g2.drawStr(3, 37, currentTime.c_str());
  String speed = (gps_speed < 10) ? ("0"+String(gps_speed)) : String(gps_speed);
  u8g2.drawStr(93, 40, speed.c_str());

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
  // begin gps serial
  neogps.begin(9600, SERIAL_8N1, 16, 17);
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
  xTaskCreatePinnedToCore(updatedata, "", 10000, NULL, 1, &updateData, 1);
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
        drawInfo(currentGPS.sat, currentTime, date, currentGPS.speed);
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
  // Acquiring gps data
  while (gps.available(neogps)) {
      fix = gps.read();
      currentGPS.speed = fix.speed_kph();
      currentGPS.latt = fix.latitude();
      currentGPS.longt = fix.longitude();
      currentGPS.sat = fix.satellites;
      currentGPS.time = fix.dateTime_ms();
      Serial.print(currentGPS.latt);
      Serial.print("-");
      Serial.print(currentGPS.longt);
      Serial.print("-");
      Serial.print(currentGPS.sat);
      Serial.print("-");
      Serial.println(currentGPS.time);
  }
}
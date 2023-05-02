#include "U8g2lib.h"
#include "timeConversion.h"
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

#include "bitmap.h"
#include "ic_direction.h"

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
struct GPSinfo : public std::mutex {
  float speed;
  float latt;
  float longt; 
  float sat;
  int hours, minutes, year, month, date;
};
GPSinfo currentGPS = { };
// month conversion
String monthName[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


// arduinojson
StaticJsonDocument<300> incomingData;

// ggmaps
DynamicJsonDocument incomingGmaps(512);
std::map<String, unsigned char *> icon;

void loadMapAsset() {
  icon["maneuver_depart"] = maneuver_depart;
  icon["maneuver_destination"] = maneuver_destination;
  icon["maneuver_destination_left"] = maneuver_destination_left;
  icon["maneuver_destination_right"] = maneuver_destination_right;
  icon["maneuver_destination_straight"] = maneuver_destination_straight;
  icon["maneuver_fork_left"] = maneuver_fork_left;
  icon["maneuver_fork_right"] = maneuver_fork_right;
  icon["maneuver_keep_left"] = maneuver_keep_left;
  icon["maneuver_keep_right"] = maneuver_keep_right;
  icon["maneuver_merge"] = maneuver_merge;
  icon["maneuver_merge_left"] = maneuver_merge_left;
  icon["maneuver_merge_right"] = maneuver_merge_right;
  icon["maneuver_name_change"] = maneuver_name_change;
  icon["maneuver_off_ramp_keep_left"] = maneuver_off_ramp_keep_left;
  icon["maneuver_off_ramp_keep_right"] = maneuver_off_ramp_keep_right;
  icon["maneuver_off_ramp_normal_left"] = maneuver_off_ramp_normal_left;
  icon["maneuver_off_ramp_normal_right"] = maneuver_off_ramp_normal_right;
  icon["maneuver_off_ramp_sharp_left"] = maneuver_off_ramp_sharp_left;
  icon["maneuver_off_ramp_sharp_right"] = maneuver_off_ramp_sharp_right;
  icon["maneuver_off_ramp_slight_left"] = maneuver_off_ramp_slight_left;
  icon["maneuver_off_ramp_slight_right"] = maneuver_off_ramp_slight_right;
  icon["maneuver_off_ramp_u_turn_left"] = maneuver_off_ramp_u_turn_left;
  icon["maneuver_off_ramp_u_turn_right"] = maneuver_off_ramp_u_turn_right;
  icon["maneuver_on_ramp_keep_left"] = maneuver_on_ramp_keep_left;
  icon["maneuver_on_ramp_keep_right"] = maneuver_on_ramp_keep_right;
  icon["maneuver_on_ramp_normal_left"] = maneuver_on_ramp_normal_left;
  icon["maneuver_on_ramp_normal_right"] = maneuver_on_ramp_normal_right;
  icon["maneuver_on_ramp_sharp_left"] = maneuver_on_ramp_sharp_left;
  icon["maneuver_on_ramp_sharp_right"] = maneuver_on_ramp_sharp_right;
  icon["maneuver_on_ramp_slight_left"] = maneuver_on_ramp_slight_left;
  icon["maneuver_on_ramp_slight_right"] = maneuver_on_ramp_slight_right;
  icon["maneuver_on_ramp_u_turn_left"] = maneuver_on_ramp_u_turn_left;
  icon["maneuver_on_ramp_u_turn_right"] = maneuver_on_ramp_u_turn_right;
  icon["maneuver_roundabout_enter_and_exit_ccw"] = maneuver_roundabout_enter_and_exit_ccw;
  icon["maneuver_roundabout_enter_and_exit_ccw_normal_left"] = maneuver_roundabout_enter_and_exit_ccw_normal_left;
  icon["maneuver_roundabout_enter_and_exit_ccw_normal_right"] = maneuver_roundabout_enter_and_exit_ccw_normal_right;
  icon["maneuver_roundabout_enter_and_exit_ccw_sharp_left"] = maneuver_roundabout_enter_and_exit_ccw_sharp_left;
  icon["maneuver_roundabout_enter_and_exit_ccw_sharp_right"] = maneuver_roundabout_enter_and_exit_ccw_sharp_right;
  icon["maneuver_roundabout_enter_and_exit_ccw_slight_left"] = maneuver_roundabout_enter_and_exit_ccw_slight_left;
  icon["maneuver_roundabout_enter_and_exit_ccw_slight_right"] = maneuver_roundabout_enter_and_exit_ccw_slight_right;
  icon["maneuver_roundabout_enter_and_exit_ccw_straight"] = maneuver_roundabout_enter_and_exit_ccw_straight;
  icon["maneuver_roundabout_enter_and_exit_ccw_u_turn"] = maneuver_roundabout_enter_and_exit_ccw_u_turn;
  icon["maneuver_roundabout_enter_and_exit_cw"] = maneuver_roundabout_enter_and_exit_cw;
  icon["maneuver_roundabout_enter_and_exit_cw_normal_left"] = maneuver_roundabout_enter_and_exit_cw_normal_left;
  icon["maneuver_roundabout_enter_and_exit_cw_normal_right"] = maneuver_roundabout_enter_and_exit_cw_normal_right;
  icon["maneuver_roundabout_enter_and_exit_cw_sharp_left"] = maneuver_roundabout_enter_and_exit_cw_sharp_left;
  icon["maneuver_roundabout_enter_and_exit_cw_sharp_right"] = maneuver_roundabout_enter_and_exit_cw_sharp_right;
  icon["maneuver_roundabout_enter_and_exit_cw_slight_left"] = maneuver_roundabout_enter_and_exit_cw_slight_left;
  icon["maneuver_roundabout_enter_and_exit_cw_slight_right"] = maneuver_roundabout_enter_and_exit_cw_slight_right;
  icon["maneuver_roundabout_enter_and_exit_cw_straight"] = maneuver_roundabout_enter_and_exit_cw_straight;
  icon["maneuver_roundabout_enter_and_exit_cw_u_turn"] = maneuver_roundabout_enter_and_exit_cw_u_turn;
  icon["maneuver_roundabout_enter_ccw"] = maneuver_roundabout_enter_ccw;
  icon["maneuver_roundabout_enter_cw"] = maneuver_roundabout_enter_cw;
  icon["maneuver_roundabout_exit_ccw"] = maneuver_roundabout_exit_ccw;
  icon["maneuver_roundabout_exit_cw"] = maneuver_roundabout_exit_cw;
  icon["maneuver_straight"] = maneuver_straight;
  icon["maneuver_turn_normal_left"] = maneuver_turn_normal_left;
  icon["maneuver_turn_normal_right"] = maneuver_turn_normal_right;
  icon["maneuver_turn_sharp_left"] = maneuver_turn_sharp_left;
  icon["maneuver_turn_sharp_right"] = maneuver_turn_sharp_right;
  icon["maneuver_turn_slight_left"] = maneuver_turn_slight_left;
  icon["maneuver_turn_slight_right"] = maneuver_turn_slight_right;
  icon["maneuver_u_turn_left"] = maneuver_u_turn_left;
  icon["maneuver_u_turn_right"] = maneuver_u_turn_right;
};

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

TaskHandle_t GPS;
void updateGPS(void * pvParameters) {
    // init gps
    NMEAGPS gps;
    gps_fix fix;
    HardwareSerial neogps(2);
    neogps.begin(9600, SERIAL_8N1, 16, 17);
    while (true) {
      while (gps.available(neogps)) {
            fix = gps.read();
            currentGPS.lock();
            currentGPS.speed = fix.speed_kph();
            currentGPS.latt = fix.latitude();
            currentGPS.longt = fix.longitude();
            currentGPS.sat = fix.satellites;
            currentGPS.hours = fix.dateTime.hours;
            currentGPS.minutes = fix.dateTime.minutes;
            currentGPS.year = fix.dateTime.full_year();
            currentGPS.month = fix.dateTime.month;
            currentGPS.date = fix.dateTime.date;
            currentGPS.unlock();
        }  
       delay(250);
    }
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
                if (incomingData["src"].as<String>() == "GMaps Parser") deserializeJson(incomingGmaps, incomingData["body"].as<String>());
                else {
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

// placeholder data
String currentTime = "00:00";
String date = "Jan 1, 2023";

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

void drawDirections() {
  u8g2.setFont(u8g2_font_6x12_te);
  if (incomingGmaps["icon"].as<String>() != "null") u8g2.drawXBMP(3, 11, 24, 24, icon[incomingGmaps["icon"].as<String>()]);
  else u8g2.drawStr(3, 11+10, (incomingGmaps["icon"].as<String>()).c_str());
  String next = "Next: " + (incomingGmaps["next"].as<String>());
  String remain = "Remain: " + (incomingGmaps["remain"].as<String>());
  u8g2.drawStr(3, 31+10, next.c_str());
  u8g2.drawStr(3, 41+10, remain.c_str());
  u8g2.drawStr(3, 51+10, (incomingGmaps["eta"].as<String>()).c_str());
}

void setup() {
  // loading icon to map for access
  loadMapAsset();
  // begin gps serial
  neogps.begin(9600, SERIAL_8N1, 16, 17);
  Serial.begin(9600);
  // define varible state
  isNotiNew.store(false);
  // u8g.setFont(u8g_font_tpssb);  // no need to set the font, as we are not drawing any strings
  u8g2.setColorIndex(1);  // set the color to white
  u8g2.begin();
  if (!bleSerial.beginAndSetupBLE("panhdtw")) {
    while (true) {
      Serial.println("failed to initialize HardwareBLESerial!");
      delay(1000);
    }
  }
  // waiting to pick up gps data
  u8g2.clearBuffer(); 
  // setup ble listener
  xTaskCreatePinnedToCore(updatedata, "", 10000, NULL, 1, &updateData, 1);
  // setup gps
  xTaskCreatePinnedToCore(updateGPS, "", 10000, NULL, 1, &GPS, 0);
}

void loop() {
  // tracking btn + switch page
  upbtn.loop();
  downbtn.loop();
  if (upbtn.isPressed()) {
    if (page == 3) page = 0;
    else page++;
  }
  else if (downbtn.isPressed()) {
    if (page == 0) page = 3;
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
      case 0: { // homepage 
        drawFrame_home();
        currentGPS.lock();
        dateTime data = convertToLocalTime(currentGPS.year, currentGPS.month, currentGPS.date, currentGPS.hours, currentGPS.minutes, 7);
        String hour = (data.hours < 10) ? "0"+String(data.hours) : String(data.hours);
        String minute = (data.minutes < 10) ? "0"+String(data.minutes) : String(data.minutes);
        currentTime = hour + ":" + minute;
        date = monthName[data.month-1] + " " + String(data.date) + ", " + String(data.year);
        drawInfo(currentGPS.sat, currentTime, date, currentGPS.speed);
        currentGPS.unlock();
        break;
      }
      case 1: { // music player 
        drawFrame_tab("Music");
        drawMusicInfo();
        break;
      }
      case 2: { // recent notification 
        drawFrame_tab("Recent");
        drawRecentNoti();
        break;
      }
      case 3: { // google maps
        drawFrame_tab("Directions");
        drawDirections();
      }
      default: break;
    }
  } while ( u8g2.nextPage() );
  //  checking pause needed to read notification
  if (isNotiNew) {
    isNotiNew = false;
    delay(1500);  
  }
  u8g2.clearBuffer(); 
  // delay(150);
}
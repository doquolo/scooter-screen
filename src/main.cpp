#include "U8g2lib.h"
#include "timeConversion.h"
#include <Arduino.h>
#include <ezButton.h>
#include <bits/stdc++.h>
#include <ArduinoJson.h>
#include <HardwareBLESerial.h>
// dual core stuff
#ifdef __cplusplus
#include <atomic>
#else
#include <stdatomic.h>
#endif
#include "bitmap.h"
#include "ic_direction.h"

using namespace std;

// for testing
long long int epoch = 1686551725;
long long int init_msec = 0;

// lcd
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R2, /* clock=*/ 18, /* data=*/ 23, /* CS=*/ 5); // ESP32

// init ble
HardwareBLESerial &bleSerial = HardwareBLESerial::getInstance();

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
  String artist = "";
  String track = "";
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
    while (bleSerial.availableLines() > 0) {
        Serial.print("Raw: ");
        char line[256]; 
        bleSerial.readLine(line, 256);
        String decodedMessage = String(line).substring(4, (strlen(line)-1));
        Serial.println(decodedMessage);
        if (decodedMessage.substring(0, 7) == "etTime(") {
          init_msec = millis();
          int startIndex, stopIndex;
          for (long long int i = 0; i < decodedMessage.length(); i++) {
            if (String(decodedMessage[i]) == "(") {
              startIndex = i;
            } else if (String(decodedMessage[i]) == ")") {
              stopIndex = i;
              break;
            }
          }
          String epoch_str = decodedMessage.substring(startIndex+1, stopIndex);
          epoch = strtoll(epoch_str.c_str(), nullptr, 10);
        }
        else if (incomingParser(decodedMessage)) {
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
ezButton selbtn(22);
ezButton pickbtn(15);

// init page
int page = 0;
// init selection
int sel = 0;

// placeholder data
String currentTime = "00:00";
String date = "Jan 1, 2023";

void drawFrame_home() {
  u8g2.drawXBMP(0, 0, 128, 64, frame_homepage);
}

void drawFrame_tab(String str) {
  // u8g2.drawXBMP(0, 0, 128, 64, frame);
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(3, 9, str.c_str());
}

void drawInfo(String currentTime, String date) {
  u8g2.setColorIndex(1);
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(5, 50, date.c_str());
  currentMusic.lock();
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(5, 59, String(currentMusic.track).c_str());
  currentMusic.unlock();
  u8g2.setFont(u8g2_font_crox5hb_tn);
  u8g2.drawStr(3, 37, currentTime.c_str());
}

void drawMusicInfo(int sel, bool activate) {
  String func[6] = {"play", "pause", "next", "previous", "volumeup", "volumedown"};
  if (activate) {
    // TODO: this function can only be executed once although its seem to be running as intended
    Serial.println("Command: {t:\"music\", n:\"" + func[sel]+ "\"}\r\n");
    String content = "{t:\"music\", n:\"" + func[sel]+ "\"}\r\n";
    bleSerial.println(content.c_str());
  }
  u8g2.setFont(u8g2_font_6x12_te);
  currentMusic.lock();
  u8g2.drawStr(3, 16+10, (currentMusic.artist).c_str());
  u8g2.drawStr(3, 30+10, (currentMusic.track).c_str());
  u8g2.drawStr(3, 44+10, (String(sel) + ": " + func[sel]).c_str());
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
  Serial.begin(9600);
  // define varible state
  isNotiNew.store(false);
  u8g2.setColorIndex(1);  // set the color to white
  u8g2.begin();
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
  // this must be called regularly to perform BLE updates
  bleSerial.poll(); 
  
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
      // TODO: update time via gadgetbridge
        // drawFrame_home();
        dateTime data = getTime(epoch, 25200, (millis() - init_msec) / 1000);
        String hour = (data.hours < 10) ? "0"+String(data.hours) : String(data.hours);
        String minute = (data.minutes < 10) ? "0"+String(data.minutes) : String(data.minutes);
        currentTime = hour + ":" + minute;
        date = monthName[data.month-1] + " " + String(data.date) + ", 20" + String(data.year);
        drawInfo(currentTime, date);
        break;
      }
      case 1: { // music player 
        drawFrame_tab("Music");
        // read nav button
        selbtn.loop();
        pickbtn.loop();
        
        bool activate = false;
        if (pickbtn.isPressed()) {
          if (sel == 5) sel = 0;
          else sel++;
        }
        if (selbtn.isPressed()) {
          Serial.print("Activating: ");
          Serial.println(sel);
          activate = true;
        }

        drawMusicInfo(sel, activate);
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
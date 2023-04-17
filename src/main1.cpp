#include <ArduinoJson.h>
#include <HardwareBLESerial.h>

HardwareBLESerial &bleSerial = HardwareBLESerial::getInstance();

// arduinojson
StaticJsonDocument<300> incomingData;

// status
// call
struct {
  String number;
  String name;
  bool state;
} incomingCall;

//noti
struct {
  String src;
  String title;
  String body;
} currentNoti;

// music
struct {
  String artist;
  String track;
} currentMusic;

bool incomingParser(String str) {
  DeserializationError error = deserializeJson(incomingData, str);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return false;
  }
  return true;
}

void setup() {
  Serial.begin(115200);
  if (!bleSerial.beginAndSetupBLE("panhdtw")) {
    while (true) {
      Serial.println("failed to initialize HardwareBLESerial!");
      delay(1000);
    }
  }
}

void loop() {
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
                currentMusic.artist = incomingData["artist"].as<String>();
                currentMusic.track = incomingData["track"].as<String>();

                // displaying data
                Serial.print("[Music] ");
                Serial.print(currentMusic.artist); 
                Serial.print(" - "); 
                Serial.println(currentMusic.track);  
            }
            else if (incomingData["t"].as<String>() == "notify"){
                // saving data
                currentNoti.src = incomingData["src"].as<String>();
                currentNoti.title = incomingData["title"].as<String>();
                currentNoti.body = incomingData["body"].as<String>();

                // displaying data
                Serial.print("[Notification] ");
                Serial.print(currentNoti.src); 
                Serial.print(": "); 
                Serial.println(currentNoti.title);
                Serial.println(currentNoti.body);
            }
            else if (incomingData["t"].as<String>() == "call"){
                if (incomingData["cmd"].as<String>() == "incoming" && !incomingCall.state) {
                    // saving data
                    incomingCall.name = incomingData["name"].as<String>();
                    incomingCall.number = incomingData["number"].as<String>();
                    incomingCall.state = true;

                    // displaying data
                    Serial.print("[Incoming Call] ");
                    Serial.print(incomingCall.name);
                    Serial.print("("); Serial.print(incomingCall.number); Serial.println(")");
                }
                else if (incomingData["cmd"].as<String>() == "end" && incomingCall.state) {
                    // saving data
                    incomingCall.state = false;

                    // displaying data
                    Serial.print("Call ended");
                }
            }
        }
    }
    delay(250);
}
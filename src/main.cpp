#include <M5Core2.h>
#include <ArduinoJson.h>
String searched_object;

void setup() {
  M5.begin();
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, 33, 32);  //33,32はそれぞれTX,RX。
}

void readSerial(void){
  StaticJsonDocument<1000> doc;
  String recvStr = Serial2.readStringUntil('\n');
  //static char recvStr[] = "{\"num\":1,\"obj\":[{\"prob\":0.869135916,\"x\":35,\"y\":24,\"w\":512,\"h\":454,\"type\":\"person\"}],\"running\":\"Object Recognition\"}";
  DeserializationError err = deserializeJson(doc, recvStr);
  if (err) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(err.f_str());
    return;
  }
  Serial.println(recvStr);
  int obj_num = doc["num"];
  searched_object = "None";
  for (int i=0; i<obj_num; i++){
    String type = doc["obj"][i]["type"].as<String>();
    if (type.equals("person")){
      searched_object = type;
      return;
    }
    else{
      searched_object = type;
    }
  }
  return;
}

void loop(){
  if(Serial2.available()){
    readSerial();
    M5.update();
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0,0);
    M5.Lcd.setTextSize(3);
    M5.Lcd.println(searched_object);
  }
}
/*
Internet Down Detector
By Fernando Garcia (fg1998) 2022

"All these words are yours, except Europa
 Attempt no landing there
 use them together
 use then in peace"
*/

#include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager
#include <ESP8266Ping.h>  // https://github.com/dancol90/ESP8266Ping
#include <BlockNot.h>     // https://github.com/EasyG0ing1/BlockNot


#define LED_PIN 15
#define BUTTON_PIN 14

WiFiManager wifiManager;

BlockNot internetCheck(10, SECONDS);

void resetButtonPressed() {
  Serial.println("reseting WIFI settings ...");
  blink(3);
  //wifiManager.resetSettings();
}


void setup() {
  Serial.begin(9600);
  Serial.println("Starting ...");
  blink(3);
  
  pinMode(LED_PIN, OUTPUT);
  //pinMode(BUTTON_PIN, INPUT);

  wifiManager.autoConnect("IDDAP");
  
  Serial.println("Connected.");

    
}

void loop() {

  
  if(digitalRead(BUTTON_PIN) == HIGH)
    resetButtonPressed();

  if (internetCheck.TRIGGERED) {
    bool ret = Ping.ping("www.google.com");
    if(ret){
      Serial.println("ok");
      blink(1);
    }
    else
    {
      Serial.println("fail");
      blink(2);
    }
  }


}


void blink(int qt){
  digitalWrite(LED_PIN, LOW);
  for(int i=0; i<qt; i++){
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
}

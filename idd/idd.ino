
//#include <ESP8266WiFi.h>
#include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager
#include <ESP8266Ping.h>  // https://github.com/dancol90/ESP8266Ping


#define LED_PIN 0
#define BUTTON_PIN 2

WiFiManager wifiManager;

void setup() {
  Serial.begin(9600);

  Serial.println("Iniciando ...");

  
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  blink(5);
  

//wifiManager.resetSettings();

//wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

  wifiManager.autoConnect("IDDAP");
  
  Serial.println("Connected.");
  
  
  
}

void loop() {

 int btnRead = digitalRead(BUTTON_PIN);
 if(btnRead == 1) {
   blink(3);
   wifiManager.resetSettings();
   wifiManager.autoConnect("IDDAP");
 }

  Serial.println("ping...");
  delay(3000);  

  bool ret = Ping.ping("www.google.com");
  if(ret)
  {
     blink(1);
  }
  else
  {
    blink(3);
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

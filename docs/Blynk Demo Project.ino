#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_AUTH_TOKEN "o-A4EfLhwCQdP2lg22Tt3ajEy50MN-hE" //Enter your blynk auth token
float x = 0.0;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Eshwar";//Enter your WIFI name
char pass[] = "qAz123@#$";//Enter your WIFI password
BlynkTimer timer;
//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(D0, param.asInt());
}
void sensorRead ()
{
  x = analogRead(A0);
  float temp = (x/1024.0)*3300;
  float cel = temp/10;
  Serial.print(cel);
  Blynk.virtualWrite(V1,cel); 
}


void setup() {
  //Set the LED pin as an output pin
  pinMode(D0, OUTPUT);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(300L,sensorRead);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
  timer.run();
}

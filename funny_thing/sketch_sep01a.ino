#include "DHT.h"

int value = 0;
int dhtpin = 6;
int heat = 0;
unsigned long t;

DHT dht(dhtpin);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  pinMode(heat, INPUT);
  pinMode(8, OUTPUT);
  Serial.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  t = millis();
  t = t/1000;
  int h = dht.readHumidity();
  int temp = dht.readTemperature();

  int light = digitalRead(heat);

  if(light < 200) {
    digitalWrite(8, HIGH);
  }
  
}

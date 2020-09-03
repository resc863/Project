#include "DHT.h"

int value = 0;
int dhtpin = 3;
int heat = 8;
int motor1 = 4;
int motor2 = 7;
unsigned long t;

DHT dht(dhtpin, DHT11);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  pinMode(heat, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  t = millis();
  t = t/1000;
  int h = dht.readHumidity();
  int temp = dht.readTemperature();

  int light = analogRead(heat);
  
  Serial.print("습도: ");
  Serial.println(h);

  Serial.print("거리: ");
  Serial.println(light);
  
  if(light > 200) {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(6, HIGH);
  }
  
  
  delay(500);
}

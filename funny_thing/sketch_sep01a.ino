#include "DHT.h"

int value = 0;
int dhtpin = 3;
int heat = 8;
int motor1 = 4;
int motor2 = 7;
int GP2Y1023 = 2;
unsigned long pulse = 0;    
float ugm3 = 0;    
unsigned long t;

DHT dht(dhtpin, DHT11);

float discomfortIndex(float temp, float humi) {
  return (1.8f*temp)-(0.55*(1-humi/100.0f)*(1.8f*temp-26))+32;
}
float pulse2ugm3(unsigned long pulse) {
  float value = (pulse - 1400) / 14.0;                
  if (value > 300) {                                        
    value = 0;                                                
  }
  return value;      
}
void setup() {
  // put your setup code here, to run once:
  dht.begin();
  pinMode(heat, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(GP2Y1023, INPUT); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  t = millis();
  t = t/1000;
  int h = dht.readHumidity();
  int temp = dht.readTemperature();

  int light = digitalRead(heat);
  
  Serial.print("습도: ");
  Serial.println(h);

  Serial.print("거리: ");
  Serial.println(light);

  
  float bad=discomfortIndex(temp,h);

  Serial.print("불쾌지수: ");
  Serial.println(bad);
  
  pulse = pulseIn(GP2Y1023, LOW, 20000); 
  ugm3 = pulse2ugm3(pulse);                                                      
  Serial.print(ugm3);                         
  Serial.println(" ug/m3");

  Serial.println("===========================");

  
  if(light == 0&&bad>80) {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(6, HIGH);
  }
  else if(light==0&&ugm3>80)
  {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
  }
  else {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(6, LOW);
  }
  delay(1000);
}

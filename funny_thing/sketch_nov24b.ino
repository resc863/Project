#include <Servo.h>
#include <DHT.h>

int value = 0;
int dhtpin = 6;
int pre = 0;
int tmp = 0;
unsigned long t;

Servo servo;
DHT dht(dhtpin, 11);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  servo.attach(0);
  servo.write(value);
}

void loop() {
  // put your main code here, to run repeatedly:
  t = millis();
  t = t/1000;
  int h = dht.readHumidity();
  int temp = dht.readTemperature();
  
  if ((t-pre)> 60) {
    value = 180;
    servo.write(value);
    delay(2000);
    pre = t;
  }

  if(h>60){
    if ((t-tmp)>10) {
      value = 180;
      servo.write(value);
      delay(5000);
      tmp = t;
    }
  }
  value = 0;
  servo.write(value);
}

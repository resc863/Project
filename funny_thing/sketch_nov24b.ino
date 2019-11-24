#include <Servo.h>
#include <DHT.h>

int value = 0;
int dhtpin = 6;
int pre = 0;
unsigned long t;

Servo servo;
DHT dht(dhtpin, 11);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
  servo.attach(9);
  servo.write(value);
}

void loop() {
  // put your main code here, to run repeatedly:
  t = millis();
  int h = dht.readHumidity();
  int temp = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.println(h);

  Serial.print("Temperature: ");
  Serial.println(temp);

  if ((t-pre)> 10000) {
    value = 180;
    servo.write(value);
    delay(2000);
    value = 0;
    servo.write(value);
    pre = t;
  }
  
}

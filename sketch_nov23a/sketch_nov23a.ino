#include <IRremote.h>
#include <DHT.h>
#include <LiquidCrystal.h>
#include <Servo.h>

int value = 0;
int RECV_PIN = A1; //define input pin on Arduino
int piezoPin = 9; // 부저의 ⊕극을 오렌지 보드 8번에 연결 
int dhtpin = 6;
int distance;
int trig = 7;
int echo = 8;
unsigned long t;

Servo servo;
DHT dht(dhtpin, 11);
IRrecv irrecv(RECV_PIN);
decode_results results;
LiquidCrystal lcd(0,1,2,3,4,5);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  servo.attach(9);
  lcd.begin(16,2);
  dht.begin();
  irrecv.enableIRIn();
  
  lcd.setCursor(0,0);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode (piezoPin, OUTPUT); 
}

void loop() {
  lcd.clear();
  t = millis();
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(piezoPin, HIGH);
  int cds = analogRead(A0);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  distance = pulseIn(echo, HIGH)/58;
  
  int h = dht.readHumidity();// 습도를 측정합니다.
  int temp = dht.readTemperature();

  if (irrecv.decode(&results)) {
    lcd.setCursor(5,0);
    switch (results.value) {
      case 0xFF6897: 
        lcd.print(0);
        value += 30;
        if (value == 180) {
          value = 0;            
        }
      case 0xFF30CF: 
        lcd.print(1);
        value -= 30;
        if (value == 180) {
          value = 0;
        }
    }
    servo.write(value);
    irrecv.resume(); // Receive the next value
  }

  lcd.setCursor(5,0);
  lcd.print(t/1000);

  lcd.setCursor(5,1);
  lcd.print(distance);
  
  lcd.setCursor(0,0);
  lcd.print(h);
  lcd.setCursor(3,0);
  lcd.print("%");
  
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.setCursor(2,1);
  lcd.print(" c");
  
  delay(1000);
}

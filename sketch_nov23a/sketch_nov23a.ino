#include <DHT.h>
#include <LiquidCrystal.h>

int piezoPin = 9; // 부저의 ⊕극을 오렌지 보드 8번에 연결 
int dhtpin = 6;
int distance;
int trig = 7;
int echo = 8;

DHT dht(dhtpin, 11);

LiquidCrystal lcd(0,1,2,3,4,5);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  dht.begin();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode (piezoPin, OUTPUT); 
}

void loop() {
  lcd.clear();
  digitalWrite(piezoPin, HIGH);
  // put your main code here, to run repeatedly:
  int cds = analogRead(A0);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  distance = pulseIn(echo, HIGH)/58;
  
  int h = dht.readHumidity();// 습도를 측정합니다.
  int t = dht.readTemperature();

  lcd.setCursor(8,0);
  lcd.print(distance);

  lcd.setCursor(8,1);
  lcd.print(cds);
  
  lcd.setCursor(0,0);
  lcd.print(h);
  lcd.setCursor(3,0);
  lcd.print("%");
  
  lcd.setCursor(0,1);
  lcd.print(t);
  lcd.setCursor(2,1);
  lcd.print(" c");
  
  delay(500);
  digitalWrite(piezoPin, LOW);
  delay(500);
}

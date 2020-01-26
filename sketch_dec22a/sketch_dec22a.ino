#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Time.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

float circle = 0.8;  
float bySpeed = 0; 
float ckTime = 0;  
float uckTime = 0; 
float cycleTime = 0;  
int count = 0; 
boolean temp = 0;  
int trig = 8;
int echo = 9;

void setup() {
  // I2C LCD를 초기화 합니다..
  lcd.init();
  // I2C LCD의 백라이트를 켜줍니다.
  lcd.backlight();
  pinMode(trig, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() { 
  
  boolean check = digitalRead(A0); // 리드스위치의 상태를 확인합니다.
  
  if(check == 1 && temp == 0){  // 리드 스위치가 열릴 때(닫힘 -> 열림)
    ckTime = millis();  
    ckTime = ckTime + 100;
    temp = 1;  
  }
  
  else if(check == 0 && temp == 1 && count > 5){ 
    uckTime = millis(); 
    uckTime = uckTime +100;
      
    cycleTime = (uckTime - ckTime) / 1000;
    
    bySpeed = (circle / cycleTime) * 3.6; 
    temp = 0; 
    count = 0; 
  }
  
  if(check == 1){  
    count++;
    if(count > 150){ 
      bySpeed = 0;
    }
  }

  lcd.setCursor(0,0);           
  lcd.print("Speed: ");
  lcd.print((int)bySpeed);
  lcd.println("Km/h");
  delay(100);
  lcd.clear();      
}

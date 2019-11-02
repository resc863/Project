#include "DHT.h"       // DHT.h 라이브러리를 포함한다
#include <Servo.h>
#define DHTPIN 2      // DHT핀을 2번으로 정의한다(DATA핀)

#define DHTTYPE DHT11  // DHT타입을 DHT11로 정의한다

DHT dht(DHTPIN, DHTTYPE);  // DHT설정 - dht (디지털2, dht11)
Servo servo;
int value = 0;

void setup() {
  servo.attach(7);
  Serial.begin(9600);    // 9600 속도로 시리얼 통신을 시작한다

}

 

void loop() {
  int cds = analogRead(A1);

  delay(1000);

  int h = dht.readHumidity();  // 변수 h에 습도 값을 저장 

  int t = dht.readTemperature(); // 변수 t에 온도 값을 저장

  if(h > 50)
  {
     value +=30;
    if(value==180)
      value =0;
    else
      value =0;
    servo.write(value);
  }

  Serial.print("Humidity: ");  // 문자열 Humidity: 를 출력한다.

  Serial.print(h);  // 변수 h(습도)를 출력한다.

  Serial.print("%\t");  // %를 출력한다

  Serial.print(cds);

  Serial.print("\t");  // %를 출력한

  Serial.print("Temperature: ");  // 이하생략

  Serial.print(t);

  Serial.println(" C");

}

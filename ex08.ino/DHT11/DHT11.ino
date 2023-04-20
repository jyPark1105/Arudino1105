#include <DHT.h>
#define DHTPIN 2 // pin 2번
#define DHTTYPE DHT11 // type -> DHT11 유형

DHT dht(DHTPIN, DHTTYPE); // 일종의 dht 함수 선언

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(2000); // 처음 2초 기다림

int h = dht.readHumidity();     // 습도값을 읽어 h에 초기화
int t = dht.readTemperature();  // 온도값을 읽어 t에 초기화

Serial.print("Humidity: ");
Serial.print(h);
Serial.println("℃"); // 18 ~ 20 습도 출력

Serial.print("TempC: ");
Serial.print(t);
Serial.println("℃"); // 21 ~ 23 온도 출력

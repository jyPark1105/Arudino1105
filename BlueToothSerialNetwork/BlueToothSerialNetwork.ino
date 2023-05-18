#include <SoftwareSerial.h> // 근거리 무선통신을 할 수 있게 하는 정적 라이브러리
#include <DHT.h> // DHT11 센서 사용하기 위한 함수를 담은 정적 라이브러리
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); // DHT 소속의 dht()함수 구현
SoftwareSerial mySerial(2,3); // 클래스 SoftwareSerial을 mySerial이라 부르겠다 : mySerial(Tx,Rx);
                              // *** Rx = Receive(수신), Tx = Transmit(송신)

void setup() {            // 시리얼 모니터 ~ 블루투스 연결
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
    int h = dht.readHumidity();
    int t = dht.readTemperature();

    if(mySerial.available()){ // mySerial 클래스가 available하면 읽은 값을 Serial모니터에 써라.
        int h_mySerial = h;
        int t_mySerial = t;
        Serial.print("TempC : ");
        Serial.write(t_mySerial);
        Serial.print("Humidity : ");
        Serial.write(h_mySerial);
        Serial.print("\n");
    }

    else if(Serial.available()){ // Serial이 available하면 t값을 휴대폰에 출력해라.
        int h_Serial = h_mySerial;
        int t_Serial = t_mySerial;
        Serial.print("TempC : ");
        Serial.write(t_Serial);
        Serial.print("Humidity : ");
        Serial.write(h_Serial);// 이 경우 휴대폰과 연결하므로 휴대폰에 Serial에서 읽은 값이 출력 됨.
        Serial.print("\n");

    }
}
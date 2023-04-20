void setup() {
    Serial.begin(9600);
}                                                        
// LM35(아날로그 온습도센서)를 활용하여 실내의 온도를 측정하기
 // 내부저항이 있어 따로 저항을 연결하지 않아도 됨. -55 ~ 150도 사이의 실내온도를 측정할 수 있다.

/* 설계

Process 1. 입력 부분이 A1. 입력부분을 읽을 변수 reading 선언, 온도 변수 tempC 선언
Process 2. LM35 공식 이용
Process 3. tempc를 Serial moniter 출력 */
                                                      

void loop() {
      int pin = A1;                                    //                              (1-1 process)
      int reading = analogRead(pin);                   // pin <- A1이므로 pin을 넣는다. (1-2 process)
      float tempC = (5.0* reading * 100.0)/1024.0;     // LM35공식                     (1-3, 2 process)
      Serial.print(tempC);
      Serial.println("℃");                 
      delay(1000);                                     // Detecting the temperature rapidly for a sec in my room.
}

      

#include <Servo.h>
Servo Hello_Servo; // Servo를 hello_Servo로 칭하겠다.

int angle = 90; // 첫 각도
int Survo_Pin = 12; // 서보 핀 번호를 지정
int pushPin = 7; // 푸시 버튼을 7번 핀에 연결
int state=0; // 회전방향 설정 (state 값 0 :  시계 방향 / 1 : 반시계 방향)

void setup() { // 준비 단계
   Hello_Servo.attach(Survo_Pin); // **Servo를 12번 핀으로 지정 ≒ digitalRead(12);
   pinMode(pushPin, INPUT); // 푸시 버튼이 연결된 핀을 입력 모드로 설정
   Serial.begin(9600); // 시리얼 모니터와 통신 
   Serial.println("Enter the push button."); // 시리얼 모니터에 문자열 출력
}

void loop() { // 루프문 내에 모터가 돌아가는 코딩을 작성해야함.
    if (digitalRead(pushPin) == HIGH) 
    {
       if(state == 0) 
       {  
        angle ++; 
        if(angle >= 180){
          state = 1;
        }
        Hello_Servo.write(angle); // 
        delay(25); // 25ms당 1degree, 180degree = 25*180 = 4.5s
        Serial.println(angle); // 현재 각도 -> 시리얼 모니터 화면에 출력
       }
       
       else if(state == 1)
       { 
       angle --;
       if (angle <= 0) state = 0; 
        Hello_Servo.write(angle); // pos가 가진 각도의 위치로 이동 ≒ digitalWrite();
        delay(50); // 50ms당 1degree, 180degree = 50*180 = 9s 인데 5deg씩 줄어드니 1.8s일 것
       } 
}
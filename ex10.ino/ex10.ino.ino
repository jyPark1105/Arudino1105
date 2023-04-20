#include <IRremote.h> 정적 라이브러리 담기

int RECV_PIN = 11; // 적외선 수신기 번호 설정
IRrecv irrecv(RECV_PIN); // 적외선 수신기 클래스 선언, 객체
decode_results results;  // 결과값 담는 클래스 선언, 객체

// **irrecv() 객체함수, results 객체를 갖고있음.

void setup()
{  
  Serial.begin(9600);
// In case the interrupt driver crashes on setup, give a clue
// to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}
void loop() {
   if (irrecv.decode(&results)) {      // 결과값의 주소가 해석되면 클래스에 담기
    Serial.println(results.value, HEX); // 결과의 값, 16진수로 출력하기
    irrecv.resume(); // 신호 계속 받기
    } 
    delay(100); 
}

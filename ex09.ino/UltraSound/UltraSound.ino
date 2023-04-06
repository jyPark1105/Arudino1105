// 순서 : 1. 전역변수 선언, 2. trig과 echo의 입출력모드 설정하기, 시리얼모니터 시작.
// 3. duration과 distance를 선언하기(공식)

int trigPin = 6;
int echoPin = 13; // 1. 전역변수 선언

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT); // 발신부
pinMode(echoPin, INPUT);  // 수신부
}                                                   

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, HIGH);
delay(2000); // 2초마다 0, 1 반복
digitalWrite(trigPin, LOW); // 발신 준비
float duration = pulseIn(echoPin, HIGH); // 수신부가 입력받는 시간 설정
float distance = ((float)340*duration/10000)/2; // distance 공식

Serial.print("duration: ");
Serial.print(duration);
Serial.println("㎲"); // 수신부가 HIGH에서 LOW가 되기까지의 시간
Serial.print("distance: ");
Serial.print(distance);
Serial.println("cm"); // 수신부가 수신받은 거리
}

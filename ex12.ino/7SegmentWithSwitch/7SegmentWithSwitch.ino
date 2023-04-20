
byte Numbers[16][8] = { // 10 8 굳이 안써도 됨. 어차피 변수값 넣을 것임
{1,1,1,1,1,1,0,0}, // 0
{0,1,1,0,0,0,0,0}, // 1
{1,1,0,1,1,0,1,0}, // 2
{1,1,1,1,0,0,1,0}, // 3
{0,1,1,0,0,1,1,0}, // 4
{1,0,1,1,0,1,1,0}, // 5
{1,0,1,1,1,1,1,0}, // 6
{1,1,1,0,0,1,0,0}, // 7
{1,1,1,1,1,1,1,0}, // 8
{1,1,1,1,0,1,1,0}, // 9
{1,1,1,0,1,1,1,0}, // A
{0,0,1,1,1,1,1,0}, // B
{1,0,0,1,1,1,0,0}, // C
{0,1,1,1,1,0,1,0}, // D
{1,0,0,1,1,1,1,0}, // E
{1,1,0,0,1,1,1,0}  // F , 16진수 값을 7-segment에 표현하기 위해 byte 설정함
};



















byte Numbers[][] = {}; // pin에 들어갈 bit 선언하기
int Pin = 2; // a~dp -> 2~9번 pin
int Num = 0; // 세로인덱스
int i; // 가로인덱스
int SwButton = 12;

void displayNumbers(int n) {
    for(i = 0; i < 8; i++)
      {
        digitalWrite(Pin + i, Numbers[n][i])
      }
    } // 단순히 led만 껐다켰다 하는 함수
}
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(SwButton, INPUT); // 스위치 입력받기
    for(i = 0; i < 8; i++)
    {
      pinMode(Pin + i, OUTPUT); // 2~9번 핀 출력상태
    }
    digitalWrite(9, HIGH); // dp부분 켜놓기
}

void loop() {
  // put your main code here, to run repeatedly:
    if(digialWrite(Swbutton) == HIGH) // 스위치 눌림.
    {
      ++Num; // 1 ~ F , 0 차례대로 출력할거임
      displayNumbers(Num); // 스위치버튼이 눌리면 displayNumbers함수를 호출해라 n대신에 Num 넣고
    }
    else {
      Serial.println("버튼을 눌러주세요.");
      delay(10000); // 10초마다 시리얼 모니터에 버튼을 눌러달라는 표시를 해줌.
    }
    if(Num > 15) // Num 16, 즉 세로줄이 16번째가 되면 다시 0번째 줄로(세로줄 0 ~ 15번째까지 있음)
    {
      Num = 0;
    }
}

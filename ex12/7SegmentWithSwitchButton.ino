/* 뭘 코딩할건지
스위치 + 7-segment를 구현할 것
배열을 통해서
byte numbers라는 배열을 선언하는데 세로줄: 16줄, 가로칸 8칸 / a ~ dp -> 2 ~ 9번 pin 연결
*/
int Pin = 2; // a부터 1씩 증가하여 a~dp까지 2~9번 핀의 값 출력
int Num = 0; // 세로 인덱스
int i;       // 가로 인덱스
byte numbers[16]= {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xF6, 0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E};

void displayNumbers(int n) {
      for(i = 0; i < 8; i++)
    {
      boolean state = bitRead(numbers[n], 7-i);
      digitalWrite(Pin + i, state);
    }
};

void setup() {
    pinMode(12, INPUT); // 증가 스위치
    pinMode(13, INPUT); // 감소 스위치
    for(i = 0; i < 8; i++)
    {
      pinMode(Pin + i, OUTPUT); // 2~9까지 출력상태로 설정(0 or 1 value)
    }
    digitalWrite(9, HIGH); // dp부분 켜놓고 시작(소수점)
};

// 루프문에서 pin들을 켜는 작업을 해야함.
void loop() {
    if(digitalRead(12) == HIGH){
      ++Num;
        if(Num > 15)
         {   // 세로줄이 9번째 이후는 없으니까 다시 초기화 시켜줌
         Num = 0;
         }
    }
    if(digitalRead(13) == HIGH){ // 감소하게 만들기
      --Num;
        if(Num < 0)
         {   // 세로줄이 9번째 이후는 없으니까 다시 초기화 시켜줌
         Num = 15;
         }
    }
    displayNumbers(Num);
    delay(2000); // 1초 지연
};

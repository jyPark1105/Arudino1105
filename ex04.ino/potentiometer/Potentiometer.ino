void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    int a = analogRead(A0);
    Serial.println(a);
    delay(100);
}
/* A0의 아날로그 입력값을 Serial moniter에 출력.
보이는 영상에서는 가변저항기(potentiometer)의 반시계방향(왼쪽 부분)에는 5V, 시계방향(오른쪽 부분)에는 0V를
연결해놨기 때문에 값이 왼쪽 ~ 오른쪽 : 0 ~ 1023이 아닌 1023 ~ 0으로 출력되는 것을 알 수 있다.

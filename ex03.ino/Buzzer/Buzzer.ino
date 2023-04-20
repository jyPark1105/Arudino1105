int myNotes[] = {784, 659, 784, 659, 784, 880, 659};
int myDu[] = {250, 250, 250, 250, 250, 250, 500};
int i, j;
void setup() {
  // put your setup code here, to run once:
    while(j < 3) // 총 3번의 연주가 진행됨.
    {
        **for(i = 0; i < 7; i++) // 각 주파수에 해당하는 음 7개를 부저가 연주함.
        {
        ** tone(6, myNotes[i], myDu[i]); // tone함수 알기
        delay(myDu[i]);
        } 
        j++;
    } noTone(6);
}

void loop() {
  // put your main code here, to run repeatedly:

}

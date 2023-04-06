int ledPin[] = {3, 6, 9};
int delayT[] = {500, 1000, 2000};
int i;
void setup() {
  // put your setup code here, to run once:
  for(i = 0; i < 3; i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i = 0; i < 3; i++)
  {
    digitalWrite(ledPin[i], HIGH);
    delay(delayT[i]);
    digitalWrite(ledPin[i], LOW);
    delay(delayT[i]);
  }
}

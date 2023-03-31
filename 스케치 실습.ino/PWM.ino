int ledPin1 = 6;
int ledPin2 = 11;

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(ledPin1, 255);
analogWrite(ledPin2, 20);
}

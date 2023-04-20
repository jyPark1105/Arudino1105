int ledPin = 12;
int val = 0;

void setup() {
  // put your setup code here, to run once:
    pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    val = analogRead(A0); // 가변저항기 값
    digitalWrite(ledPin, HIGH);
    delay(val);
    digitalWrite(ledPin, LOW);
    delay(val);
}

int ledPin = 7;
int sensorVal = 0;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    sensorVal = analogRead(A0);
    Serial.println(sensorVal);
    if(sensorval > 700)
    {
      digitalWrite(ledPin, LOW);
    }
    digitalWrite(ledPin, HIGH);
    delay(500);
}

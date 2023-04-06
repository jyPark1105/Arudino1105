int ledPin = 13;
int buttonPin = 4;
int buttonState = 0;

void setup() {
    pinMode(ledPin, OUTPUT); // 
    pinMode(buttonPin, INPUT); // buttonPin은 내가 입력하는 값 
}

void loop() {
    buttonState = digitalRead(buttonPin); // buttonPin을 누르기 전 상태 0 -> LOW, 누른 후 상태 1 -> HIGH.
    if(buttonState == HIGH)
    {
        digitalWrite(ledPin, HIGH);
    } 
    else if(buttonState == LOW)
    {
        digitalWrite(ledPin, LOW);
    }
}
int tonePin = 6; // PWM pin

void setup() {
    pinMode(tonePin, OUTPUT);
}

void loop() {
    tone(tonePin, 500);
    delay(500);
    noTone(tonePin);
    delay(500);
}
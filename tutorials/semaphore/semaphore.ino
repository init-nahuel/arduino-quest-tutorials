int redPin = 7, yellowPin = 6, greenPin = 5;
int waitTime = 5000, trnsTime = 2000, passTime = 5000;
int buttonPin = 9;
int increaseTime = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  semaphore(redPin, waitTime);
  semaphore(yellowPin, trnsTime);
  semaphore(greenPin, passTime);
}

void semaphore(int pin, int t) {
  unsigned long stampedTime = millis();
  digitalWrite(pin, HIGH);
  while (millis() - stampedTime < t) {
    int addTime = detectPress(buttonPin);
    if (addTime) {
      stampedTime += increaseTime;
    }
  }
  digitalWrite(pin, LOW);
}

int detectPress(int pin) {
  int isPressed = digitalRead(pin);
  if (isPressed) {
    return 1;
  } else {
    return 0;
  }
}

int triggerPin = 7, echoPin = 5;
int echoTime, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);

    distance = 0.034*echoTime/2;
    Serial.print("Distance ");
    Serial.println(distance);  
}

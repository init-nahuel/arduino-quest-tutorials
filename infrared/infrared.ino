 int detectorPin = 7, detectorValue; 
 void setup() {
  // put your setup code here, to run once:
  pinMode(detectorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  detectorValue = digitalRead(detectorPin);

  if (detectorValue == HIGH) {
    Serial.println("Detectado movimiento");
  } else {
    Serial.println("No se ha detectado movimiento");
  }
}

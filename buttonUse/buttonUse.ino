int buttonPin = 7;
int isPressed = 0;

void setup() {
  // Queremos leer senales que lleguen al pin 7 por tanto ocupamos el modo INPUT
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  isPressed = digitalRead(buttonPin);

  // Preguntamos si se presiona el boton  
  if (isPressed == 1) {
    Serial.println("Pulsado");
  }

  // Se ocupa delay() solo para que al presionarlo no se muestre en la pantalla
  // el texto "Pulsado" tan rapido al momento de apretar el boton
  delay(100);
}
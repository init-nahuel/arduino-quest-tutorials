#include <LiquidCrystal.h>

int rsPin = 12, enablePin = 11;
int d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Data pins

LiquidCrystal lcd(rsPin, enablePin, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hola!");
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Hola!");
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
}

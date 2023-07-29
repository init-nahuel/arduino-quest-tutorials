#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int address = 0x27;
LiquidCrystal_I2C lcd(address, 16, 2);
int pinPlayer = 6, playerPosition = 0;
int movePlayer = 0;
unsigned long prevTime = millis();
int shootingDelay = 300;

void setup() {
  lcd.init();
  Wire.begin();
  lcd.backlight();
  pinMode(pinPlayer, INPUT);
  lcd.setCursor(1, 0);
  lcd.print("#");
  Serial.begin(9600);
}

void loop() {
//  movePlayer = digitalRead(pinPlayer);
//  if (movePlayer) {
//    playerPosition = move(playerPosition, lcd);
//    Serial.println(movePlayer);
//  }

//    unsigned long currentTime = millis();
//    if (currentTime - prevTime >= shootingDelay) {
//      shooting(lcd);
//    }
//    shooting(lcd);
  lcd.setCursor(17, 0);
  lcd.print("-");
  delay(500);
  lcd.print(" ");
  lcd.setCursor(16, 0);
  lcd.print("-");
  delay(500);
  lcd.print(" ");
  lcd.setCursor(15, 0);
  lcd.print("-");
  delay(500);
  lcd.print(" ");
}

int move(int pos, LiquidCrystal_I2C lcd) {
  lcd.setCursor(0, pos);
  lcd.print(" ");
  
  if (pos) {
    lcd.setCursor(0, 0);
    lcd.print("#");
    
    return 0;
  }
  
  lcd.setCursor(0, 1);
  lcd.print("#");

  return 1;
}

void shooting(LiquidCrystal_I2C lcd) {
  int bulletPos = random(0, 2); // Escoge una posicion para la bala c/r al lcd, 0 o 1
  for (int i=17; i>=0; i--) {
    if (i!=17) {
      lcd.setCursor(i+1, bulletPos);
      lcd.print(" ");
    }
    lcd.setCursor(i, bulletPos);
    lcd.print("-");
    delay(800);
  }
}
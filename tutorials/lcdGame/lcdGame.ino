#include <LiquidCrystal_I2C.h>

int address = 0x27;
LiquidCrystal_I2C lcd(address, 16, 2);
int pinPlayer = 6, playerPosition = 0;
int movePlayer = 0;
unsigned long prevTime = millis();
int shootingDelay = 800;

int move(int pos, LiquidCrystal_I2C lcd);
void shooting(LiquidCrystal_I2C lcd, int playerPosition);

void setup() {
  pinMode(pinPlayer, INPUT);
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
}

void loop() {

  movePlayer = digitalRead(pinPlayer);
  if (movePlayer) {
    playerPosition = move(playerPosition, lcd);
  }

  unsigned long currentTime = millis();
  if (currentTime - prevTime >= shootingDelay) {
    shooting(lcd, playerPosition);
  }
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

void shooting(LiquidCrystal_I2C lcd, int playerPosition) {
  int bulletPos = random(0, 2); // Escoge una posicion para la bala c/r al lcd, 0 o 1
  for (int i=17; i>=0; i--) {
    if (i == 0 && bulletPos == playerPosition) {
      Serial.println("MORISTEE!");
    }
    if (i != 17) {
      lcd.print(" ");
    }
    lcd.setCursor(i, bulletPos);
    lcd.print("-");
    delay(800);
    lcd.setCursor(i, bulletPos);
  }
  lcd.print(" ");
}
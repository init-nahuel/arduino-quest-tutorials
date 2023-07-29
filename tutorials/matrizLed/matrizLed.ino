#include <MD_MAX72xx.h>

int clkPin = 7, csPin = 6, dinPin = 5;
MD_MAX72XX matrizLed = MD_MAX72XX(MD_MAX72XX::DR0CR1RR0_HW, dinPin, clkPin, csPin, 1);

const byte IMAGES[][8] = {
{
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
},{
  0b00000000,
  0b00011000,
  0b00101000,
  0b00011000,
  0b00000000,
  0b00011000,
  0b00010100,
  0b00011000
}};
const int IMAGES_LEN = sizeof(IMAGES)/8;

void setup() {
  matrizLed.begin();
}

void loop() {
  matrizLed.setPoint(2, 0, HIGH);
  delay(1000);
  matrizLed.clear();
  delay(1000);
  matrizLed.setColumn(2, 0b11111111);
  delay(1000);
  matrizLed.setColumn(2, 0b10101010);
  delay(1000);
  matrizLed.clear();
  drawImage(IMAGES, IMAGES_LEN);
  delay(1000);
}

void drawImage(byte image[][8], int rows) {
  for (int i=0; i<rows; i++) {
    for (int j=0; j<8; j++) {
      matrizLed.setRow(j, image[i][j]);
    }
    delay(500);
  }
}
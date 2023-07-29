#include <Servo.h>

Servo servoMotor;
int servoPin = 6; // PWM

void setup() {
  // put your setup code here, to run once:
  servoMotor.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  servoMotor.write(180);
  servoMotor.write(0);
}

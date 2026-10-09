#include <Servo.h>


Servo meuServo;

void setup()
{
  Serial.begin(9600);
  meuServo.attach(9);
}

void loop()
{
  int pot = analogRead(A0);
  int angulo = map(pot, 0, 1023, 0, 360);
  meuServo.write(angulo);
  delay(150);
}

#include <Servo.h>


Servo meuServo;

void setup()
{
  Serial.begin(9600);
  meuServo.attach(9);
}


void loop()
{
  meuServo.write(0);
  delay(1000)
  meuServo.write(90);
  delay(1000)
  meuServo.write(180);
  delay(1000)
}

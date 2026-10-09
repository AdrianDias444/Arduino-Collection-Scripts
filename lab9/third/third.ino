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
  for(int i = 0; i < 180; i++)
  {
    meuServo.write(i);
    delay(10);
  }
  for(int i = 180; i > 0; i--)
  {
    meuServo.write(i);
    delay(10);
  }
}


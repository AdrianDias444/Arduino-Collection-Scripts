include <Stepper.h>


const int passosPorVolta = 2048;
Stepper meuMotor(passosPorVolta, 8, 10, 9, 11);

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  meuMotor.setSpeed(15);
  meuMotor.step(1024);
  delay(1000);
  meuMotor.step(-1024);
  delay(1000);
}

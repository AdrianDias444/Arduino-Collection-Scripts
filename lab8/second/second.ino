#include <Stepper.h>
const int passosPorVolta = 2048;
Stepper meuMotor( passosPorVolta , 8 , 10 , 9 , 11);

void setup () {
  Serial.begin(9600);
}


void loop () {
  int potenciometro = analogRead(A0);
  int velocidade = map(potenciometro, 0, 1023, 0, 15);
  Serial.println(velocidade);
  meuMotor.setSpeed(velocidade);
  if(velocidade > 1)
    meuMotor.step(10);
}

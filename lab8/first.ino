# include < Stepper .h >
const int passosPorVolta = 2048;
Stepper meuMotor(passosPorVolta , 8 , 10 , 9 , 11) ;

void setup () {
  Serial.begin(9600) ;
}

void loop () {
  int velocidade = 15;
  meuMotor.setSpeed(velocidade);
  meuMotor.step(10) ;
}

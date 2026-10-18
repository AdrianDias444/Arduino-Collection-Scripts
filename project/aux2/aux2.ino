#include "header.hpp"
#include "Tone.h"


aux_arduino aux;

void setup_passos_inicial(aux_arduino& aux)
{
    aux.passo1.buzzer1 = 0;
    aux.passo1.buzzer2 = 0;
    aux.passo1.delay = 100;
    
    aux.passo2.buzzer1 = 0;
    aux.passo2.buzzer2 = 0;
    aux.passo2.delay = 100;


    aux.passo3.buzzer1 = 0;
    aux.passo3.buzzer2 = 0;
    aux.passo3.delay = 100;


    aux.passo4.buzzer1 = 0;
    aux.passo4.buzzer2 = 0;
    aux.passo4.delay = 100;


    aux.passo5.buzzer1 = 0;
    aux.passo5.buzzer2 = 0;
    aux.passo5.delay = 100;
}





int pot_value(int analog_pin)
{
    int poten = analogRead(analog_pin);
    int value = map(poten, 0, 1023, 0, 8);

    return(value);
}


Tone buzzer1;
Tone buzzer2;

void setup()
{
    // botoes
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    

    // 2 buzzers em paralelo
    buzzer1.begin(10);
    buzzer2.begin(11);

    // Receber sinal da main
    pinMode(12, INPUT);

    setup_passos_inicial(aux);
    Serial.begin(115200);
}


int converter_notas(int value)
{
    if(value == 0)
        return(0);
    if(value == 1)
        return(DO);
    if(value == 2)
        return(RE);
    if(value == 3)
        return(MI);
    if(value == 4)
        return(FA);
    if(value == 5)
        return(SOL);
    if(value == 6)
        return(LA);
    if(value == 7)
        return(SI);
    if(value == 8)
        return(DO2);
    return(0);
}


void gerenciar_definicoes_aux(aux_arduino& aux)
{
    while(digitalRead(2) == HIGH)
    {
        aux.passo1.delay = map(analogRead(A5), 0, 1023, 100, 500);
        aux.passo1.buzzer1 = converter_notas(pot_value(A0));
        aux.passo1.buzzer2 = converter_notas(pot_value(A1));
    }
    while(digitalRead(3) == HIGH)
    {
        aux.passo2.delay = map(analogRead(A5), 0, 1023, 100, 500);
        aux.passo2.buzzer1 = converter_notas(pot_value(A0));
        aux.passo2.buzzer2 = converter_notas(pot_value(A1));
    }
    while(digitalRead(4) == HIGH)
    {
        aux.passo3.delay = map(analogRead(A5), 0, 1023, 100, 500);
        aux.passo3.buzzer1 = converter_notas(pot_value(A0));
        aux.passo3.buzzer2 = converter_notas(pot_value(A1));
    }
    while(digitalRead(5) == HIGH)
    {
        aux.passo4.delay = map(analogRead(A5), 0, 1023, 100, 500);
        aux.passo4.buzzer1 = converter_notas(pot_value(A0));
        aux.passo4.buzzer2 = converter_notas(pot_value(A1));
    }
    while(digitalRead(6) == HIGH)
    {
        aux.passo5.delay = map(analogRead(A5), 0, 1023, 100, 500);
        aux.passo5.buzzer1 = converter_notas(pot_value(A0));
        aux.passo5.buzzer2 = converter_notas(pot_value(A1));
    }
}

void play_passo(passo_aux passo)
{
    if(passo.buzzer1 != 0){
        buzzer1.play(passo.buzzer1, passo.delay);

    }
    if(passo.buzzer2 !=0){
        buzzer2.play(passo.buzzer2, passo.delay);
    }
}


void loop()
{
    gerenciar_definicoes_aux(aux);
    Serial.println("Inicio de ciclo");
    while(digitalRead(12) != HIGH){
    }
    play_passo(aux.passo1);
    delay(aux.passo1.delay);

    while(digitalRead(12) != HIGH){
    }
    play_passo(aux.passo2);
    delay(aux.passo2.delay);
    
    while(digitalRead(12) != HIGH){
    }
    play_passo(aux.passo3);
    delay(aux.passo3.delay);
    
    while(digitalRead(12) != HIGH){
    }

    play_passo(aux.passo4);
    delay(aux.passo4.delay);
    
    while(digitalRead(12) != HIGH){
    }
    play_passo(aux.passo5);
    delay(aux.passo5.delay);
}
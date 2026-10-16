#include "header.hpp"
#include "Tone.h"


aux_arduino aux;

void setup_passos_inicial(aux_arduino& aux)
{
    aux.passo1.buzzer1 = 0;
    aux.passo1.buzzer2 = 0;
    
    aux.passo2.buzzer1 = 0;
    aux.passo2.buzzer2 = 0;

    aux.passo3.buzzer1 = 0;
    aux.passo3.buzzer2 = 0;
    
    aux.passo4.buzzer1 = 0;
    aux.passo4.buzzer2 = 0;

    aux.passo5.buzzer1 = 0;
    aux.passo5.buzzer2 = 0;

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
    // 5 leds
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);


    // botoes
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    
    // Receber sinal da main
    pinMode(11, INPUT);

    // 2 buzzers em paralelo
    buzzer1.begin(12);
    buzzer2.begin(13);


    setup_passos_inicial(aux);
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
    while(digitalRead(5) == HIGH)
    {
        aux.passo1.delay = map(analogRead(A5), 0, 1023, 100, 500);
        aux.passo1.buzzer1 = converter_notas(pot_value(A1));
        aux.passo1.buzzer2 = converter_notas(pot_value(A2));
    }
    while(digitalRead(6) == HIGH)
    {
        aux.passo2.delay = map(analogRead(A5), 0, 1023, 100, 500);
        aux.passo2.buzzer1 = converter_notas(pot_value(A1));
        aux.passo2.buzzer2 = converter_notas(pot_value(A2));
    }
    while(digitalRead(7) == HIGH)
    {
        aux.passo3.delay = map(analogRead(A5), 0, 1023, 100, 500);
        aux.passo3.buzzer1 = converter_notas(pot_value(A1));
        aux.passo3.buzzer2 = converter_notas(pot_value(A2));
    }
    while(digitalRead(8) == HIGH)
    {
        aux.passo4.delay = map(analogRead(A5), 0, 1023, 100, 500);
        aux.passo4.buzzer1 = converter_notas(pot_value(A1));
        aux.passo4.buzzer2 = converter_notas(pot_value(A2));
    }
    while(digitalRead(9) == HIGH)
    {
        aux.passo5.delay = map(analogRead(A5), 0, 1023, 100, 500);
        aux.passo5.buzzer1 = converter_notas(pot_value(A1));
        aux.passo5.buzzer2 = converter_notas(pot_value(A2));
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
    if(digitalRead(11) == HIGH)
    {
        play_passo(aux.passo1);
        delay(aux.passo1.delay);
    }

    while(digitalRead(11) == LOW){pass;}
    
    if(digitalRead(11) == HIGH)
    {
        play_passo(aux.passo2);
        delay(aux.passo2.delay);
    }
    
    while(digitalRead(11) == LOW){pass;}
    
    if(digitalRead(11) == HIGH)
    {
        play_passo(aux.passo3);
        delay(aux.passo3.delay);
    }
    
    while(digitalRead(11) == LOW){pass;}

    if(digitalRead(11) == HIGH)
    {
        play_passo(aux.passo4);
        delay(aux.passo4.delay);
    }
    
    while(digitalRead(11) == LOW){pass;}
    
    if(digitalRead(11) == HIGH)
    {
        play_passo(aux.passo5);
        delay(aux.passo5.delay);
    }
}
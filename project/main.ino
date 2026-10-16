#include "header.hpp"
#include "Tone.h"


master_arduino  master;
void setup_passos_inicial(master_arduino& master)
{
    master.passo1.buzzer = 0;
    master.passo2.buzzer = 0;
    master.passo3.buzzer = 0;
    master.passo4.buzzer = 0;
    master.passo5.buzzer = 0;
}




int pot_value(int analog_pin)
{
    int poten = analogRead(analog_pin);
    int value = map(poten, 0, 1023, 0, 8);

    return(value);
}

void setup()
{
    // botoes
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);


    // buzzer
    pinMode(7, OUTPUT);

    // Ativar AUX1
    pinMode(12, OUTPUT);
    // Ativar AUX2
    pinMode(13, OUTPUT);

    setup_passos_inicial(master);
    
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

void gerenciar_definicoes()
{
    while(digitalRead(2) == HIGH)
    {
        master.passo1.delay = map(analogRead(A5), 0, 1023, 100, 500);
        master.passo1.buzzer = converter_notas(pot_value(A1));
    }
    while(digitalRead(3) == HIGH)
    {
        master.passo2.delay = map(analogRead(A5), 0, 1023, 100, 500);
        master.passo2.buzzer = converter_notas(pot_value(A1));
    }
    while(digitalRead(4) == HIGH)
    {
        master.passo3.delay = map(analogRead(A5), 0, 1023, 100, 500);
        master.passo3.buzzer = converter_notas(pot_value(A1));
    }
    while(digitalRead(5) == HIGH)
    {
        master.passo4.delay = map(analogRead(A5), 0, 1023, 100, 500);
        master.passo4.buzzer = converter_notas(pot_value(A1));
    }
    while(digitalRead(6) == HIGH)
    {
        master.passo5.delay = map(analogRead(A5), 0, 1023, 100, 500);
        master.passo5.buzzer = converter_notas(pot_value(A1));
    }

}

void play_passo(passo_master passo)
{
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    delay(5);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    if(passo.buzzer != 0){
        tone(7, passo.buzzer, passo.delay);
    }
    delay(passo.delay - 22);
}



void loop()
{
    gerenciar_definicoes();
    play_passo(master.passo1);
    play_passo(master.passo2);
    play_passo(master.passo3);
    play_passo(master.passo4);
    play_passo(master.passo5);

}

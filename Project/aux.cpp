#include "header.h"

int poten_value(int analog_pin)
{
    int poten = analogRead(analog_pin);
    int value = map(poten, 0, 1023, 0, 7);

    return(value);
}

void buzer_bell(int som, int buzzer_pin, int delay)
{
    tone(buzzer_pin, som, delay);
}

void buzzer_action(int poten_value, int buzzer_pin, int delay)
{
    if(som == 0)
        buzer_bell(DO, buzer_pin, delay);
    if(som == 1)
        buzer_bell(RE, buzer_pin, delay);
    if(som == 2)
        buzer_bell(MI, buzer_pin, delay);
    if(som == 3)
        buzer_bell(FA, buzer_pin, delay);
    if(som == 4)
        buzer_bell(SOL, buzer_pin, delay);
    if(som == 5)
        buzer_bell(LA, buzer_pin, delay);
    if(som == 6)
        buzer_bell(SI, buzer_pin, delay);
    if(som == 7)
        buzer_bell(DO2, buzer_pin, delay);
}



void all_buzzer_on(int input)
{
    int pot_0;
    int pot_1;
    int pot_2;
    int pot_3;
    int pot_4;
    int delay;

    pot_0 = poten_value(A0);
    delay = poten_value(A5);
    buzzer_action(pot_0, 3, delay);

    pot_1 = poten_value(A1);
    delay = poten_value(A5);
    buzzer_action(pot_1, 4, delay);

    pot_2 = poten_value(A2)
    delay = poten_value(A5);
    buzzer_action(pot_2, 5, delay);

    pot_3 = poten_value(A3);
    delay = poten_value(A5);
    buzzer_action(pot_3, 6, delay);

    int pot_4 = poten_value(A4);
    delay = poten_value(A5);
    buzzer_action(pot_4, 7, delay);
}

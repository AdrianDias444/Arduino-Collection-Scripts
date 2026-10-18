#ifndef HEADER_HPP
#define HEADER_HPP

#define DO  262
#define RE  294
#define MI  330
#define FA  349
#define SOL 392
#define LA  440
#define SI  494
#define DO2 523

#include <Arduino.h>

struct passo_master
{
    int buzzer;
    int delay;
};


struct master_arduino
{
    int             tempo;
    passo_master     passo1;
    passo_master     passo2;
    passo_master     passo3;
    passo_master     passo4;
    passo_master     passo5;
};



//------------------>

struct passo_aux
{
    int buzzer1;
    int buzzer2;
    int delay;
};


struct aux_arduino
{
    int         tempo;
    passo_aux  passo1;
    passo_aux  passo2;
    passo_aux  passo3;
    passo_aux  passo4;
    passo_aux  passo5;
};



#endif
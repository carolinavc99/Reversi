#ifndef PROJ_STACK_H
#define PROJ_STACK_H
#include "estado.h"

struct JOGADA {
    ESTADO tabuleiro;
    struct JOGADA* prox;
};

//struct JOGADA* topo;

void push(ESTADO e);
void pop();
void resetJogadas(); // faz o reset da lista das jogadas feitas

#endif //PROJ_STACK_H

#ifndef PROJ_STACK_H
#define PROJ_STACK_H
#include "estado.h"

struct JOGADA {
    ESTADO tabuleiro;
    struct JOGADA* prox;
};

//struct JOGADA* topo;

struct JOGADA* push(ESTADO e, struct JOGADA* topo); // devolve o novo pointer topo
struct JOGADA* pop(struct JOGADA* topo); // devolve o novo pointer topo
struct JOGADA* resetJogadas(struct JOGADA* topo, int* jogadas_efetuadas); // faz o reset da lista das jogadas feitas

#endif //PROJ_STACK_H

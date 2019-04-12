#include <stdlib.h>
#include "stack.h"

// novajogada
void push(ESTADO e) {
    struct JOGADA* temp;

    temp = (struct JOGADA*) malloc (sizeof(struct JOGADA));

    if (!temp) {
        printf("Stack sobrelotada.\n");
        exit(1);
    }

    temp->tabuleiro = e;
    temp->prox = topo;
    topo = temp;
}

/*
   undo
   Não esquecer que esta função funciona em stack, logo a última jogada é a que está no INÍCIO,
      para onde o topo está a apontar.
*/
void pop() {
    struct JOGADA* temp;
    temp = topo;
    topo = topo->prox;
    free(temp);
}


// fucking bullshit-ass CODE!!!! GOD-DAMMIT piece of shit FUNCTION im TIRED and i want to SLEEP not do THIS SHIT fucking HELL!!1!!!

// faz reset das jogadas
void resetJogadas (ESTADO e) {
    struct JOGADA* temp;

    while (topo) {
        temp = topo;
        topo = topo->prox;
        free(temp);
    }
}

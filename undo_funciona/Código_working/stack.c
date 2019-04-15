#include <stdlib.h>
#include "stack.h"

// novajogada
void push(ESTADO e) {
    struct JOGADA* temp;

    temp = (struct JOGADA*) malloc (sizeof(struct JOGADA));

    if (!temp) {
        printf("\nStack sobrelotada.\n");
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


// faz reset das jogadas
void resetJogadas() {
    struct JOGADA* temp;

    while (topo) {
        temp = topo;
        topo = topo->prox;
        free(temp);
    }

}

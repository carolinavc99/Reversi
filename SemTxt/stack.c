#include <stdlib.h>
#include "stack.h"

// novajogada
struct JOGADA* push(ESTADO e, struct JOGADA* topo) {
    struct JOGADA* temp;

    temp = (struct JOGADA*) malloc (sizeof(struct JOGADA));

    if (!temp) {
        printf("\nStack sobrelotada.\n");
        exit(1);
    }

    temp->tabuleiro = e;
    temp->prox = topo;
    topo = temp;

    return topo;
}

/*
   undo
   Não esquecer que esta função funciona em stack, logo a última jogada é a que está no INÍCIO,
      para onde o topo está a apontar.
*/
struct JOGADA* pop(struct JOGADA* topo) {
    struct JOGADA* temp;

    temp = topo;
    topo = topo->prox;
    free(temp);

    return topo;

}


// faz reset das jogadas
struct JOGADA* resetJogadas(struct JOGADA* topo, int* jogadas_efetuadas) {
    struct JOGADA* temp;

    while (topo) {
        temp = topo;
        topo = topo->prox;
        free(temp);
    }

    *jogadas_efetuadas = 0;
    return topo;
}

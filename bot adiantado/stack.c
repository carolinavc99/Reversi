#include <stdlib.h>
#include "stack.h"

/**
 * Acrescenta uma jogada ao topo da stack.
 * @param e Estado atual.
 * @param topo Jogada a acrescentar à stack.
 * @return Jogada que foi acrescentada à stack.
 */
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

/**
 * Retira uma jogada do topo da stack.
 * @param topo Jogada a ser retirada da stack.
 * @return Jogada que fica no topo da stack após a remoção da jogada dada.
 */
struct JOGADA* pop(struct JOGADA* topo) {
    struct JOGADA* temp;

    temp = topo;
    topo = topo->prox;
    free(temp);

    return topo;

}

// faz reset das jogadas
/**
 * Esvazia a stack.
 * @param topo Jogada que se encontra no topo da stack.
 * @param jogadas_efetuadas Número de jogadas já efetuadas.
 * @return Jogada que se encontra no topo da stack.
 */
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

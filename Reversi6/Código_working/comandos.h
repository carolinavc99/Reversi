#ifndef PROJ_COMANDOS_H
#define PROJ_COMANDOS_H

#endif //PROJ_COMANDOS_H

#include "estado.h"

ESTADO novoJogo (VALOR peca);

ESTADO jogar (ESTADO e, int linha, int coluna);

ESTADO calcJogadasValidas (ESTADO e);

void posicoesValidas (ESTADO e, ESTADO v);

int validarJogada (ESTADO e, int linha, int coluna);

void guardar (ESTADO e, char input[]);

ESTADO undo (ESTADO e);

////////////////////////////////////////////////////////
typedef struct celula {
    int numero;             // 1ª,2ª,3ª,etc jogada
    struct celula *prox;    // próxima jogada qe foi executada
} *JOGADA;

JOGADA novaJogada (); // função que incrementa a lista de jogadas já feitas
////////////////////////////////////////////////////////







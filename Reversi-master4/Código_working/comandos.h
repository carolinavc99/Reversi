#ifndef PROJ_COMANDOS_H
#define PROJ_COMANDOS_H

#endif //PROJ_COMANDOS_H

#include "estado.h"

ESTADO novoJogo (ESTADO e, VALOR peca);

ESTADO jogar (ESTADO e, int linha, int coluna);

ESTADO calcJogadasValidas (ESTADO e);

void posicoesValidas (ESTADO e, ESTADO v);

int validarJogada (ESTADO e, int linha, int coluna);








#include "estado.h"
#include "stack.h"
#ifndef PROJ_COMANDOS_H
#define PROJ_COMANDOS_H

ESTADO novoJogo (VALOR peca);

ESTADO jogar (ESTADO e, int linha, int coluna);

ESTADO calcJogadasValidas (ESTADO e);

void posicoesValidas (ESTADO e, ESTADO v);

int validarJogada (ESTADO e, int linha, int coluna);

void guardar (ESTADO e, char input[]); // devolve um apontador para a lista de jogadas

struct JOGADA* undo (ESTADO* e, struct JOGADA* topo);

ESTADO continuaJogo (ESTADO e, char input []);

struct JOGADA* novaJogada (ESTADO e, int linha, int coluna, struct JOGADA* topo); // função que incrementa a stack de jogadas já feitas

int passaJogada (ESTADO e, VALOR p);

int arrayValidas (ESTADO e, PONTO validas[]);

void sugestao(ESTADO e);

#endif //PROJ_COMANDOS_H



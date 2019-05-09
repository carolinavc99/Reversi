#include <stdio.h>

#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H




/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/


// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O, VALOR_V, VALOR_S} VALOR;

/**
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca;          // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char modo;           // modo em que se está a jogar! 0-> manual, 1-> contra computador
    char nome[30];       // nome do ficheiro de jogo (INCLUI '.txt') -- é '.' se ainda não tiver sido guardado
    int score[2];
} ESTADO;

// >>>> ACRESCENTEI STRUCT <<<<
/**
 * Estrutura que armazenas as coordenadas de um ponto
 */
typedef struct ponto {
    int l; //linha
    int c; //coluna
} PONTO;


void printa(ESTADO);

ESTADO score (ESTADO e);

VALOR chrtovalor(char c);

int min(int a, int b);
int max(int a, int b);

#endif //PROJ_ESTADO_H


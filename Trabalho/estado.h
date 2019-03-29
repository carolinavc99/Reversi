
#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H

/*
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/


// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O} VALOR;

//Estrutura que armazena o estado do jogo
typedef struct estado {
    VALOR peca;     // peça do jogador que vai jogar
    VALOR grelha[8][8];
    char modo;      // modo em que se está a jogar M-> manual, A-> contra computador
} ESTADO;


void destado(ESTADO);
char dmenu();


#endif //PROJ_ESTADO_H
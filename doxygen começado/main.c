#include <stdio.h>
#include "estado.h"
#include <string.h>
#include "menu.h"


int main() {

    ESTADO e = {0}; // tabuleiro vazio

    struct JOGADA* stackUndo;

    e.modo = ' ';
    e.peca = VAZIA;
    e.score [0] = 2;
    e.score [1] = 2;
    strcpy(e.nome, ".");


    // estado inicial do tabuleiro. Inicio do jogo!
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    menu(e,stackUndo);

    return 0;
}
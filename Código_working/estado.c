#include <stdio.h>
#include "estado.h"


// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e) {

    char c = ' ';

    if(e.peca == VALOR_X) printf("\nJogador: X | ");
    else {
        if (e.peca == VALOR_O) printf("\nJogador: O | ");
        else printf("\nJogador:  | ");
    }

    if(e.modo == '0') printf("Modo: Manual\n\n");
    else {
        if (e.modo == '1') printf("Modo: Contra o computador:\n\n");
        else printf("Modo:  \n\n");
    }



    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
            }
            printf("%c ", c);

        }
        printf("\n");
    }

}


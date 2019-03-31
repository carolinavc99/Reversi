#include <stdio.h>
#include "estado.h"


ESTADO novo_jogo(ESTADO e, VALOR v) {

    e.grelha[3][4] = VALOR_O;
    e.grelha[4][3] = VALOR_O;
    e.grelha[3][3] = VALOR_X;
    e.grelha[4][4] = VALOR_X;
    e.peca = v;

    return e;
}

//e.grelha[2][2] = VALOR_X;


// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e)
{
    char c = ' ';

    printf ("\n  1 2 3 4 5 6 7 8\n");

    for (int i = 0; i < 8; i++) {
        printf ("%d ",i+1);
        for (int j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'X';
                    break;
                }
                case VALOR_X: {
                    c = 'O';
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
    printf("\n");
}


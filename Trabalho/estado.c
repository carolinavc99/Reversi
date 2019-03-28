
#include <stdio.h>
#include "estado.h"


// display do estado
void destado(ESTADO e) {
    char c = ' ';

    printf("\n  ### Reversi ###\n");
    printf("\n  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        printf ("%d ", i+1);
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
    printf("\n");
}



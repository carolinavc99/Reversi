#include <stdio.h>
#include "estado.h"


//interpreta VALOR
VALOR chrtovalor(char c){
    if (c == 'X')
        return VALOR_X;
    else if (c == 'O')
        return VALOR_O;
    else
        return VAZIA;
}



// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e) {

    char c = ' ';
    int k = 1;
    char m, j;

    //Atualiza o score.
    e = score(e);

    if(e.peca == VALOR_X) j = 'X'; //printf("\nJogador: X | ");
    else {
        if (e.peca == VALOR_O) j = 'O';//printf("\nJogador: O | ");
        else j = ' '; //printf("\nJogador:  | ");
    }

    printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * *\n"
           "*                                                 *\n");

    if(e.modo == '0')
        printf("* Modo: Manual                                    *\n");
    else {
        if (e.modo == '1') printf("\nModo: Contra o computador:\n");
        else printf("Modo:  \n");
    }

    printf( "*                                                 *\n"
            "*    1 2 3 4 5 6 7 8                              *\n");




    for (int i = 0; i < 8; i++) {

        printf("*  %d ",k);

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
                case VALOR_V: {
                    c = '.';
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }

            }
            printf("%c ", c);

        }

        if(k==3) printf(    "         Jogador: %c          *\n", j);
        else {
            if(k==5) printf("        X: %d  |  O: %d        *\n", e.score[0], e.score[1]);


            else printf("                             *\n");
        }

        k ++;
    }

    printf(  "*                                                 *"
             "\n* * * * * * * * * * * * * * * * * * * * * * * * * *\n");

}

/*
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

    printf("Score:\n");
    printf("X: %d | O: %d\n\n", e.score[0], e.score[1]);

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
                case VALOR_V: {
                    c = '.';
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
*/

/*
 * Calcula o score de cada um dos jogadores.
 */

ESTADO score (ESTADO e) {

    int o, x;

    o=0;
    x=0;

    for(int linha = 0; linha < 8; linha++) {

        for (int coluna = 0; coluna < 8; coluna++) {

            if(e.grelha[linha][coluna] == VALOR_X) x++;

            else {

                if (e.grelha[linha][coluna] == VALOR_O) o++;

            }

        }

    }

    e.score[0] = x;
    e.score[1] = o;

    return(e);

}






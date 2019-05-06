#include <stdio.h>
#include "estado.h"

// VERIFICAR SE A FUNÇÃO É UTILIZADA.
VALOR chrtovalor(char c){
    if (c == 'X')
        return VALOR_X;
    else if (c == 'O')
        return VALOR_O;
    else
        return VAZIA;
}

/**
 * Imprime o score de cada jogador.
 * @param x Score do jogador com a peça X.
 * @param o Score do jogador com a peça O.
 */
void printaScore (int x, int o) {

    if (x<10 && o<10)        printf("        X: %d  |  O: %d        *\n", x, o);
    else {
        if (x>9 && o>9)      printf("        X: %d |  O: %d       *\n", x, o);
        else {
            if (x<10 && o>9) printf("        X: %d  |  O: %d       *\n", x, o);
            else             printf("        X: %d |  O: %d        *\n", x, o);
        }
    }

}

/**
 * Imprime um estado.
 * @param e Estado a ser impresso.
 */
void printa(ESTADO e) {             // exemplo de uma função para imprimir o estado (Tabuleiro)
    char c = ' ';
    int k = 1;
    char j;

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
            if(k==5) printaScore(e.score[0], e.score[1]);


            else printf("                             *\n");
        }

        k ++;
    }

    printf(  "*                                                 *"
             "\n* * * * * * * * * * * * * * * * * * * * * * * * * *\n");

}

/**
 * Calcula o score de cada um dos jogadores.
 * @param e Estado atual.
 * @return Estado com o score atualizado.
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






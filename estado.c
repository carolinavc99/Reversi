
#include <stdio.h>
#include "estado.h"


// display do estado
void destado(ESTADO e) {
    char c = ' ';

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

// display do menu
char dmenu() {   // os comentários ao lado são sobre o que é preciso fazer para cada função
    char c;

    printf("Opções:\n"
           "N - cria um novo jogo\n"        // indique a peça que começa primeiro e o nome do ficheiro
           "L - ler um jogo de ficheiro\n"  // indicar o ficheiro em que o jogo pretendido está guardado
           "E - guardar o jogo\n"           // escrever num ficheiro o estado atual do jogo
           "J - jogar\n"                    // indique a linha e a coluna da posição, não esquecer que esta função é sensível à peça que deve ser jogada
           "S - opções de jogada\n"         // imprime '.'
           "H - sugestão de jogadda\n"      // imprime '?'
           "U - desfazer a última jogada\n" // usar stacks para isto, tem de conseguir retornar até ao estado inicial do jogo
           "A - jogar contra o computador (X joga primeiro)\n" // indique a peça e o nível de dificuldade
           "Q - sair\n");

    scanf("%c", &c);

    return c;
}


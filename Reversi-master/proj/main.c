#include <stdio.h>
#include "estado.h"
#include "comandos.h"

int main() {
    ESTADO e = {0};
    char c;


    // estado inicial do tabuleiro
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    destado(e); // imprime o tabuleiro

    //menu com printfs auxiliares ao lado em comentário
    printf("Opções:\n"
           "N - cria um novo jogo\n" // indique a peça que começa primeiro
           "L - ler um jogo de ficheiro\n" // indicar o ficheiro, O QUE É QUE ISTO FAZ?
           "E - escrever em ficheiro estado do jogo\n" // WHAT THIS DO?
           "J - jogar\n" // indique a linha e a coluna da posição, não esquecer que esta função é sensível à peça que deve ser jogada
           "S - opções de jogada\n" // imprime .
           "H - sugestão de jogadda\n" // imprime ?
           "U - desfazer a última jogada\n" // usar stacks para isto, tem de conseguir retornar até ao estado inicial do jogo
           "A - jogar contra o computador (X joga primeiro)\n" // indique a peça e o nível de dificuldade
           "Q - sair\n");

    scanf("%c", &c);

    // A 'comandos' não interpreta o 'Q', a 'main' é que sim.
    while (c != 'Q') {
        comandos(c);
    }

    return 0;
}
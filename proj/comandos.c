#include <stdio.h>
#include "estado.h"

// esta função interpreta os comandos (é o antigo 'interpretador')
// nota: esta função corre indefinidamente porque a main a chama sempre que o input NÂO é 'Q'

int comandos(char c) { // no final de cada função tem de imprimir o menu

    switch (c) {

        case 'N':
            novoJogo(); // dentro do ficheiro correto, altera o tabuleiro de jogo, com o jogador correto
            dmenu();
            break;

        case 'L':
            lerJogo();
            dmenu();
            break;

        case 'E':
            guardar();
            dmenu();
            break;

        case 'J':
            jogar();
            dmenu();
            break;

        case 'S':
            opJogada();
            dmenu();
            break;

        case 'H':
            sugest();
            dmenu();
            break;

        case 'U':
            desfazer();
            dmenu();
            break;

        case 'A':
            computador();
            dmenu();
            break;

        default:
            printf("Comando inválido.");
            dmenu();
            break;
    }

}

int novoJogo() {
    char peca;

    printf("Indique quem vai jogar primeiro: [X/O]\n");
    scanf("%c", &peca);

    while (!(peca == 'X' || peca == 'x' || peca == 'O' || peca == 'o')) {
        getchar();
        printf("Jogador inválido. Por favor introduza 'X' ou 'O'\n");
        scanf("%c", &peca);
    }


    return 0;
}
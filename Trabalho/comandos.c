#include <stdio.h>
#include "comandos.h"

// esta função interpreta os comandos (é o antigo 'interpretador')
// nota: esta função corre indefinidamente porque a main a chama sempre que o input NÂO é 'Q'
int comandos(char c) {

    switch (c) {
        //variáveis de embuste
        char a;

        case 'N':
                novoJogo(); // dentro do ficheiro correto, altera o tabuleiro de jogo, com o jogador correto
            break;

        case 'L':
            break;

        case 'E':
            break;

        case 'J':
            break;

        case 's':
            break;

        case 'H':
            break;

        case 'U':
            break;

        case 'A':
            break;

        default:
            printf("Comando inválido.");
            break;
    }

}

int novoJogo() {
    char peca;

    printf("Indique quem vai jogar primeiro: [X/O]\n");
    scanf ("%c", &peca);

    while (!(peca == 'X' || peca == 'x' || peca == 'O' || peca == 'o')) {
        getchar();
        printf("Jogador inválido. Por favor introduza 'X' ou 'O'\n");
        scanf("%c", &peca);
    }

    return 0;
}
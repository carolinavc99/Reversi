#include <stdio.h>
#include "estado.h"
#include "comandos.h"
#include <stdlib.h>

int main() {
    ESTADO e = {0};
    char c;


    // estado inicial do tabuleiro
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    destado(e); // imprime o tabuleiro

    c = dmenu(); // imprime o menu e devolve o input do utilizador

    // A 'comandos' não interpreta o 'Q', a 'main' é que sim.
    while (c != 'Q') {
        comandos(c);
    }


    printf("Ação terminada.");
    return 0;
}


/*                           ##############   NOTAS   ##############
 *
 *  Neste trabalho precisamos que a 'main' seja capaz de criar novos ficheiros para cada jogo guardado.
 *  Ou seja, de cada vez que a pessoa pede Novo Jogo o programa tem de ser capaz de criar um ficheiro
 * novo, a partir do nome que o utilizador lhe der.
 *  A função 'fopen' já abre ficheiros automaticamente, por isso temos de descobrir uma maneira de
 * fornecer à 'fopen' o nome do ficheiro. (passando-lhe uma string com o nome que queremos dar ao jogo)
 *
 * */
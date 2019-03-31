#include <stdio.h>
#include <stdlib.h>
#include "estado.h"

int main() {
    ESTADO e = {0};
    char c;


    // estado inicial do tabuleiro
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    printf("\n  ### Reversi ###\n");
    destado(e); // imprime o tabuleiro (com linhas e colunas numeradas)

    c = dmenu(); // imprime o menu e devolve o input do utilizador

    // A 'comandos' não interpreta o 'Q', a 'main' é que sim.
    while (c != 'Q') {
        comandos(c);
    }

    return 0;
}


/*                           ##############   NOTAS   ##############
 *
 *  <<NOVO JOGO>>
 *  Neste trabalho precisamos que a 'main' seja capaz de criar novos ficheiros para cada jogo guardado.
 *  Ou seja, de cada vez que a pessoa pede 'Novo Jogo' o programa tem de ser capaz de criar um ficheiro
 * novo, a partir do nome que o utilizador lhe der.
 *  A função 'fopen' já abre ficheiros automaticamente, por isso passamos-lhe uma string com o nome que
 *  queremos dar àquele jogo em particular.
 *
 *  <<LER JOGO>>
 *
 *  <<GUARDAR>>
 *
 *  <<JOGAR>>
 *
 *  <<OPÇÕES DE JOGADA>>
 *
 *  <<SUGESTÕES DE JOGADA>>
 *
 *  <<DESFAZER>>
 *
 *  <<MODO AUTOMÁTICO>>
 *
 *  <<SAIR>>
 * */
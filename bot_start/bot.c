//
// Created by carolinavc on 4/21/19.
//
#include "estado.h"
#include "bot.h"
#include "comandos.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Devolve o estado com a jogada feita/escolhida pelo bot.
 * @param n Dificuldade
 * @param e Estado atual
 * @param letra Letra pertencente ao bot
 * @return Estado onde o bot já jogou
 */
ESTADO bot (int n, ESTADO e, char letra) {
    switch(n) {
        case 0:
            return e;
            break;

        case 3:
            return e;
            break;

        case 6:
            return e;
            break;

        default:
            printf("Erro com o bot.");
            return e;
    }

}



int minmax(ESTADO e, int nivel, char letra, char letra_bot, char letra_adversario) {
    int valor;

    letra_bot = toupper(letra_bot);
    letra_adversario = toupper(letra_adversario);
    letra = toupper(letra);

    // se é a raiz, ou se chegou ao final do jogo
    if ((nivel == 0) || ( (passaJogada(e, chrtovalor(letra_bot)) == 1) && (passaJogada(e, chrtovalor(letra_adversario)) == 1) ) )
        return score(e);
    if (letra == letra_bot) {
        valor = 0;
        for (each child of node)
            valor = max(valor, minmax(child, nivel - 1, letra_adversario, letra_bot, letra_adversario));
        return valor;
    }
    else /*(letra == letra_adversario)*/ {
        valor = +1000;
        for (each child of node)
            valor = min(valor, minmax(child, nivel - 1, letra_bot, letra_bot, letra_adversario));
        return valor;
    }
}
 /*
( Initial call )
minimax(raiz, nivel, letra_do_bot)

*/

// percorre os 24 nodos de jogadas possíveis

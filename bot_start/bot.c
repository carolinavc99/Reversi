//
// Created by carolinavc on 4/21/19.
//
#include "estado.h"
#include "bot.h"
#include <stdio.h>
#include <stdlib.h>

// recebe um inteiro que determina qual a dificuldade do bot
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

/*
 * Algoritmo tem de ser minmax:
 *  - minimiza a pontuação do adversário
 *  - maximiza a pontuação do bot
 *
 *  */


/*
 ESQUELETO MINMAX
*/
 int minimax(ESTADO e, int nivel, char letra) {
    if (nivel = 0 || (node is leaf))
        return score(e);
    if (we are the bot) {
        value = -infinito;
        for (each child_of_node)
            value = max(value, minimax(child, depth - 1, letra_do_não_bot));
        return value;\
    }
    else (we are NOT the bot) {
        value = +infinite;
        for (each child of node)
            value = min(value, minimax(child, depth - 1, letra_do_bot));
        return value;
    }
 }
 /*
( Initial call )
minimax(origin, depth, TRUE)

 */
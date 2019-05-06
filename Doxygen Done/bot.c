//
// Created by carolinavc on 4/21/19.
//

#include "bot.h"
#include <stdio.h>
#include <stdlib.h>

// recebe um inteiro que determina qual a dificuldade do bot
void bot (int n) {
    switch(n) {
        case 0:
            break;

        case 3:
            break;

        case 6:
            break;

        default:
            printf("Erro com o bot.");
    }

}

/*
 * Algoritmo tem de ser minmax:
 *  - minimiza a pontuação do adversário
 *  - maximiza a pontuação do bot
 *
 *  */
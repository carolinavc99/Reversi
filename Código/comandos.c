#include "comandos.h"
#include "comandos.h"
#include <stdio.h>

ESTADO novoJogo (ESTADO e) {

    int opcao = 0;

    e.modo = '0';

    while (opcao != 1 & opcao != 2) {

        printf("\nQuem começa o jogo?\n(1)X\n(2)O\n");
        scanf("%d", &opcao);

        if(opcao != 1 & opcao != 2) printf("\nOpção inválida\n");

        else {

            if (opcao == 1) e.peca = VALOR_X;
            else e.peca = VALOR_O;

        }

    }

    printa(e);

    return e;

}
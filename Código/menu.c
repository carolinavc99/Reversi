#include "menu.h"
#include "comandos.h"
#include <stdio.h>

ESTADO menu (ESTADO e) {

    int opcao = 0;

    while (opcao != 9) {

        printf("\n. . . . . . . . . . . . . . . . . . . . . . . . .\n. Selecione a opção:                            .\n.                                               .\n");
        printf(". (1)Novo jogo                                  .\n");
        printf(". (2)Continuar jogo                             .\n");
        printf(". (3)Guardar jogo                               .\n");
        printf(". (4)Jogar                                      .\n");
        printf(". (5)Jogadas válidas                            .\n");
        printf(". (6)Sugestão de jogada                         .\n");
        printf(". (7)Desfazer última jogada                     .\n");
        printf(". (8)Novo jogo contra o bot                     .\n");
        printf(". (9)Sair                                       .\n. . . . . . . . . . . . . . . . . . . . . . . . .\n");

        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                e = novoJogo(e);
                break;

            case 2:
                printa(e);
                break;

            case 9:
                printf("\nSaiu do jogo.\n");
                break;

            default:
                printf("\nOpção inválida.\n");
                break;

        }


    }

    return e;

}
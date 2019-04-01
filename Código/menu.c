#include "menu.h"
#include "comandos.h"
#include <stdio.h>
#include <ctype.h>

ESTADO menu (ESTADO e) {

    char opcao = ' ';
    char peca = ' ';

    while (toupper(opcao) != 'Q') {

        printf("\n. . . . . . . . . . . . . . . . . . . . . . . . .\n"
               ". Selecione a opção:                            .\n"
               ".                                               .\n"
               ". (N) Novo jogo                                 .\n"
               ". (L) Continuar jogo                            .\n"
               ". (E) Guardar jogo                              .\n"
               ". (J) Jogar                                     .\n"
               ". (S) Jogadas válidas                           .\n"
               ". (H) Sugestão de jogada                        .\n"
               ". (U) Desfazer última jogada                    .\n"
               ". (A) Novo jogo contra o bot                    .\n"
               ". (Q) Sair                                      .\n"
               ". . . . . . . . . . . . . . . . . . . . . . . . .\n");

        fscanf(stdin, "%c ", &opcao);

        switch (toupper(opcao)) {

            case 'N':
                fscanf(stdin, "%c", &peca);

                switch (toupper(peca)) {

                    case 'X':
                        e = novoJogo(e,VALOR_X);
                        break;

                    case 'O':
                        e = novoJogo(e,VALOR_O);
                        break;

                    default:
                        printf("Peça inválida\n");
                        break;

                }

                break;

            case 'L':
                printa(e);
                break;

            case 'Q':
                printf("\nSaiu do jogo.\n");
                break;

            default:
                printf("\nOpção inválida.\n");
                break;

        }


    }

    return e;

}




//fscanf(stdin, "%c ", inst)
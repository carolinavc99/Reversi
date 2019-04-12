#include "menu.h"
#include "comandos.h"
#include "stack.h"
#include <stdio.h>
#include <ctype.h>

ESTADO menu (ESTADO e) { // interpretador
    char opcao[1024], arg1='\0', arg2='\0';
    char input[1024];
    ESTADO v;
    int numero=0; // numero de (opcao + argumentos) inseridos

    topo = NULL;


    while (toupper(opcao[0]) != 'Q') {

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


        fgets(input, 1000, stdin); // guarda em 'input', well, o input

        numero = sscanf(input, "%s", opcao);

        opcao[0] = toupper(opcao[0]);

        // prints-teste -- eliminar
        printf("input <%s>\n", input);
        printf("opcao <%s>\n", opcao);


        switch (opcao[0]) {
            case 'N':
                sscanf(input, "%*s %c", &arg1);
                arg1 = toupper(arg1);

                if (chrtovalor(arg1) == VALOR_X || chrtovalor(arg1) == VALOR_O) {
                    e = novoJogo(chrtovalor(arg1));
                    resetJogadas(e);
                    push(e);
                }
                else
                    printf("Peça inválida\n");

                break;

            case 'L':
                sscanf(input, "%*s %s", &arg1);
                e = continuaJogo (e, arg1);
                break;

            case 'E':
                sscanf(input, "%*s %s", &arg1);
                if (e.peca == VAZIA)
                    printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                else
                    guardar(e, &arg1);
                resetJogadas(e);
                push(e);
                break;

            case 'J':
                sscanf(input, "%*s %c %c", &arg1, &arg2);
                if (!arg2)
                    printf("\nFalta de argumentos.\n");
                else { //Valida a jogada.
                    if (validarJogada(e, arg1, arg2) == 1)
                        printf("\nJogada inválida.\n");
                    else {
                        if(e.peca == VAZIA)
                            printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                        else
                            e = jogar(e, arg1, arg2);  // coloca a peça no sítio, se tal for possível
                   novaJogada(e, arg1, arg2);
                    }
                }
                 break;

            case 'A':
                 break;

            case 'S':
             if(e.peca == VAZIA)
                 printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
             else {
                 v = calcJogadasValidas(e);
                 posicoesValidas(e, v);
             }
                 break;

             case 'H':
                 if(e.peca == VAZIA)
                     printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                 // else
                 break;

             case 'U':
                 if (e.score[0] == 2 && e.score[1] == 2) { // aka se é o estado inicial
                    printf("Não há mais jogadas para retroceder.");
                 }
                 if(e.peca == VAZIA)
                     printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                 else
                     undo(e);
                 break;

             case 'Q':
                 printf("\nSaiu do jogo.\n");
                 break;

             default:
                 printf("\nOpção inválida.\n");
                 break;
            }
        }

    //  NOTA:
    //  uma vez guardado um jogo, a lista de jogadas prévias desaparece
    return e;
}

#include "menu.h"
#include "comandos.h"
#include <stdio.h>
#include <ctype.h>

ESTADO menu (ESTADO e) { // interpretador
    char opcao='\0', arg1='\0', arg2='\0';
    char input[1000];
    ESTADO v;
    int numero=0; // numero de (opcao + argumentos) inseridos

    ESTADO j[100];
    j[0] = e;


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


        fgets(input, 1000, stdin); // guarda em 'input', well, o input

        numero = sscanf(input, "%s %c %c", &opcao, &arg1, &arg2); // scan do input e retira os argumentos

        opcao = toupper(opcao);
        arg1 = toupper(arg1);
        arg2 = toupper(arg2);



        // prints-teste -- eliminar
        printf("input <%s>\n", input);
        printf("opcao <%c>\n", opcao);
        printf("argumento 1 <%c>\n", arg1);
        printf("argumento 2 <%c>\n", arg2);


        if (numero > 1) { // se a função tem pelo menos um argumento

            switch (opcao) {
                case 'N':
                    if (arg1 == 'X')
                        e = novoJogo(VALOR_X);
                    else if (arg1 == 'O')
                        e = novoJogo(VALOR_O);
                    else
                        printf("Peça inválida\n");
                    break;

                case 'L':
                    e = continuaJogo (e, input);
                    break;

                case 'E':
                    if(e.peca == VAZIA) printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                    else guardar(e, input);
                    break;

                case 'J':
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
                        novaJogada(e,*j);
                        }
                    }

                    break;

                case 'A':
                    break;

                default:
                    printf("\nOpção inválida.\n");
                    break;
            }
        }
        else { // se a função não leva argumentos
            switch(opcao) {
                case 'S':
                    if(e.peca == VAZIA) printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                    else {
                        v = calcJogadasValidas(e);
                        posicoesValidas(e, v);
                    }
                    break;

                case 'H':
                    if(e.peca == VAZIA) printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                    // else
                    break;

                case 'U':
                    if(e.peca == VAZIA) printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                    else undo(e);
                    break;

                case 'Q':
                    printf("\nSaiu do jogo.\n");
                    break;

                default:
                    printf("\nOpção inválida.\n");
                    break;
            }
        }

    }



    //  NOTA:
    //  uma vez guardado um jogo, a lista de jogadas prévias desaparece!

    return e;

}

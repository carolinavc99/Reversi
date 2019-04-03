#include "menu.h"
#include "comandos.h"
#include <stdio.h>
#include <ctype.h>

ESTADO menu (ESTADO e) { // interpretador
    char opcao=' ', arg1=' ', arg2=' ';
    char input[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

    while(toupper(opcao) != 'Q') {

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


        fgets(input, 10, stdin); // guarda em 'input', well, o input


        opcao = toupper(input[0]); // opcao é igual à pos 0 do input
        arg1 = toupper(input[2]);  // peca/linha é igual à pos 2 do input
        arg2 = toupper(input[4]);  // coluna é igual à pos 4 do input


        // prints-teste -- eliminar
        printf("input <%s>\n", input);
        printf("opcao <%c>\n", opcao);
        printf("argumento 1 <%c>\n", arg1);
        printf("argumento 2 <%c>\n", arg2);


        if (arg1 && arg1 != ' ') { //se a função pelo menos um argumento

            switch(opcao) {
                case 'N':
                    switch(arg1) {
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

                case 'L': // esta função não precisa de um ficheiro??
                    printa(e);
                    break;

                case 'E':
                    break;

                case 'J':
                    if (arg2 == NULL || arg2 == ' ') // se não existe arg2/é espaço
                        printf("Poucos argumentos.");
                    else
                        jogar(e, arg1, arg2); // coloca a peça no sítio, se tal for possível
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
                    break;

                case 'H':
                    break;

                case 'U':
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

    return e;

}

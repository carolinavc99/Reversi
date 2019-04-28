#include "menu.h"
#include "comandos.h"
#include "stack.h"
#include <stdio.h>
#include <ctype.h>

ESTADO menu (ESTADO e, struct JOGADA* topo) { // interpretador
    char opcao[1024], arg1='\0', arg2='\0';
    char input[1024];
    ESTADO v;
    int numero=0; // numero de (opcao + argumentos) inseridos

    topo = NULL;

    // número de jogadas efetuadas no ponto atual do jogo
    int jogadas_efetuadas = 0;
    // novajogada incrementa este valor


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

        // Desenha um cursor antecedido do próximo jogador a efetuar a jogada.
        if(e.peca == VALOR_O) printf("\nO ➢ ");
        else {
            if(e.peca == VALOR_X) printf("\nX ➢ ");
            else printf("\n  ➢ ");
        }

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
                    topo = resetJogadas(topo, &jogadas_efetuadas);
                    topo = push(e, topo);
                }
                else
                    printf("Peça inválida\n");

                break;

            case 'L':                                   //  <-- acaba quando se dá um nome que não existe
                sscanf(input, "%*s %s", &arg1);
                e = continuaJogo (e, &arg1);
                jogadas_efetuadas = 0;
                break;

            case 'E':
                sscanf(input, "%*s %s", &arg1);
                if (e.peca == VAZIA)
                    printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                else if (arg1 == '\0')
                    printf("\nPrecisa de indicar um nome para guardar o ficheiro.\n");

                else {
                    guardar(e, &arg1);
                    topo = resetJogadas(topo, &jogadas_efetuadas); // jogadas_efetuadas = 0 e lista de jogadas limpa
                    topo = push(e, topo);
                }
                break;

            case 'J':
                sscanf(input, "%*s %c %c", &arg1, &arg2);
                if (!arg2)
                    printf("\nFalta de argumentos.\n");
                else if (validarJogada(e, arg1, arg2) == 1)
                        printf("\nJogada inválida.\n");
                else if (e.peca == VAZIA)
                            printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                else {
                    e = jogar(e, arg1, arg2);  // coloca a peça no sítio, se tal for possível
                    topo = novaJogada(e, arg1, arg2, topo);
                    jogadas_efetuadas++;
                }
                printf("jog: %d", jogadas_efetuadas);
                 break;

            case 'A':
                sscanf(input, "%*s %c", &arg1);
                //bot(arg1);    // a função bot funciona dependendo da dificuldade do jogo
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
                 e = score(e);
                 if (jogadas_efetuadas == 0)
                      printf("Não há mais jogadas para retroceder.");
                 else if (e.peca == VAZIA)
                     printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                 else {
                     topo = undo(&e, topo);
                     jogadas_efetuadas--;
                 }
                 break;

             case 'Q':
                 printf("\nSaiu do jogo.\n"
                        "\n        ### Trabalho realizado por ###"
                        "\n"
                        "\nAna Sofia Gomes             Miguel Rodrigues"
                        "\n             Carolina Vila Chã\n");
                 break;

             default:
                 printf("\nOpção inválida.\n");
                 break;
            }

        // limpar os argumentos
        arg1='\0';
        arg2 = '\0';
    }

    return e;
}

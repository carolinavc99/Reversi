#include "menu.h"
#include "comandos.h"
#include "stack.h"
#include "bot.h"
#include <stdio.h>
#include <ctype.h>

ESTADO menu (ESTADO e, struct JOGADA* topo) { // interpretador
    char opcao[1024], arg1='\0', arg2='\0';
    char input[1024];
    ESTADO v;

    topo = NULL;

    // número de jogadas efetuadas no ponto atual do jogo
    int jogadas_efetuadas = 0; // novajogada incrementa este valor


    while (toupper(opcao[0]) != 'Q') {

        printf("                            ===========                            \n"
               "                            | REVERSI |                            \n"
               "                            ===========                            \n"
               "                                                                   \n"
               " ==============================     ============================== \n"
               " |  N   Novo Jogo             |     |  L   Carregar Jogo         | \n"
               " ==============================     ============================== \n"
               " ==============================     ============================== \n"
               " |  E   Guardar Jogo          |     |  J   Jogar                 | \n"
               " ==============================     ============================== \n"
               " ==============================     ============================== \n"
               " |  S   Jogadas Validas       |     |  H   Sugestao de Jogada    | \n"
               " ==============================     ============================== \n"
               " ==============================     ============================== \n"
               " |  U   Desfazer Jogada       |     |  A   Novo Jogo contra Bot  | \n"
               " ==============================     ============================== \n"
               "                                                                   \n"
               "                                                                   \n"
               "                      =======================                      \n"
               "                      |  Q   Sair do Jogo   |                      \n"
               "                      =======================                      \n");


        /* menu antigo
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
                 ". (D) Dicas sobre como jogar                    .\n"   // nova opção Dicas
                 ". (Q) Sair                                      .\n"
                 ". . . . . . . . . . . . . . . . . . . . . . . . .\n");
        */


        // Desenha um cursor antecedido do próximo jogador a efetuar a jogada.
        if(e.peca == VALOR_O) printf("\nO ➢ ");
        else {
            if(e.peca == VALOR_X) printf("\nX ➢ ");
            else printf("\n  ➢ ");
        }

        // guarda em 'input' o input
        fgets(input, 1000, stdin);

        sscanf(input, "%s", opcao);

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
                } else
                    printf("Peça inválida\n");

                break;

            case 'L':                                   //  <-- acaba quando se dá um nome que não existe
                sscanf(input, "%*s %s", &arg1);
                e = continuaJogo(e, &arg1);
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
                if (e.peca == VAZIA)
                    printf("\nCrie um novo jogo ou continue um jogo já existente.\n");
                else {
                    v = calcJogadasValidas(e);
                    posicoesValidas(e, v);
                }
                break;

            case 'H':
                if (e.peca == VAZIA)
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
                    printf("jog undo: %d", jogadas_efetuadas);
                }
                break;

            case 'Q':
                printf("\nSaiu do jogo.\n"
                       "\n        ### Trabalho realizado por ###"
                       "\n"
                       "\nAna Sofia Gomes             Miguel Rodrigues"
                       "\n             Carolina Vila Chã\n");
                break;

            case 'D':
                printf("\n. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."
                       "\n.      INPUT       ||                                     AÇÃO                                        ."
                       "\n. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."
                       "\n. N <peça>         || Inicia um novo jogo em que o primeiro a jogar é o jogador com a peça indicada.  ."
                       "\n. L <ficheiro>     || Continua um jogo previamente guardado no ficheiro pedido.                       ."
                       "\n. E <ficheiro>     || Escreve em ficheiro (guarda) o estado atual do jogo.                            ."
                       "\n. J <L> <C>        || Joga a peça atual na posição (L,C). O comando J 1 1 coloca a peça atual no      ."
                       "\n.                      canto superior esquerdo, se tal for possível                                   ."
                       "\n. S                || Imprime um ponto ‘.’ nas posições em que a jogada é válida.                     ."
                       "\n. H                || Mostra uma sugestão de jogada. É colocado um ‘?’ no sitio sugerido.             ."
                       "\n. U                || Desfaz a última jogada. Permite desfazer até ao estado inicial do jogo, ou      ."
                       "\n.                      até ao último 'E' ou 'L' efetuado.                                             ."
                       "\n. A <peça> <nível> || Cria um novo jogo contra ‘bot’ em que o computador joga com a peça contra um    ."
                       "\n.                      bot de nível (3 níveis possíveis). Neste modo quem joga primeiro é sempre o    ."
                       "\n.                      jogador com a peça ‘X’.                                                        ."
                       "\n. Q                || Sair do jogo.                                                                   ."
                       "\n. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ."
                       "\n");
                break;

            default:
                printf("\nOpção inválida.\n");
                break;
        }

        // dar reset aos argumentos
        arg1='\0';
        arg2 = '\0';
    }

    return e;
}

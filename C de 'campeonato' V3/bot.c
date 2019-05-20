#include "estado.h"
#include "bot.h"
#include "comandos.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Devolve o estado com a jogada feita/escolhida pelo bot nível
 * @param e Estado atual
 * @return Estado atualizado pelo bot
 */
ESTADO bot1 (ESTADO e) {

    PONTO validas[50];
    int pr, pp; //Posição random e posições preenchidas

    pp = arrayValidas (e,validas);

    //Escolhe um indice do array (random)
    // rand gera números de 0 ao tamanho do array menos 1
    if(pp==1) pr = 0;
    else pr = (rand()>RAND_MAX/(pp-1));
    //TESTE
    //printf("pr: %d\n", pr);

    //Indica as coordenadas guardadas no indice do array escolhido
    //printf("Posição random: (%d,%d)\n", validas[pr].l, validas[pr].c);

    validas[pr].l = validas[pr].l + 48;
    validas[pr].c = validas[pr].c + 48;

    e = jogar(e,validas[pr].l, validas[pr].c);

    return e;
}

/**
 * Devolve o estado com a jogada feita/escolhida pelo bot.
 * @param e Estado atual
 * @return Estado onde o bot já jogou
 */
ESTADO bot (ESTADO e) {
    ESTADO f;
    int pontuacao=-1;
    PARENTE p;
    PONTO melhor_jogada;

    switch(e.modo) {
        case '1':
            e = bot1(e);
            return e;
            break;

        case '2': {
            int temp_pontuacao=0;
            //teste
            printf("\ncaso 2 escolhido");
            int altura = 3;
            PONTO validas[25];
            int i=0;

            // cria array de jogadas disponíveis
            f = calcJogadasValidas(e);
            for(int a=0; a<8; a++) {
                for(int b=0; b<8; b++) {
                    if(f.grelha[a][b]==e.peca) {
                        validas[i].l = a+1;
                        validas[i].c = b+1;
                        i++;
                    }
                }
            }

            /*  > array de estados alterados com as jogadas
             *  > árvores de jogadas
                > aplica minmax a cada uma
                > escolhe a melhor jogada
             */
            //teste
            printf("\ni. %d",i);
            int j=0;
            while (j <= i) { //percorre as jogadas válidas até chegar à última
                //teste
                printf("\nvalidas: linha %d, coluna %d", validas[j].l, validas[j].c);
                // cria a raiz
                p = criaRaiz(e, validas[j], altura);
                // cria a árvore de jogadas
                p = jogTree(p, altura);
                // minmax
                temp_pontuacao = minmax(p->estado, altura, p);
                if (pontuacao < temp_pontuacao) {
                    pontuacao = temp_pontuacao;
                    melhor_jogada = validas[j];
                    //teste
                    printf("\npontuacao nova: %d temp_pontuacao: %d",pontuacao, temp_pontuacao);
                    printf("\nnova jogada: linha %d coluna %d", validas[j].l, validas[j].c);
                }
                j++;
            }

            e = jogar(e,melhor_jogada.l, melhor_jogada.c);
            return e;
            break;
        }

        case '3':
            return e;
            break;

        default:
            printf("Erro com o bot. Dificuldade inválida.");
            return e;
    }
}


/**
 * Maximiza a pontuação de um nodo da árvore de jogadas.
 * @param e Estado atual
 * @param x Nodo da árvore
 * @param valor Valor anterior
 * @return Valor maximizado
 */
int aux_minMAX (ESTADO e, PARENTE x, int valor) {
    //teste
    printf("\nminMAX inicializada");
    valor = max(valor, minmax(x->estado, x->nivel, x->one)); // o x->nível já vai decrescendo à medida que progride na árvore
    valor = max(valor, minmax(x->estado, x->nivel, x->two));
    valor = max(valor, minmax(x->estado, x->nivel, x->three));
    valor = max(valor, minmax(x->estado, x->nivel, x->four));
    valor = max(valor, minmax(x->estado, x->nivel, x->five));
    valor = max(valor, minmax(x->estado, x->nivel, x->six));
    valor = max(valor, minmax(x->estado, x->nivel, x->seven));
    valor = max(valor, minmax(x->estado, x->nivel, x->eight));
    valor = max(valor, minmax(x->estado, x->nivel, x->nine));
    valor = max(valor, minmax(x->estado, x->nivel, x->ten));
    valor = max(valor, minmax(x->estado, x->nivel, x->eleven));
    valor = max(valor, minmax(x->estado, x->nivel, x->twelve));
    valor = max(valor, minmax(x->estado, x->nivel, x->thirt));
    valor = max(valor, minmax(x->estado, x->nivel, x->fourt));
    valor = max(valor, minmax(x->estado, x->nivel, x->fift));
    valor = max(valor, minmax(x->estado, x->nivel, x->sixt));
    valor = max(valor, minmax(x->estado, x->nivel, x->sevent));
    valor = max(valor, minmax(x->estado, x->nivel, x->eightt));
    valor = max(valor, minmax(x->estado, x->nivel, x->ninet));
    valor = max(valor, minmax(x->estado, x->nivel, x->twenty));
    valor = max(valor, minmax(x->estado, x->nivel, x->tone));
    valor = max(valor, minmax(x->estado, x->nivel, x->ttwo));
    valor = max(valor, minmax(x->estado, x->nivel, x->tthree));
    valor = max(valor, minmax(x->estado, x->nivel, x->tfour));

    return valor;
}


/**
 * Minimiza a pontuação de um nodo da árvore de jogadas.
 * @param e Estado atual
 * @param x Nodo da árvore
 * @param valor Valor anterior
 * @return Valor minimizado
 */
int aux_MINmax (ESTADO e, PARENTE x, int valor) {
    //teste
    printf("\nMINmax inicializada");
    valor = min(valor, minmax(x->estado, x->nivel, x->one));
    valor = min(valor, minmax(x->estado, x->nivel, x->two));
    valor = min(valor, minmax(x->estado, x->nivel, x->three));
    valor = min(valor, minmax(x->estado, x->nivel, x->four));
    valor = min(valor, minmax(x->estado, x->nivel, x->five));
    valor = min(valor, minmax(x->estado, x->nivel, x->six));
    valor = min(valor, minmax(x->estado, x->nivel, x->seven));
    valor = min(valor, minmax(x->estado, x->nivel, x->eight));
    valor = min(valor, minmax(x->estado, x->nivel, x->nine));
    valor = min(valor, minmax(x->estado, x->nivel, x->ten));
    valor = min(valor, minmax(x->estado, x->nivel, x->eleven));
    valor = min(valor, minmax(x->estado, x->nivel, x->twelve));
    valor = min(valor, minmax(x->estado, x->nivel, x->thirt));
    valor = min(valor, minmax(x->estado, x->nivel, x->fourt));
    valor = min(valor, minmax(x->estado, x->nivel, x->fift));
    valor = min(valor, minmax(x->estado, x->nivel, x->sixt));
    valor = min(valor, minmax(x->estado, x->nivel, x->sevent));
    valor = min(valor, minmax(x->estado, x->nivel, x->eightt));
    valor = min(valor, minmax(x->estado, x->nivel, x->ninet));
    valor = min(valor, minmax(x->estado, x->nivel, x->twenty));
    valor = min(valor, minmax(x->estado, x->nivel, x->tone));
    valor = min(valor, minmax(x->estado, x->nivel, x->ttwo));
    valor = min(valor, minmax(x->estado, x->nivel, x->tthree));
    valor = min(valor, minmax(x->estado, x->nivel, x->tfour));

    return valor;
}


/**
 * Calcula de modo recursivo qual a melhor jogada a realizar.
 * @param e Estado atual
 * @param nivel Nível de dificuldade/Altura da árvore de jogadas possíveis
 * @param x Raiz da árvore
 * @return Pontuação do jogo se se seguir as jogadas da árvore
 */
int minmax(ESTADO e, int nivel, PARENTE x) {
    //teste
    printf("\nminmax inicializada");
    int valor;
    //x->estado = e;

    // Peça do adversario
    VALOR adv;
    adv = opp(e.bot);

    // se chegou ao final da árvore, ou se chegou ao final do jogo
    if ((nivel == 0) || ( (passaJogada(e, chrtovalor(e.bot)) == 1) && (passaJogada(e, adv) == 1) ) ) {
        if (e.bot == VALOR_X) {
            e = score(x->estado); // calcula os scores do estado
            return e.score[0]; // devolve o score do bot
        }
        if (e.bot == VALOR_O) {
            e = score(x->estado);
            return e.score[1];
        }
    }

    // temos de maximizar
    if (e.peca == e.bot) {

        if (x->one) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->one, valor);
                //teste
                printf("\nnodo 1: %d", valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->one, valor);
            }
        }
        else
            return valor;

        if (x->two) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->two, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->two, valor);
            }
        }
        else
            return valor;

        if (x->three) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->three, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->three, valor);
            }
        }
        else
            return valor;

        if (x->four) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->four, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->four, valor);
            }
        }
        else
            return valor;

        if (x->five) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->five, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->five, valor);
            }
        }
        else
            return valor;

        if (x->six) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->six, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->six, valor);
            }
        }
        else
            return valor;

        if (x->seven) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->seven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->seven, valor);
            }
        }
        else
            return valor;

        if (x->eight) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->eight, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->eight, valor);
            }
        }
        else
            return valor;

        if (x->nine) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->nine, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->nine, valor);
            }
        }
        else
            return valor;

        if (x->ten) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->ten, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->ten, valor);
            }
        }
        else
            return valor;

        if (x->eleven) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->eleven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->eleven, valor);
            }
        }
        else
            return valor;

        if (x->twelve) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->twelve, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->twelve, valor);
            }
        }
        else
            return valor;

        if (x->thirt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->thirt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->thirt, valor);
            }
        }
        else
            return valor;

        if (x->fourt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->fourt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->fourt, valor);
            }
        }
        else
            return valor;

        if (x->fift) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->fift, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->fift, valor);
            }
        }
        else
            return valor;

        if (x->sixt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->sixt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->sixt, valor);
            }
        }
        else
            return valor;

        if (x->sevent) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->sevent, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->sevent, valor);
            }
        }
        else
            return valor;

        if (x->eightt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->eightt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->eightt, valor);
            }
        }
        else
            return valor;

        if (x->ninet) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->ninet, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->ninet, valor);
            }
        }
        else
            return valor;

        if (x->twenty) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->twenty, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->twenty, valor);
            }
        }
        else
            return valor;

        if (x->tone) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->tone, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->tone, valor);
            }
        }
        else
            return valor;

        if (x->ttwo) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->ttwo, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->ttwo, valor);
            }
        }
        else
            return valor;

        if (x->tthree) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->tthree, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->tthree, valor);
            }
        }
        else
            return valor;

        if (x->tfour) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, x->tfour, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, x->tfour, valor);
            }
        }
        else
            return valor;

        return valor;
    }

    //temos de minimizar
    else { // (e.peca == adv)
        valor = +1000;

        if (x->one) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->one, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->one, valor);
            }
        }
        else
            return valor;

        if (x->two) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->two, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->two, valor);
            }
        }
        else
            return valor;

        if (x->three) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->three, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->three, valor);
            }
        }
        else
            return valor;

        if (x->four) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->four, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->four, valor);
            }
        }
        else
            return valor;

        if (x->five) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->five, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->five, valor);
            }
        }
        else
            return valor;

        if (x->six) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->six, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->six, valor);
            }
        }
        else
            return valor;

        if (x->seven) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->seven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->seven, valor);
            }
        }
        else
            return valor;

        if (x->eight) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->eight, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->eight, valor);
            }
        }
        else
            return valor;

        if (x->nine) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->nine, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->nine, valor);
            }
        }
        else
            return valor;

        if (x->ten) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->ten, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->ten, valor);
            }
        }
        else
            return valor;

        if (x->eleven) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->eleven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->eleven, valor);
            }
        }
        else
            return valor;

        if (x->twelve) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->twelve, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->twelve, valor);
            }
        }
        else
            return valor;

        if (x->thirt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->thirt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->thirt, valor);
            }
        }
        else
            return valor;

        if (x->fourt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->fourt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->fourt, valor);
            }
        }
        else
            return valor;

        if (x->fift) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->fift, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->fift, valor);
            }
        }
        else
            return valor;

        if (x->sixt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->sixt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->sixt, valor);
            }
        }
        else
            return valor;

        if (x->sevent) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->sevent, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->sevent, valor);
            }
        }
        else
            return valor;

        if (x->eightt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->eightt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->eightt, valor);
            }
        }
        else
            return valor;

        if (x->ninet) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->ninet, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->ninet, valor);
            }
        }
        else
            return valor;

        if (x->twenty) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->twenty, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->twenty, valor);
            }
        }
        else
            return valor;

        if (x->tone) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->tone, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->tone, valor);
            }
        }
        else
            return valor;

        if (x->ttwo) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->ttwo, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->ttwo, valor);
            }
        }
        else
            return valor;

        if (x->tthree) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->tthree, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->tthree, valor);
            }
        }
        else
            return valor;

        if (x->tfour) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, x->tfour, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, x->tfour, valor);
            }
        }
        else
            return valor;

        return valor;
    }
}

/*
( Initial call )
minimax(raiz, nivel, e.bot)
*/


/**
 * Retorna a Peça oposta (X<->O).
 * @param peca Peça atual
 * @return Peça oposta
 */

VALOR opp (VALOR peca) {
    if (peca == VALOR_X)
        return VALOR_O;
    else
        return VALOR_X;
}

/**
 * Altera o estado fornecido utilizando a jogada contida no Parente x.
 * @param e Estado a alterar.
 * @param x Contém a próxima jogada.
 * @return Estado alterado pelo bot, contino no parente.
 */
ESTADO jogadaFilho (ESTADO e, PARENTE x) {
    if ((x->linha && x->coluna) && (validarJogada(e, x->linha, x->coluna) != 1) && (e.peca != VAZIA) && (e.modo != ' '))
        x->estado = jogar(e, x->linha, x->coluna);

    return x->estado;
}

/**
 * Cria a raiz/nodo inicial de uma árvore de PARENTEs.
 * @param e Estado anterior à jogada
 * @param posicao Jogada
 * @param altura Dificuldade do bot/altura máxima da árvore
 * @return Raiz da árvore
 */
PARENTE criaRaiz(ESTADO e, PONTO posicao, int altura) {
    PARENTE p;
    p = (PARENTE)malloc(sizeof(PARENTE));

    //criar raiz da árvore
    p->nivel = altura;
    p->linha = posicao.l;
    p->coluna = posicao.c;
    p->estado = jogadaFilho(e,p);

    p = nivelTree(p,altura);

    return p;
}


/**
 * Cria apenas uma geração de PARENTEs/jogadas válidas
 * @param altura Altura na árvore
 * @return Raiz da árvore
 */
PARENTE nivelTree(PARENTE p, int altura) {
//teste
    printf("\nnivelTree inicializada com altura(%d) e parente: nivel(%d) linha(%d) coluna(%d)", altura, p->nivel, p->linha, p->coluna);
    printf("\nnivelTree estado:\n");
    printa(p->estado);

    // criar a lista de jogadas válidas
    ESTADO f;
    PONTO validas[25];
    int i=0;
    f = calcJogadasValidas(p->estado);
    for(int a=0; a<8; a++) {
        for(int b=0; b<8; b++) {
            if(f.grelha[a][b] == p->estado.peca) {
                validas[i].l = a+1;
                validas[i].c = b+1;
                i++;
            }
        }
    }


    // cria os filhos de acordo com a lista de jogadas válidas
    // pegar no estado de p -> aplica-lhe a jogada do seu filho -> e guarda o novo estado no filho
    if (1<=i && altura > 0) {   // se ainda existem jogadas válidas e altura > 0
        p->one = (PARENTE)malloc(sizeof(PARENTE));      // reserva espaço na memória
        p->one->linha = validas[1].l;                   // coloca a jogada dentro do filho
        p->one->coluna = validas[1].c;
        p->one->nivel = p->nivel -1;                    // diminui o nivel do nodo
        p->one->estado = jogadaFilho(p->estado,p->one); // altera o estado do pai com a jogada do filho, e guarda no filho
    }
    else if (2<=i && altura > 0) {
        p->two = (PARENTE)malloc(sizeof(PARENTE));
        p->two->linha = validas[2].l;
        p->two->coluna = validas[2].c;
        p->two->nivel = p->nivel -1;
        p->two->estado = jogadaFilho(p->estado,p->two);
    }
    else if (3<=i && altura > 0) {
        p->three = (PARENTE)malloc(sizeof(PARENTE));
        p->three->linha = validas[3].l;
        p->three->coluna = validas[3].c;
        p->three->nivel = p->nivel -1;
        p->three->estado = jogadaFilho(p->estado,p->three);
    }
    else if (4<=i && altura > 0) {
        p->four = (PARENTE)malloc(sizeof(PARENTE));
        p->four->linha = validas[4].l;
        p->four->coluna = validas[4].c;
        p->four->nivel = p->nivel -1;
        p->four->estado = jogadaFilho(p->estado,p->four);
    }
    else if (5<=i && altura > 0) {
        p->five = (PARENTE)malloc(sizeof(PARENTE));
        p->five->linha = validas[5].l;
        p->five->coluna = validas[5].c;
        p->five->nivel = p->nivel -1;
        p->five->estado = jogadaFilho(p->estado,p->five);
    }
    else if (6<=i && altura > 0) {
        p->six = (PARENTE)malloc(sizeof(PARENTE));
        p->six->linha = validas[6].l;
        p->six->coluna = validas[6].c;
        p->six->nivel = p->nivel -1;
        p->six->estado = jogadaFilho(p->estado,p->six);
    }
    else if (7<=i && altura > 0) {
        p->seven = (PARENTE)malloc(sizeof(PARENTE));
        p->seven->linha = validas[7].l;
        p->seven->coluna = validas[7].c;
        p->seven->nivel = p->nivel -1;
        p->seven->estado = jogadaFilho(p->estado,p->seven);
    }
    else if (8<=i && altura > 0) {
        p->eight = (PARENTE)malloc(sizeof(PARENTE));
        p->eight->linha = validas[8].l;
        p->eight->coluna = validas[8].c;
        p->eight->nivel = p->nivel -1;
        p->eight->estado = jogadaFilho(p->estado,p->eight);
    }
    else if (9<=i && altura > 0) {
        p->nine = (PARENTE)malloc(sizeof(PARENTE));
        p->nine->linha = validas[9].l;
        p->nine->coluna = validas[9].c;
        p->nine->nivel = p->nivel -1;
        p->nine->estado = jogadaFilho(p->estado,p->nine);
    }
    else if (10<=i &&& altura > 0) {
        p->ten = (PARENTE)malloc(sizeof(PARENTE));
        p->ten->linha = validas[10].l;
        p->ten->coluna = validas[10].c;
        p->ten->nivel = p->nivel -1;
        p->ten->estado = jogadaFilho(p->estado,p->ten);
    }
    else if (11<=i && altura > 0) {
        p->eleven = (PARENTE)malloc(sizeof(PARENTE));
        p->eleven->linha = validas[11].l;
        p->eleven->coluna = validas[11].c;
        p->eleven->nivel = p->nivel -1;
        p->eleven->estado = jogadaFilho(p->estado,p->eleven);
    }
    else if (12<=i && altura > 0) {
        p->twelve = (PARENTE)malloc(sizeof(PARENTE));
        p->twelve->linha = validas[12].l;
        p->twelve->coluna = validas[12].c;
        p->twelve->nivel = p->nivel -1;
        p->twelve->estado = jogadaFilho(p->estado,p->twelve);
    }
    else if (13<=i && altura > 0) {
        p->thirt = (PARENTE)malloc(sizeof(PARENTE));
        p->thirt->linha = validas[13].l;
        p->thirt->coluna = validas[13].c;
        p->thirt->nivel = p->nivel -1;
        p->thirt->estado = jogadaFilho(p->estado,p->thirt);
    }
    else if (14<=i && altura > 0) {
        p->fourt = (PARENTE)malloc(sizeof(PARENTE));
        p->fourt->linha = validas[14].l;
        p->fourt->coluna = validas[14].c;
        p->fourt->nivel = p->nivel -1;
        p->fourt->estado = jogadaFilho(p->estado,p->fourt);
    }
    else if (15<=i && altura > 0) {
        p->fift = (PARENTE)malloc(sizeof(PARENTE));
        p->fift->linha = validas[15].l;
        p->fift->coluna = validas[15].c;
        p->fift->nivel = p->nivel -1;
        p->fift->estado = jogadaFilho(p->estado,p->fift);
    }
    else if (16<=i && altura > 0) {
        p->sixt = (PARENTE)malloc(sizeof(PARENTE));
        p->sixt->linha = validas[16].l;
        p->sixt->coluna = validas[16].c;
        p->sixt->nivel = p->nivel -1;
        p->sixt->estado = jogadaFilho(p->estado,p->sixt);
    }
    else if (17<=i && altura > 0) {
        p->sevent = (PARENTE)malloc(sizeof(PARENTE));
        p->sevent->linha = validas[17].l;
        p->sevent->coluna = validas[17].c;
        p->sevent->nivel = p->nivel -1;
        p->sevent->estado = jogadaFilho(p->estado,p->sevent);
    }
    else if (18<=i && altura > 0) {
        p->eightt = (PARENTE)malloc(sizeof(PARENTE));
        p->eightt->linha = validas[18].l;
        p->eightt->coluna = validas[18].c;
        p->eightt->nivel = p->nivel -1;
        p->eightt->estado = jogadaFilho(p->estado,p->eightt);
    }
    else if (19<=i && altura > 0) {
        p->ninet = (PARENTE)malloc(sizeof(PARENTE));
        p->ninet->linha = validas[19].l;
        p->ninet->coluna = validas[19].c;
        p->ninet->nivel = p->nivel -1;
        p->ninet->estado = jogadaFilho(p->estado,p->ninet);
    }
    else if (20<=i && altura > 0) {
        p->twenty = (PARENTE)malloc(sizeof(PARENTE));
        p->twenty->linha = validas[20].l;
        p->twenty->coluna = validas[20].c;
        p->twenty->nivel = p->nivel -1;
        p->twenty->estado = jogadaFilho(p->estado,p->twenty);
    }
    else if (21<=i && altura > 0) {
        p->tone = (PARENTE)malloc(sizeof(PARENTE));
        p->tone->linha = validas[21].l;
        p->tone->coluna = validas[21].c;
        p->tone->nivel = p->nivel -1;
        p->tone->estado = jogadaFilho(p->estado,p->tone);
    }
    else if (22<=i && altura > 0) {
        p->ttwo = (PARENTE)malloc(sizeof(PARENTE));
        p->ttwo->linha = validas[22].l;
        p->ttwo->coluna = validas[22].c;
        p->ttwo->nivel = p->nivel -1;
        p->ttwo->estado = jogadaFilho(p->estado,p->ttwo);
    }
    else if (23<=i && altura > 0) {
        p->tthree = (PARENTE)malloc(sizeof(PARENTE));
        p->tthree->linha = validas[23].l;
        p->tthree->coluna = validas[23].c;
        p->tthree->nivel = p->nivel -1;
        p->tthree->estado = jogadaFilho(p->estado,p->tthree);
    }
    else if (24<=i && altura > 0) {
        p->tfour = (PARENTE)malloc(sizeof(PARENTE));
        p->tfour->linha = validas[24].l;
        p->tfour->coluna = validas[24].c;
        p->tfour->nivel = p->nivel -1;
        p->tfour->estado = jogadaFilho(p->estado,p->tfour);
    }

    return p;
}

/**
 * Cria a árvore de jogadas válidas
 * @param p Raiz da árvore
 * @param altura Altura máxima/dificuldade do bot
 * @return Raiz da árvore
 */
PARENTE jogTree(PARENTE p, int altura) {
    //teste
    printf("\njogTree inicializada com altura(%d)", altura);

    while (altura >= 0) {
        if (p->one) {
            p->one = nivelTree(p->one, altura); // cria a sub-árvore
            p->one = jogTree(p->one, altura-1); // cria as próximas sub-árvores até altura = 0
            //teste
            printf("\njogTree nodo 1: altura(%d), estado:\n", altura);
            printa(p->one->estado);
        }
        else if (p->two) {
            p->two = nivelTree(p->two, altura);
            p->two = jogTree(p->two, altura - 1);
        }
        else if (p->three) {
            p->three = nivelTree(p->three, altura);
            p->three = jogTree(p->three, altura - 1);
        }
        else if (p->four) {
            p->four = nivelTree(p->four, altura);
            p->four = jogTree(p->four, altura - 1);
        }
        else if (p->five) {
            p->five = nivelTree(p->five, altura);
            p->five = jogTree(p->five, altura - 1);
        }
        else if (p->six) {
            p->six = nivelTree(p->six, altura);
            p->six = jogTree(p->six, altura - 1);
        }
        else if (p->seven) {
            p->seven = nivelTree(p->seven, altura);
            p->seven = jogTree(p->seven, altura - 1);
        }
        else if (p->eight) {
            p->eight = nivelTree(p->eight, altura);
            p->eight = jogTree(p->eight, altura - 1);
        }
        else if (p->nine) {
            p->nine = nivelTree(p->nine, altura);
            p->nine = jogTree(p->nine, altura - 1);
        }
        else if (p->ten) {
            p->ten = nivelTree(p->ten, altura);
            p->ten = jogTree(p->ten, altura - 1);
        }
        else if (p->eleven) {
            p->eleven = nivelTree(p->eleven, altura);
            p->eleven = jogTree(p->eleven, altura - 1);
        }
        else if (p->twelve) {
            p->twelve = nivelTree(p->twelve, altura);
            p->twelve = jogTree(p->twelve, altura - 1);
        }
        else if (p->thirt) {
            p->thirt = nivelTree(p->thirt, altura);
            p->thirt = jogTree(p->thirt, altura - 1);
        }
        else if (p->fourt) {
            p->fourt = nivelTree(p->fourt, altura);
            p->fourt = jogTree(p->fourt, altura - 1);
        }
        else if (p->fift) {
            p->fift = nivelTree(p->fift, altura);
            p->fift = jogTree(p->fift, altura - 1);
        }
        else if (p->sixt) {
            p->sixt = nivelTree(p->sixt, altura);
            p->sixt = jogTree(p->sixt, altura - 1);
        }
        else if (p->sevent) {
            p->sevent = nivelTree(p->sevent, altura);
            p->sevent = jogTree(p->sevent, altura - 1);
        }
        else if (p->eightt) {
            p->eightt = nivelTree(p->eightt, altura);
            p->eightt = jogTree(p->eightt, altura - 1);
        }
        else if (p->ninet) {
            p->ninet = nivelTree(p->ninet, altura);
            p->ninet = jogTree(p->ninet, altura - 1);
        }
        else if (p->twenty) {
            p->twenty = nivelTree(p->twenty, altura);
            p->twenty = jogTree(p->twenty, altura - 1);
        }
        else if (p->tone) {
            p->tone = nivelTree(p->tone, altura);
            p->tone = jogTree(p->tone, altura - 1);
        }
        else if (p->ttwo) {
            p->ttwo = nivelTree(p->ttwo, altura);
            p->ttwo = jogTree(p->ttwo, altura - 1);
        }
        else if (p->tthree) {
            p->tthree = nivelTree(p->tthree, altura);
            p->tthree = jogTree(p->tthree, altura - 1);
        }
        else if (p->tfour) {
            p->tfour = nivelTree(p->tfour, altura);
            p->tfour = jogTree(p->tfour, altura - 1);
        }
        altura--;
    }
    return p;
}



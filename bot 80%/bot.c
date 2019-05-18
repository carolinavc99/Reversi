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

    e = jogar (e,validas[pr].l, validas[pr].c);

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
    ESTADO raizes[25]; //array de árvores derivadas das jogadas
    PARENTE p;
    PONTO melhor_jogada;

    switch(e.modo) {
        case '1':
            e = bot1(e);
            break;

        case '2': {
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

            /*  > array de estados alterados com as jogadas
             *  > árvores de jogadas
                > aplica minmax a cada uma
                > escolhe a melhor jogada
             */
            while (validas[i].l && validas[i].c) { //para cada jogada válida
                p = jogTree(e, validas[i], 3); // devolve a árvore correspondente
                if (pontuacao < minmax(p->estado,3,p)) {
                    pontuacao = minmax(p->estado,3,p);
                    melhor_jogada = validas[i];
                }
                i++;
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
    valor = max(valor, minmax(jogadaFilho(e, x->one), x->nivel - 1, x->one));
    valor = max(valor, minmax(jogadaFilho(e, x->two), x->nivel - 1, x->two));
    valor = max(valor, minmax(jogadaFilho(e, x->three), x->nivel - 1, x->three));
    valor = max(valor, minmax(jogadaFilho(e, x->four), x->nivel - 1, x->four));
    valor = max(valor, minmax(jogadaFilho(e, x->five), x->nivel - 1, x->five));
    valor = max(valor, minmax(jogadaFilho(e, x->six), x->nivel - 1, x->six));
    valor = max(valor, minmax(jogadaFilho(e, x->seven), x->nivel - 1, x->seven));
    valor = max(valor, minmax(jogadaFilho(e, x->eight), x->nivel - 1, x->eight));
    valor = max(valor, minmax(jogadaFilho(e, x->nine), x->nivel - 1, x->nine));
    valor = max(valor, minmax(jogadaFilho(e, x->ten), x->nivel - 1, x->ten));
    valor = max(valor, minmax(jogadaFilho(e, x->eleven), x->nivel - 1, x->eleven));
    valor = max(valor, minmax(jogadaFilho(e, x->twelve), x->nivel - 1, x->twelve));
    valor = max(valor, minmax(jogadaFilho(e, x->thirt), x->nivel - 1, x->thirt));
    valor = max(valor, minmax(jogadaFilho(e, x->fourt), x->nivel - 1, x->fourt));
    valor = max(valor, minmax(jogadaFilho(e, x->fift), x->nivel - 1, x->fift));
    valor = max(valor, minmax(jogadaFilho(e, x->sixt), x->nivel - 1, x->sixt));
    valor = max(valor, minmax(jogadaFilho(e, x->sevent), x->nivel - 1, x->sevent));
    valor = max(valor, minmax(jogadaFilho(e, x->eightt), x->nivel - 1, x->eightt));
    valor = max(valor, minmax(jogadaFilho(e, x->ninet), x->nivel - 1, x->ninet));
    valor = max(valor, minmax(jogadaFilho(e, x->twenty), x->nivel - 1, x->twenty));
    valor = max(valor, minmax(jogadaFilho(e, x->tone), x->nivel - 1, x->tone));
    valor = max(valor, minmax(jogadaFilho(e, x->ttwo), x->nivel - 1, x->ttwo));
    valor = max(valor, minmax(jogadaFilho(e, x->tthree), x->nivel - 1, x->tthree));
    valor = max(valor, minmax(jogadaFilho(e, x->tfour), x->nivel - 1, x->tfour));

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
    valor = min(valor, minmax(jogadaFilho(e, x->one), x->nivel - 1, x->one));
    valor = min(valor, minmax(jogadaFilho(e, x->two), x->nivel - 1, x->two));
    valor = min(valor, minmax(jogadaFilho(e, x->three), x->nivel - 1, x->three));
    valor = min(valor, minmax(jogadaFilho(e, x->four), x->nivel - 1, x->four));
    valor = min(valor, minmax(jogadaFilho(e, x->five), x->nivel - 1, x->five));
    valor = min(valor, minmax(jogadaFilho(e, x->six), x->nivel - 1, x->six));
    valor = min(valor, minmax(jogadaFilho(e, x->seven), x->nivel - 1, x->seven));
    valor = min(valor, minmax(jogadaFilho(e, x->eight), x->nivel - 1, x->eight));
    valor = min(valor, minmax(jogadaFilho(e, x->nine), x->nivel - 1, x->nine));
    valor = min(valor, minmax(jogadaFilho(e, x->ten), x->nivel - 1, x->ten));
    valor = min(valor, minmax(jogadaFilho(e, x->eleven), x->nivel - 1, x->eleven));
    valor = min(valor, minmax(jogadaFilho(e, x->twelve), x->nivel - 1, x->twelve));
    valor = min(valor, minmax(jogadaFilho(e, x->thirt), x->nivel - 1, x->thirt));
    valor = min(valor, minmax(jogadaFilho(e, x->fourt), x->nivel - 1, x->fourt));
    valor = min(valor, minmax(jogadaFilho(e, x->fift), x->nivel - 1, x->fift));
    valor = min(valor, minmax(jogadaFilho(e, x->sixt), x->nivel - 1, x->sixt));
    valor = min(valor, minmax(jogadaFilho(e, x->sevent), x->nivel - 1, x->sevent));
    valor = min(valor, minmax(jogadaFilho(e, x->eightt), x->nivel - 1, x->eightt));
    valor = min(valor, minmax(jogadaFilho(e, x->ninet), x->nivel - 1, x->ninet));
    valor = min(valor, minmax(jogadaFilho(e, x->twenty), x->nivel - 1, x->twenty));
    valor = min(valor, minmax(jogadaFilho(e, x->tone), x->nivel - 1, x->tone));
    valor = min(valor, minmax(jogadaFilho(e, x->ttwo), x->nivel - 1, x->ttwo));
    valor = min(valor, minmax(jogadaFilho(e, x->tthree), x->nivel - 1, x->tthree));
    valor = min(valor, minmax(jogadaFilho(e, x->tfour), x->nivel - 1, x->tfour));

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
    int valor;
    x->estado = e;

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
 * @param e Estado atual.
 * @param x Contém a próxima jogada. É um nodo da árvore de jogadas possíveis.
 * @return Estado alterado pelo bot.
 */

ESTADO jogadaFilho (ESTADO e, PARENTE x) {
    if ((x->linha && x->coluna) && (validarJogada(e, x->linha, x->coluna) != 1) && (e.peca != VAZIA) && (e.modo != ' '))
        e = jogar(e, x->linha, x->coluna);

    return e;
}

// cria uma árvore de jogadas possíveis dado uma jogada inicial, um estado, e a altura da árvore
PARENTE jogTree(ESTADO e, PONTO posicao, int altura) {
    PARENTE p;

    return p;
}
// cria apenas um nível de jogadas
PARENTE nivelTree(ESTADO e, PONTO posicao, int altura) {
    PARENTE p;

    int linha, coluna;
    linha = posicao.l;
    coluna = posicao.c;

    while (altura > 0) {
        p->linha = linha;
        p->coluna = coluna;
        p->one = jogTree(ESTADO e, PONTO );
    }



    return p;
}







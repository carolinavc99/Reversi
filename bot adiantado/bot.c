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
    printf("pr: %d\n", pr);

    //Indica as coordenadas guardadas no indice do array escolhido
    printf("Posição random: (%d,%d)\n", validas[pr].l, validas[pr].c);

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
    switch(e.modo) {
        case '1':
            e = bot1(e);
            break;

        case '2':
            return e;
            break;

        case '3':
            return e;
            break;

        default:
            printf("Erro com o bot. Dificuldade inválida.");
            return e;
    }

    return e;

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

// compara o valor com o dos filhos, usando min
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
    valor = min(valor, minmax(jogadaFilho(e, x->thirt), x->nivel - 1, x->thirt))
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

// SEMPRE QUE A MINMAX CORRE, UTILIZA UMA DAS DUAS AUXILIARES
// LOGO
// O NÍVEL DECRESCE 1 A CADA ITERAÇÃO
// daí não precisarmos de diminuir o nível dentro da minmax E dentro das auxiliares
// (isso ia fazer com que diminuisse de 2 em 2)

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
    if ((nivel == 0) || ( (passaJogada(e, chrtovalor(e.bot)) == 1) && (passaJogada(e, adv) == 1) ) )
        if (e.bot == VALOR_X)
            return score(x->estado)[0];
        if (e.bot == VALOR_O)
            return score(x->estado)[1];

    // temos de maximizar
    if (e.peca == e.bot) {

        if (x->one) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->one, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->one, valor);
            }
        }
        else
            return valor;

        if (x->two) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->two, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->two, valor);
            }
        }
        else
            return valor;

        if (x->three) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->three, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->three, valor);
            }
        }
        else
            return valor;

        if (x->four) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->four, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->four, valor);
            }
        }
        else
            return valor;

        if (x->five) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->five, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->five, valor);
            }
        }
        else
            return valor;

        if (x->six) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->six, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->six, valor);
            }
        }
        else
            return valor;

        if (x->seven) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->seven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->seven, valor);
            }
        }
        else
            return valor;

        if (x->eight) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->eight, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->eight, valor);
            }
        }
        else
            return valor;

        if (x->nine) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->nine, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->nine, valor);
            }
        }
        else
            return valor;

        if (x->ten) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->ten, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->ten, valor);
            }
        }
        else
            return valor;

        if (x->eleven) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->eleven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->eleven, valor);
            }
        }
        else
            return valor;

        if (x->twelve) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->twelve, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->twelve, valor);
            }
        }
        else
            return valor;

        if (x->thirt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->thirt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->thirt, valor);
            }
        }
        else
            return valor;

        if (x->fourt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->fourt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->fourt, valor);
            }
        }
        else
            return valor;

        if (x->fift) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->fift, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->fift, valor);
            }
        }
        else
            return valor;

        if (x->sixt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->sixt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->sixt, valor);
            }
        }
        else
            return valor;

        if (x->sevent) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->sevent, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->sevent, valor);
            }
        }
        else
            return valor;

        if (x->eightt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->eightt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->eightt, valor);
            }
        }
        else
            return valor;

        if (x->ninet) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->ninet, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->ninet, valor);
            }
        }
        else
            return valor;

        if (x->twenty) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->twenty, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->twenty, valor);
            }
        }
        else
            return valor;

        if (x->tone) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->tone, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->tone, valor);
            }
        }
        else
            return valor;

        if (x->ttwo) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->ttwo, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->ttwo, valor);
            }
        }
        else
            return valor;

        if (x->tthree) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->tthree, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->tthree, valor);
            }
        }
        else
            return valor;

        if (x->tfour) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, x->tfour, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, x->tfour, valor);
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
                valor = aux_MINmax(e, nivel, x->one, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->one, valor);
            }
        }
        else
            return valor;

        if (x->two) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->two, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->two, valor);
            }
        }
        else
            return valor;

        if (x->three) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->three, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->three, valor);
            }
        }
        else
            return valor;

        if (x->four) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->four, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->four, valor);
            }
        }
        else
            return valor;

        if (x->five) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->five, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->five, valor);
            }
        }
        else
            return valor;

        if (x->six) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->six, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->six, valor);
            }
        }
        else
            return valor;

        if (x->seven) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->seven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->seven, valor);
            }
        }
        else
            return valor;

        if (x->eight) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->eight, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->eight, valor);
            }
        }
        else
            return valor;

        if (x->nine) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->nine, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->nine, valor);
            }
        }
        else
            return valor;

        if (x->ten) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->ten, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->ten, valor);
            }
        }
        else
            return valor;

        if (x->eleven) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->eleven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->eleven, valor);
            }
        }
        else
            return valor;

        if (x->twelve) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->twelve, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->twelve, valor);
            }
        }
        else
            return valor;

        if (x->thirt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->thirt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->thirt, valor);
            }
        }
        else
            return valor;

        if (x->fourt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->fourt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->fourt, valor);
            }
        }
        else
            return valor;

        if (x->fift) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->fift, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->fift, valor);
            }
        }
        else
            return valor;

        if (x->sixt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->sixt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->sixt, valor);
            }
        }
        else
            return valor;

        if (x->sevent) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->sevent, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->sevent, valor);
            }
        }
        else
            return valor;

        if (x->eightt) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->eightt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->eightt, valor);
            }
        }
        else
            return valor;

        if (x->ninet) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->ninet, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->ninet, valor);
            }
        }
        else
            return valor;

        if (x->twenty) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->twenty, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->twenty, valor);
            }
        }
        else
            return valor;

        if (x->tone) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->tone, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->tone, valor);
            }
        }
        else
            return valor;

        if (x->ttwo) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->ttwo, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->ttwo, valor);
            }
        }
        else
            return valor;

        if (x->tthree) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->tthree, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->tthree, valor);
            }
        }
        else
            return valor;

        if (x->tfour) {
            x->estado = score(e);
            if (e.bot == VALOR_X) {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, x->tfour, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, x->tfour, valor);
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
 * Altera o estado fornecido utilizando a jogada dentro do Parente x.
 * @param e Estado atual.
 * @param x Contém a próxima jogada. É um nodo da árvore de jogadas possíveis.
 * @return Estado alterado pelo bot.
 */
ESTADO jogadaFilho (ESTADO e, PARENTE x) {
    if ((x->linha && x->coluna) && (validarJogada(e, x->linha, x->coluna) != 1) && (e.peca != VAZIA) && (e.modo != ' '))
        e = jogar(e, x->linha, x->coluna);

    return e;
}

// cria uma árvore de jogadas possíveis dado uma jogada inicial, um estado, e a altura da àrvore
PARENTE jogTree(ESTADO e, PONTO posicao, int altura) {
    PRENTE p;

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
        p->one = jogTree(ESTADO e, PONTO )
    }



    return p;
}








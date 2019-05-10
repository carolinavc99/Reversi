#include "estado.h"
#include "bot.h"
#include "comandos.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Devolve o estado com a jogada feita/escolhida pelo bot nível
 * @param e
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
    printf("%d", pr);

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
            printf("Erro com o bot.");
            return e;
    }

    return e;

}
/*
// compara o valor com o dos filhos
int aux_minMAX (ESTADO e, int nivel, char letra, char letra_bot, char letra_adversario, PARENTE x, int valor) {
    valor = max(valor, minmax(x->one, x->nivel - 1, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->two, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->three, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->four, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->five, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->six, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->seven, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->eight, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->nine, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->ten, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->eleven, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->twelve, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->thirt, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->fourt, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->fift, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->sixt, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->sevent, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->eightt, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->ninet, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->twenty, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->tone, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->ttwo, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->tthree, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = max(valor, minmax(x->tfour, x->nivel - 2, letra, letra_bot, letra_adversario));  // menos 2 porque tem de saber o nível do parente??

    return valor;
}

int aux_MINmax (ESTADO e, int nivel, char letra, char letra_bot, char letra_adversario, PARENTE x, int valor) {
    valor = min(valor, minmax(x->one, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->two, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->three, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->four, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->five, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->six, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->seven, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->eight, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->nine, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->ten, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->eleven, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->twelve, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->thirt, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->fourt, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->fift, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->sixt, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->sevent, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->eightt, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->ninet, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->twenty, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->tone, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->ttwo, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->tthree, x->nivel - 2, letra, letra_bot, letra_adversario));
    valor = min(valor, minmax(x->tfour, x->nivel - 2, letra, letra_bot, letra_adversario));  // menos 2 porque tem de saber o nível do parente??

    return valor;
}

int minmax(ESTADO e, int nivel, char letra, char letra_bot, char letra_adversario, PARENTE x) {
    int valor;
    x->estado = e;

    letra_bot = toupper(letra_bot);
    letra_adversario = toupper(letra_adversario);
    letra = toupper(letra);

    // se é a raiz, ou se chegou ao final do jogo
    if ((nivel == 0) || ( (passaJogada(e, chrtovalor(letra_bot)) == 1) && (passaJogada(e, chrtovalor(letra_adversario)) == 1) ) )
        if (letra_bot == 'X')
            return score(x->estado)[0];
        if (letra_bot == 'O')
            return score(x->estado)[1];

    // temos de maximizar
    if (letra == letra_bot) {

        if (x->one) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->one, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->one, valor);
            }
        }
        else
            return valor;

        if (x->two) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->two, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->two, valor);
            }
        }
        else
            return valor;

        if (x->three) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->three, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->three, valor);
            }
        }
        else
            return valor;

        if (x->four) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->four, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->four, valor);
            }
        }
        else
            return valor;

        if (x->five) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->five, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->five, valor);
            }
        }
        else
            return valor;

        if (x->six) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->six, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->six, valor);
            }
        }
        else
            return valor;

        if (x->seven) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->seven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->seven, valor);
            }
        }
        else
            return valor;

        if (x->eight) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->eight, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->eight, valor);
            }
        }
        else
            return valor;

        if (x->nine) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->nine, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->nine, valor);
            }
        }
        else
            return valor;

        if (x->ten) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->ten, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->ten, valor);
            }
        }
        else
            return valor;

        if (x->eleven) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->eleven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->eleven, valor);
            }
        }
        else
            return valor;

        if (x->twelve) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->twelve, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->twelve, valor);
            }
        }
        else
            return valor;

        if (x->thirt) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->thirt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->thirt, valor);
            }
        }
        else
            return valor;

        if (x->fourt) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->fourt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->fourt, valor);
            }
        }
        else
            return valor;

        if (x->fift) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->fift, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->fift, valor);
            }
        }
        else
            return valor;

        if (x->sixt) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->sixt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->sixt, valor);
            }
        }
        else
            return valor;

        if (x->sevent) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->sevent, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->sevent, valor);
            }
        }
        else
            return valor;

        if (x->eightt) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->eightt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->eightt, valor);
            }
        }
        else
            return valor;

        if (x->ninet) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->ninet, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->ninet, valor);
            }
        }
        else
            return valor;

        if (x->twenty) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->twenty, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->twenty, valor);
            }
        }
        else
            return valor;

        if (x->tone) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->tone, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->tone, valor);
            }
        }
        else
            return valor;

        if (x->ttwo) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->ttwo, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->ttwo, valor);
            }
        }
        else
            return valor;

        if (x->tthree) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->tthree, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->tthree, valor);
            }
        }
        else
            return valor;

        if (x->tfour) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->tfour, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_adversario, letra_bot, letra_adversario, x->tfour, valor);
            }
        }
        else
            return valor;

    }

    //temos de minimizar
    else // (letra == letra_adversario){
        valor = +1000;

        if (x->one) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_minMAX(e, nivel, letra_bot, letra_bot, letra_adversario, x->one, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_minMAX(e, nivel, letra_bot, letra_bot, letra_adversario, x->one, valor);
            }
        }
        else
            return valor;

        if (x->two) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->two, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->two, valor);
            }
        }
        else
            return valor;

        if (x->three) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->three, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->three, valor);
            }
        }
        else
            return valor;

        if (x->four) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->four, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->four, valor);
            }
        }
        else
            return valor;

        if (x->five) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->five, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->five, valor);
            }
        }
        else
            return valor;

        if (x->six) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->six, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->six, valor);
            }
        }
        else
            return valor;

        if (x->seven) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->seven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->seven, valor);
            }
        }
        else
            return valor;

        if (x->eight) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->eight, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->eight, valor);
            }
        }
        else
            return valor;

        if (x->nine) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->nine, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->nine, valor);
            }
        }
        else
            return valor;

        if (x->ten) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->ten, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->ten, valor);
            }
        }
        else
            return valor;

        if (x->eleven) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->eleven, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->eleven, valor);
            }
        }
        else
            return valor;

        if (x->twelve) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->twelve, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->twelve, valor);
            }
        }
        else
            return valor;

        if (x->thirt) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->thirt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->thirt, valor);
            }
        }
        else
            return valor;

        if (x->fourt) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->fourt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->fourt, valor);
            }
        }
        else
            return valor;

        if (x->fift) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->fift, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->fift, valor);
            }
        }
        else
            return valor;

        if (x->sixt) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->sixt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->sixt, valor);
            }
        }
        else
            return valor;

        if (x->sevent) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->sevent, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->sevent, valor);
            }
        }
        else
            return valor;

        if (x->eightt) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->eightt, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->eightt, valor);
            }
        }
        else
            return valor;

        if (x->ninet) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->ninet, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->ninet, valor);
            }
        }
        else
            return valor;

        if (x->twenty) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->twenty, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->twenty, valor);
            }
        }
        else
            return valor;

        if (x->tone) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->tone, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->tone, valor);
            }
        }
        else
            return valor;

        if (x->ttwo) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->ttwo, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->ttwo, valor);
            }
        }
        else
            return valor;

        if (x->tthree) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->tthree, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->tthree, valor);
            }
        }
        else
            return valor;

        if (x->tfour) {
            x->estado = score(e);
            if (letra_bot == 'X') {
                valor = e.score[0];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->tfour, valor);
            }
            else {
                valor = e.score[1];
                valor = aux_MINmax(e, nivel, letra_bot, letra_bot, letra_adversario, x->tfour, valor);
            }
        }
        else
            return valor;

    }
}

*/
 /*
( Initial call )
minimax(raiz, nivel, letra_do_bot)

*/

// percorre os 24 nodos de jogadas possíveis

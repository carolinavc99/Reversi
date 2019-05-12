//
// Created by carolinavc on 4/21/19.
//

#ifndef PROJ_BOT_H
#define PROJ_BOT_H

ESTADO bot (ESTADO e);

typedef struct famJog {
    ESTADO estado;
    int nivel;
    // jogada que ele contém
    int linha;
    int coluna;

    struct famJog *one;
    struct famJog *two;
    struct famJog *three;
    struct famJog *four;
    struct famJog *five;
    struct famJog *six;
    struct famJog *seven;
    struct famJog *eight;
    struct famJog *nine;
    struct famJog *ten;
    struct famJog *eleven;
    struct famJog *twelve;
    struct famJog *thirt;
    struct famJog *fourt;
    struct famJog *fift;
    struct famJog *sixt;
    struct famJog *sevent;
    struct famJog *eightt;
    struct famJog *ninet;
    struct famJog *twenty;
    struct famJog *tone;
    struct famJog *ttwo;
    struct famJog *tthree;
    struct famJog *tfour;
} *PARENTE;

VALOR opp (VALOR peca);
ESTADO jogadaFilho (ESTADO e, PARENTE x)

int aux_minMAX (ESTADO e, PARENTE x, int valor);
int aux_MINmax (ESTADO e, PARENTE x, int valor);

int minmax(ESTADO e, int nivel, PARENTE x);

PARENTE jogTree(ESTADO e, PONTO posicao, int altura);

#endif //PROJ_BOT_H

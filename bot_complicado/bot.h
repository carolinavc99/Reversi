//
// Created by carolinavc on 4/21/19.
//

#ifndef PROJ_BOT_H
#define PROJ_BOT_H

ESTADO bot (int n, ESTADO e, char letra);

int minmax(ESTADO e, int nivel, char letra);

typedef struct famJog {
    ESTADO estado;
    int nivel;
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

#endif //PROJ_BOT_H

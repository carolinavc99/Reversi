#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "interpretador.h"
#include "estado.h"

#define PROMPT "Meu Reversi"


void printPrompt (ESTADO e){
    switch (e.peca){
        case VALOR_X :
            printf ("%s X >", PROMPT);
            break;
        case VALOR_O :
            printf ("%s O >", PROMPT);
            break;
        default:
            printf ("%s ? >", PROMPT);
    }
}


ESTADO interpretar (char *linha, ESTADO e){
    int n;
    char cmd [MAX_BUFFER];
    char peca[MAX_BUFFER];

    n = scanf(linha,"%s", cmd);
    switch (toupper(cmd[0])){
        case 'N' :
            n = sscanf(linha, "%s %s", cmd, peca);
            switch (toupper(peca[0])){
                case 'X' :
                    e = novo_jogo(e,VALOR_X);
                    break;
                case 'O' :
                    e = novo_jogo(e, VALOR_O);
                    break;
                default:
                    printf ("Peça inválida!! \n");
            }
            e = novo_jogo(e,VALOR_X);
            printa(e);
            break;
        case 'L' :
            break;
        case 'E' :
            break;
        case 'J' :
            break;
        case 'S' :
            break;
        case 'H' :
            break;
        case 'U' :
            break;
        case 'A' :
            break;
        case 'Q' :
            exit(0);
        default:
            printf ("Comado inválido. Por favor reveja as regras!! \n");
    }

    return e;
}


void interpretador (ESTADO e) {
    char linha [MAX_BUFFER];
    printPrompt(e);
    while (fgets(linha,MAX_BUFFER,stdin)){
        e=interpretar(linha, e);
        printa(e);
        printPrompt(e);
    }
}
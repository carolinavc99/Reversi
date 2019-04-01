#include "comandos.h"
#include <stdio.h>

ESTADO novoJogo (ESTADO e, VALOR peca) {

    int opcao = 0;

    e.modo = '0';
    e.peca = peca;

    printa(e);

    return e;

}

ESTADO jogar (ESTADO e, int linha, int coluna) {
    return e;
}
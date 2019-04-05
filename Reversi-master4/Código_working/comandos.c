#include "comandos.h"
#include <string.h>
#include <stdio.h>

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


ESTADO novoJogo (ESTADO e, VALOR peca) {
    char nome[20];
    char conteudo[300]; // o que vai estar escrito no ficheiro
    char c;
    FILE *fp;

    printf("Introduza o nome do ficheiro: ");
    scanf("%s", nome);
    getchar(); // retira o enter final que estava a dar problemas

    strcat(nome, ".txt");
    printf("\nEstá agora a jogar em: %s\n", nome);

    strcpy(e.nome, nome); // coloca no estado o nome do ficheiro

    e.modo = '0';
    e.peca = peca;

    // escrever o estado no ficheiro
    strcpy (conteudo, "M ");

    if (peca == VALOR_X)
        strcat (conteudo, "X\n");
    else
        strcat (conteudo, "O\n");


    for (int i = 0; i < 8; i++) { // linha a linha
        for (int j = 0; j < 8; j++) { // elemento a elemento
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    strcat (conteudo, "O");
                    break;
                }
                case VALOR_X: {
                    strcat (conteudo, "X");
                    break;
                }
                case VAZIA: {
                    strcat (conteudo, "-");
                    break;
                }
            }
            strcat (conteudo, " ");
        }
        strcat (conteudo, "\n");
    }

    fp = fopen(nome, "w"); // 'w' permite re-escrever o conteúdo do ficheiro, 'w+' não alterava
    rewind(fp); // just to be safe, embora seja desnecessário
    fprintf(fp, "%s", conteudo);
    fclose(fp);

    printa(e);

    return e;

}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


/*
 * Verifica se existe uma peça igual à que está a jogar na posição (l,c) ou no caminho
 * obtido adicionando dl e dc a (l,c).
 */

int verificaLinha (ESTADO e, int dl, int dc, int linha, int coluna) {

    if(e.grelha[linha][coluna] == e.peca) return 0;

    if( (linha + dl < 0) || (linha + dl > 7)) return 1;

    if( (coluna + dc < 0) || (coluna + dc > 7)) return 1;

    return verificaLinha (e, dl, dc, linha+dl, coluna+dc);

}

/*
 * Verifica se a posição linha,coluna contém a peça oposta à que está a efetuar a jogada
 * e se o caminho resultante de adicionar dl a linha e dc a coluna eventualmente acaba na
 * peça que está a jogar.
 */

int jogadaValida (ESTADO e, int dl, int dc, int linha, int coluna) {

    VALOR outro = VAZIA;

    if(e.peca == VALOR_X) outro = VALOR_O;

    else {

        if(e.peca == VALOR_O) outro = VALOR_X;

    }

    if( (linha + dl < 0) || (linha + dl > 7) ) return 1;

    if( (coluna + dc < 0) || (coluna + dc > 7) ) return 1;

    if(e.grelha[linha+dl][coluna+dc] != outro) return 1;

    if( (linha + dl + dl < 0) || (linha + dl + dl > 7) ) return 1;

    if( (coluna + dc + dc < 0) || (coluna + dc + dc> 7) ) return 1;


    return verificaLinha (e, dl, dc, (linha+dl+dl), (coluna+dc+dc));


}


ESTADO calcJogadasValidas (ESTADO e) {

    ESTADO v = {0};
    int no, nn, ne, oo, ee, so, ss, se; // coordenadas

    for(int linha = 0; linha < 8; linha++) {

        for(int coluna = 0; coluna < 8; coluna++) {

            if(e.grelha[linha][coluna] == VAZIA) {

                no = jogadaValida(e, -1, -1, linha, coluna);
                nn = jogadaValida(e, -1,  0, linha, coluna);
                ne = jogadaValida(e, -1,  1, linha, coluna);

                oo = jogadaValida(e,  0, -1, linha, coluna);
                ee = jogadaValida(e,  0,  1, linha, coluna);

                so = jogadaValida(e,  1, -1, linha, coluna);
                ss = jogadaValida(e,  1,  0, linha, coluna);
                se = jogadaValida(e,  1,  1, linha, coluna);

                if(no == 0 || nn == 0 || ne == 0 || oo == 0|| ee == 0|| so == 0|| ss == 0 || se == 0) {
                    v.grelha [linha][coluna] = e.peca;
                }
            }


        }

    }

    return v;

}


/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


/*
 * Indica as coordenadas das posições válidas.
 */

void posicoesValidas (ESTADO e, ESTADO v) {

    for(int linha = 0; linha < 8; linha++) {

        for (int coluna = 0; coluna < 8; coluna++) {

            if (v.grelha[linha][coluna] == e.peca) e.grelha[linha][coluna] = VALOR_V;

        }

    }

    printa(e);

}


/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


/*
 * Valida jogada.
 */

int validarJogada (ESTADO e, int linha, int coluna) {

    ESTADO v;
    int r=1;

    // Transforma os códigos char referentes à linha e à coluna nos inteiros referentes à linha e à coluna.
    linha = linha - 48;
    coluna = coluna - 48;

    v = calcJogadasValidas (e);

    if(v.grelha[linha-1][coluna-1]==e.peca) r=0;

    return r;

}

/*
int verifica (ESTADO e, int linha, int coluna, int dl, int dc) {

    VALOR outro;
    int r = 0;

    if (e.peca == VALOR_X) outro = VALOR_O;
    else outro = VALOR_X;

    if (e.grelha[linha + dl][coluna + dc] == outro) r = 1 + verifica(e, linha, coluna, dl + dl, dc + dc);
    else { if (e.grelha[linha + dl][coluna + dc] == VAZIA) r = 0; }

    return r;

}
*/

/*
 * Coloca uma peça no tabuleiro na posição (linha,coluna) se a jogada for válida.
 */

ESTADO jogar (ESTADO e, int linha, int coluna) {

    // Transforma os códigos char referentes à linha e à coluna nos inteiros referentes à linha e à coluna.
    linha = linha - 48;
    coluna = coluna - 48;

    //Coloca a peça no tabuleiro.
    if(e.peca == VALOR_O) e.grelha[linha-1][coluna-1] = VALOR_O;
    else {e.grelha[linha-1][coluna-1] = VALOR_X;}

    //Transforma as peças encurraladas.
    //transformaEstado (e, linha, coluna);

    //Altera o jogador no Estado.
    if(e.peca == VALOR_O) e.peca = VALOR_X;
    else {e.peca = VALOR_O;}

    //Atualiza o score.
    e = score(e);

    //Imprime estado modificado.
    printa(e);

    return e;
}


/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

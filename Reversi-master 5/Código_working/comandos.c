#include "comandos.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>

ESTADO novoJogo (VALOR peca) {
    ESTADO e = {0};

    e.modo = '0';
    e.peca = peca;
    strcpy(e.nome, ".");
    e.score [0] = 2;
    e.score [1] = 2;

    // teste
    printf("nome: %s", e.nome);

    // estado inicial do tabuleiro
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    printf("\n\n#### Novo Jogo ####\n");
    printa(e);

    return e;
}


ESTADO continuaJogo (ESTADO e, char nome[]) {
    FILE *fp;
    char l[20];


    for (int j=0; nome[j]; j++) {
        if (nome[j] == '.') {
            printf("Nome inválido.");
            return e;
        }
    }
    strcat(nome, ".txt");

    strcpy(e.nome, nome);

    fp = fopen(nome, "r+");

    if(fp == NULL)

        printf("Jogo inexistente.");

    else {

        fscanf(fp, "%s", l);
        printf("\n%s\n", l);

        if(l[0] == 'M') e.modo = '0';
        else e.modo = '1';

        if(l[1] == 'X') e.peca = VALOR_X;
        else e.peca = VALOR_O;

        for(int i=0; i<8; i++) {              // percorre as linhas

            fscanf(fp, "%s", l);
            printf("%s\n", l);

            for (int j=0; j<8; j++) {         // percorre as colunas

                switch(l[j]) {

                    case 'X':
                        e.grelha[i][j] = VALOR_X;
                        break;

                    case 'O':
                        e.grelha[i][j] = VALOR_O;
                        break;

                    default:
                        e.grelha[i][j] = VAZIA;
                        break;

                }

            }
        }

    }

    fclose(fp);
    printa (e);
    return e;
}

void guardar (ESTADO e, char nome[]) {
    char conteudo[300]; // o que vai estar escrito no ficheiro
    FILE *fp;

    for (int j=0; nome[j]; j++) {
        if (nome[j] == '.') {           // se o nome do ficheiro conter um ponto é inválido
            printf("\nO nome não pode conter '.'\n");   // NOTA: '.' é o caso base de nome para um jogo que nunca foi guardado
            return;
        }
    }

    // adiciona a extensão
    strcat(nome, ".txt");

    // coloca no estado o nome.txt
    strcpy(e.nome, nome);


    // escrever o estado no ficheiro
    if (e.modo == '0')
        strcpy (conteudo, "M");
    else
        strcpy (conteudo, "A");

    if (e.peca == VALOR_X)
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
            //strcat (conteudo, " ");
        }
        strcat (conteudo, "\n");
    }

    fp = fopen(nome, "w");       // 'w' permite re-escrever o conteúdo do ficheiro ('w+' não alterava se o ficheiro já existisse)
    rewind(fp);                  // probs desnecessário
    fprintf(fp, "%s", conteudo); // imprime estado no ficheiro
    fclose(fp);

    printf("\nJogo guardado em: %s\n", nome);
    printa(e);

}


/*
    pop
    a undo não estava a conseguir verificar se já tinha chegado ao final da lista de jogadas, por isso,
    na função undo do menu, mandei verificar se já estava no estado inicial em vez de o fazer aqui
 */
ESTADO undo (ESTADO e) {
    if (e.score[0] == 2 && e.score[1] == 2)
        printf("\nNão há mais jogadas para desfazer.\n");
    else {
        pop();
        e = topo->tabuleiro;
    }
    printa(e);

    return e;
}

// push personalizada para verificar jogadas
void novaJogada (ESTADO e, int linha, int coluna) {
    // verificar se a jogada é válida
    if (validarJogada(e, linha, coluna) != 1)
        printf("\nA jogada não é válida.\n");
    else
        push(e);
}

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
    else
        if(e.peca == VALOR_O) outro = VALOR_X;


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

                if (no == 0 || nn == 0 || ne == 0 || oo == 0|| ee == 0|| so == 0|| ss == 0 || se == 0)
                    v.grelha [linha][coluna] = e.peca;
            }
        }
    }
    return v;
}

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
 * Verifica se existe uma peça do jogador que está a jogar numa dada direção.
 * Caso exista, devolve o número de peças do adversário encurraladas nessa direção.
 * Caso contrário, retorna o valor 0.
 */
int verificaPeca (ESTADO e, int linha, int coluna, int dl, int dc, VALOR outro, int i) {

    if (linha < 8 && coluna < 8 && coluna >= 0 && linha >= 0) {

        if (e.grelha[linha][coluna] == outro) {

            i++;
            i = verificaPeca(e, linha + dl, coluna + dc, dl, dc, outro, i);

        }

        else {

            if (e.grelha[linha][coluna] == VAZIA) i = 0;


        }

    }

    else i = 0;

    return i;

}


/*
 * Transforma as peças do adversário encurraladas em peças do jogador que está a jogar.
 */
ESTADO transformaPecas (ESTADO e, int linha, int coluna, int dl, int dc) {

    VALOR outro;
    int j,k;

    if (e.peca == VALOR_X) outro = VALOR_O;
    else outro = VALOR_X;

    linha = linha + dl;
    coluna = coluna + dc;

    k = verificaPeca(e,linha,coluna,dl,dc,outro,0);

    if (k!=0) {

        for (j = 0; j < k; j++) {

            e.grelha[linha][coluna] = e.peca;
            linha = linha + dl;
            coluna = coluna + dc;

        }
    }

    return e;

}


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
    e = transformaPecas (e, linha-1, coluna-1, -1, -1);
    e = transformaPecas (e, linha-1, coluna-1, -1,  0);
    e = transformaPecas (e, linha-1, coluna-1, -1,  1);

    e = transformaPecas (e, linha-1, coluna-1,  0, -1);
    e = transformaPecas (e, linha-1, coluna-1,  0,  1);

    e = transformaPecas (e, linha-1, coluna-1,  1, -1);
    e = transformaPecas (e, linha-1, coluna-1,  1,  0);
    e = transformaPecas (e, linha-1, coluna-1,  1,  1);

    //Altera o jogador no Estado.
    if(e.peca == VALOR_O) e.peca = VALOR_X;
    else {e.peca = VALOR_O;}

    //Imprime estado modificado.
    printa(e);

    return e;
}

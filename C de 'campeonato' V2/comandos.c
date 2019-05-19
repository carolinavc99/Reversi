#include "comandos.h"
#include "bot.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Começa um novo jogo.
 * @param peca Primeiro jogador a efetuar jogada.
 * @return Estado com o tabuleiro inicial.
 */
ESTADO novoJogo (VALOR peca, char modo, char dificuldade) {
    ESTADO e = {0};

    if(modo == 'M') {
        e.modo = '0';
        e.peca = peca;
        e.bot = VAZIA;
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

        printf("\n\n====> Novo Jogo <====\n");
        printa(e);

    }
    else {
        e.peca = peca;
        e.modo = dificuldade;
        strcpy(e.nome, ".");
        e.score [0] = 2;
        e.score [1] = 2;

        // estado inicial do tabuleiro
        e.grelha[3][4] = VALOR_X;
        e.grelha[4][3] = VALOR_X;
        e.grelha[3][3] = VALOR_O;
        e.grelha[4][4] = VALOR_O;

        printf("\n\n====> Novo Jogo contra Bot de Nível %c <====\n", dificuldade);
        printa(e);
    }
    return e;
}

/**
 * Converte um char num valor.
 * @param c Char a ser convertido.
 * @return Valor correspondente ao char dado.
 */
VALOR chartovalor(char c) {
    switch(c) {
        case 'X': return  VALOR_X;
        case 'O': return  VALOR_O;
    }
    return VAZIA;
}

/**
 * Converte um valor num char.
 * @param v Valor a ser convertido.
 * @return Char corresopondente ao valor dado.
 */
char valortochar (VALOR v) {
    switch(v) {
        case VALOR_O: return 'O';
        case VALOR_X: return 'X';
    }
}

/**
 * Continua um jogo guardado num ficheiro.
 * @param e Estado anterior.
 * @param nome Nome do ficheiro onde o jogo está guardado.
 * @return Estado com o jogo continuado.
 */
ESTADO continuaJogo (ESTADO e, char nome[]) {  // nome é sem extensão, nome2 é COM extensão
    FILE *fp;
    char l[20], mj[20];
    char x;


    for (int j=0; nome[j]; j++) {
        if (nome[j] == '.') {
            printf("Nome inválido.");
            return e;
        }
    }

    // tentar abrir o ficheiro
    fp = fopen(nome, "r+");

    // não existe o ficheiro pedido E não existe ficheiro atual
    if ((fp == NULL) && (e.modo == ' ' && e.peca == VAZIA)) {
        printf("Jogo inexistente.\n"
               "Por favor começe um jogo novo ou continue um jogo existente.\n");
        return e;

    }
    // não existe ficheiro pedido mas existe ficheiro atual => printa o atual
    else if (fp == NULL) {
        printf("\nJogo inexistente.\n");
        printa(e);
        return e;
    }
    // existe ficheiro pedido (e existe atual)
    else {

        // coloca o nome do ficheiro no estado
        strcpy(e.nome, nome);

        fgets(mj, 100, fp);

        if (mj[0] == 'M') e.modo = '0';
        else {
            switch(mj[4]){
                case '1': e.modo = '1'; break;
                case '2': e.modo = '2'; break;
                case '3': e.modo = '3'; break;
            }
            if(mj[2] == 'X') e.bot = VALOR_O;
            else e.bot = VALOR_X;
        }

        if (mj[2] == 'X') e.peca = VALOR_X;
        else e.peca = VALOR_O;

        for(int i=0; i<8; i++) {

            x=0;

            fgets(l, 20, fp);

            for(int j=0; j<15; j=j+2) {

                e.grelha[i][x] = chartovalor(l[j]);
                x++;

            }
        }
        fclose(fp);
    }

    printa (e);
    return e;
}

/**
 * Guarda o jogo num ficheiro.
 * @param e Estado com o jogo a ser guardado.
 * @param nome Nome do ficheiro no qual o jogo vai ser guardado.
 */
void guardar (ESTADO e, char nome[]) { // nome é sem extensão, nome2 é COM extensão
    char conteudo[300]; // o que vai estar escrito no ficheiro
    FILE *fp;

    for (int j=0; nome[j]; j++) {
        if (nome[j] == '.') {           // se o nome do ficheiro conter um ponto é inválido
            printf("\nO nome não pode conter '.'\n");   // NOTA: '.' é o caso base de nome para um jogo que nunca foi guardado
            return;
        }
    }

    // coloca no estado o nome
    strcpy(e.nome, nome);

    // adiciona a extensão
    //strcpy(nome2, nome);
    //strcat(nome2, ".txt");

    // escrever o estado no ficheiro
    if (e.modo == '0')
        strcpy (conteudo, "M ");
    else
        strcpy (conteudo, "A ");

    if (e.peca == VALOR_X)
        strcat (conteudo, "X ");
    else
        strcat (conteudo, "O ");

    switch (e.modo) {
        case '1': strcat (conteudo, "1\n"); break;
        case '2': strcat (conteudo, "2\n"); break;
        case '3': strcat (conteudo, "3\n"); break;
    }


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

    fp = fopen(nome, "w");       // 'w' permite re-escrever o conteúdo do ficheiro ('w+' não alterava se o ficheiro já existisse)
    rewind(fp);                   // probs desnecessário
    fprintf(fp, "%s", conteudo);  // imprime estado no ficheiro
    fclose(fp);

    printf("\nJogo guardado em: %s\n", nome);
    printa(e);

}

/**
 * Retrocede uma jogada.
 * @param e Estado atual.
 * @param topo Última jogada efetuada.
 * @return Penúltima jogada efetuada.
 */
struct JOGADA* undo (ESTADO* e, struct JOGADA* topo) {
    topo = pop(topo);
    *e = topo->tabuleiro;

    printa(*e);

    return(topo);
}

// push personalizada para verificar jogadas
// devolve o número atualizado de jogadas efetuadas
/**
 * Adiciona a jogada efetuada ao topo da stack.
 * @param e Estado atual.
 * @param linha Linha onde o jogador efetuou a jogada.
 * @param coluna Coluna onde o jogador efetuou a jogada.
 * @param topo Última jogada efetuada.
 * @return Jogada acrescentada ao topo da stack.
 */
struct JOGADA* novaJogada (ESTADO e, int linha, int coluna, struct JOGADA * topo) {
    // verificar se a jogada é válida
    if (validarJogada(e, linha, coluna) != 1)
        printf("\nA jogada não é válida.\n");
    else {
        e = score(e);
        topo = push(e, topo);
    }
    return topo;
}

/**
 * Verifica se existe uma peça igual à que está a jogar na posição (l,c) ou no caminho obtido adicionando dl e dc a (l,c).
 * @param e Estado atual.
 * @param dl Valor a adicionar à linha para percorrer a direção desejada.
 * @param dc Valor a adicionar à coluna para percorrer a direção desejada.
 * @param linha Linha da posição a ser analisada.
 * @param coluna Coluna da posição a ser analisada.
 * @return Caso exista, retorna 1. Caso contrário, retorna 0.
 */
int verificaLinha (ESTADO e, int dl, int dc, int linha, int coluna) {

    if(e.grelha[linha][coluna] == e.peca) return 0;

    if(e.grelha[linha][coluna] == VAZIA) return 1;

    if( (linha + dl < 0) || (linha + dl > 7)) return 1;

    if( (coluna + dc < 0) || (coluna + dc > 7)) return 1;

    return verificaLinha (e, dl, dc, linha+dl, coluna+dc);
}

/**
 * Verifica se a posição (linha,coluna) contém a peça oposta à que está a efetuar a jogada
 * e se o caminho resultante de adicionar dl a linha e dc a coluna eventualmente acaba na
 * peça que está a jogar.
 * @param e Estado atual.
 * @param dl Valor a adicionar à linha para percorrer a direção desejada.
 * @param dc Valor a adicionar à coluna para percorrer a direção desejada.
 * @param linha Linha da posição a ser analisada.
 * @param coluna Coluna da posição a ser analisada.
 * @return Caso exista, retorna 1. Caso contrário, retorna 0.
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

/**
 * Calcula as jogadas válidas.
 * @param e Estado atual.
 * @return Estado com as posições válidas assinaladas pela peça referente ao jogador que vai efetuar a jogada.
 */
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

/**
 * Imprime o estado atual com pontos nas posições válidas.
 * @param e Estado atual.
 * @param v Estado com as posições válidas assinaladas pela peça referente ao jogador que vai efetuar a jogada.
 */
void posicoesValidas (ESTADO e, ESTADO v) {

    for(int linha = 0; linha < 8; linha++) {

        for (int coluna = 0; coluna < 8; coluna++) {

            if (v.grelha[linha][coluna] == e.peca) e.grelha[linha][coluna] = VALOR_V;

        }
    }
    printa(e);
}

/**
 * Valida uma jogada.
 * @param e Estado atual.
 * @param linha Linha onde o jogador pretende efetuar a jogada.
 * @param coluna Coluna onde o jogador pretende efetuar a jogada.
 * @return Caso a jogada seja válida, retorna 1. Caso contrário, retorna 0.
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

/**
 * Verifica se existe uma peça do jogador que está a jogar numa dada direção.
 * @param e Estado atual.
 * @param linha Linha onde o jogador efetuou a jogada.
 * @param coluna Coluna onde o jogador efetuou a jogada.
 * @param dl Valor a adicionar à linha para percorrer a direção desejada.
 * @param dc Valor a adicionar à coluna para percorrer a direção desejada.
 * @param outro Peça do adversário.
 * @param i Contador do número de peças encurraladas.
 * @return Número de peças do adversário encurraladas nessa direção. Caso não existam retorna o valor 0.
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

/**
 * Transforma as peças do adversário encurraladas em peças do jogador que está a jogar.
 * @param e Estado atual.
 * @param linha Linha onde o jogador efetuou a jogada.
 * @param coluna Coluna onde o jogador efetuou a jogada.
 * @param dl Valor a adicionar à linha para percorrer a direção desejada.
 * @param dc Valor a adicionar à coluna para percorrer a direção desejada.
 * @return Retorna o estado com as peças encurraladas modificadas.
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

/**
 * Verifica se o jogador que vai jogar tem de passar a jogada.
 * @param e Estado atual.
 * @param p Jogador que vai jogar.
 * @return Valor 1 se tiver de passar a jogada. Caso contrário, retorna o valor 0.
 */
int passaJogada (ESTADO e, VALOR p) {

    ESTADO v;

    e.peca = p;                              // >>>> ACRESCENTEI LINHA <<<<
    v = calcJogadasValidas(e);

    for(int i=0; i<8; i++) {

        for(int j=0; j<8; j++) {

            if(v.grelha[i][j] == p) return 0;

        }
    }

    return 1;

}

/**
 * Finaliza um jogo.
 * @param e Estado atual.
 * @return Estado vazio.
 */
ESTADO fimJogo(ESTADO e) {

    char vencedor;

    if(e.score[0] > e.score[1]) vencedor = 'X';
    else {
        if(e.score[0] == e.score[1]) vencedor = ' ';
        else vencedor = 'O';
    }

    if(vencedor != ' ') printf("\n ========> FIM DO JOGO <======== \n"
                               "\n           Vencedor: %c          \n"
                               "\n           Pontuações:           \n"
                                 "             X -> %d             \n"
                                 "             O -> %d             \n", vencedor, e.score[0], e.score[1]);

    else printf("\n ========> FIM DO JOGO <======== \n"
                "\n             Empate              \n"
                "\n           Pontuações:           \n"
                  "             X -> %d             \n"
                  "             O -> %d             \n", e.score[0], e.score[1]);

    e.modo = ' ';
    e.peca = VAZIA;
    e.score [0] = 2;
    e.score [1] = 2;
    strcpy(e.nome, ".");

    return e;
}

/**
 * Coloca uma peça no tabuleiro na posição (linha,coluna).
 * @param e Estado atual.
 * @param linha Linha onde o jogador pretende efetuar a jogada.
 * @param coluna Coluna onde o jogador pretende efetuar a jogada.
 * @return Estado após a colocação da peça no tabuleiro.
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
    else e.peca = VALOR_O;

    //Imprime estado modificado.
    printa(e);

    VALOR outro = VAZIA;

    e = score(e);

    if (e.peca == VALOR_X) outro = VALOR_O;
    else if (e.peca == VALOR_O) outro = VALOR_X;


    if(passaJogada(e, e.peca)==1){
        if (passaJogada(e, outro)==1) e = fimJogo(e);
        else {
            printf("\nJogadas indisponíveis para o jogador %c.\nPassou jogada.\n", valortochar(e.peca));
            e.peca = outro;
            if(e.modo=='1' || e.modo=='2' || e.modo=='3') {
                if(e.peca == e.bot) {
                    printf("\n\n====> Jogada do Bot <====\n");
                    e = bot(e);
                }

            }
        }
    }

    return (e);
}

/**
 * Preenche um array com as coordenadas das jogadas válidas de um estado.
 * @param e Estado a analisar.
 * @param validas Array a ser preenchido com as coordenadas das jogadas válidas do estado dado.
 * @return Número de posições preenchidas do array.
 */
int arrayValidas (ESTADO e, PONTO validas[]) {

    ESTADO v;
    int i = 0;

    v = calcJogadasValidas(e);
    //TESTE
    //printa(v);

    //Preenche o array
    for(int a=0; a<8; a++) {
        for(int b=0; b<8; b++) {
            if(v.grelha[a][b]==e.peca) {
                validas[i].l = a+1;
                validas[i].c = b+1;
                i++;
            }
        }
    }

    //TESTE
    /*
    for(int k=0; k<i; k++) {
        printf("(%d,%d)", validas[k].l, validas[k].c);
    }
    printf("\n");

    //TESTE
    printf("Tamanho do array: %d\n", i);

    */

    return i;

}

/**
 * Sugere uma jogada imprimindo no estado um '?' na posição da mesma.
 * @param e Estado atual.
 */
void sugestao (ESTADO e) {

    PONTO validas[50];
    int pr, pp; //Posição random e posições preenchidas

    pp = arrayValidas (e,validas);

    //Escolhe um indice do array (random)
    //rand gera números de 0 ao tamanho do array menos 1
    if(pp==1) pr = 0;
    else pr = (rand()>RAND_MAX/(pp-1));

    //Indica as coordenadas guardadas no indice do array escolhido
    printf("Posição random: (%d,%d)\n", validas[pr].l, validas[pr].c);

    e.grelha[validas[pr].l-1][validas[pr].c-1] = VALOR_S;

    printa(e);

}
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#define TAM 20
/*
como jogar
clique em um quadrado ara ver quantas minas estao ao redor dele. ara vencer,
vire todos o quadraados sem revelar uma mina.
o camo minado e um teste de memoria e raciocinio aarentemente simles. e um dos
jogos do windows mais oulares de todos os temos. o objetivo e encontrar os
quadrados vazios e evitar as minas.

regras e nooes basicas
objetivo
encontrar os quadrados vazios e evitar as minas. quanto mais raido voce
esvaziar o tabuleiro, melhor sera a sua ontuaao.
tabuleiro
o camo minado ossui tres ooes de tabuleiros, cada um deles rogressivamente
mais dificil que o outro.
iniciante 81 quadrados e 10 minas
intermediario 256 quadrados e 40 minas
avanado 480 quadrados e 99 minas
tambem e ossivel criar um tabuleiro ersonalizado clicando no menu jogo e em
ooes. o camo minado ermite tabuleiros com ate 720 quadrados e 668 minas.

Como jogar
As regras do Campo Minado s�o simples:

Se voc� descobrir uma mina, o jogo acaba.

Se descobrir um quadrado vazio, voc� continua jogando.

Se parecer um n�mero, ele informar� quantas minas est�o escondidas nos oito
quadrados que o cercam. Voc� usa essa informa��o para deduzir em que quadrados
pr�ximos � seguro clicar.

Sugest�es e dicas
Marque as minas. Se voc� suspeita que um quadrado cont�m uma mina, clique nele
com o bot�o direito do mouse.Isso marca o quadrado com uma bandeira.(Se n�o
tiver certeza, clique com o bot�o direito do mouse novamente para inserir um
ponto de interroga��o.)

Estude os padr�es. Se tr�s quadrados seguidos exibirem os n�meros 2, 3 e 2,
provavelmente haver� tr�s minas alinhadas ao lado desses n�meros.Se um quadrado
mostrar o n�mero 8, todos os quadrados que o circundam estar�o minados.

Explore o desconhecido. N�o sabe onde clicar em seguida?Tente esvaziar algum
territ�rio inexplorado.� melhor clicar no meio dos quadrados que n�o est�o
marcados do que em uma �rea que voc� suspeita estar minada.

*/
/**
** Desafios
** - Campo
** - CampoUsuario OK
** - PopularBombas
** - PreencherDicas
** - Navega��o
**/

void definirTamanhoCampo (int *ptamL, int *ptamC);
void limparCampoUsuario (char campoUsuario[TAM][TAM]);
void limparCampo (char campo[TAM][TAM]);
void imprimirCampoUsuario (char campoUsuario[TAM][TAM], int tamL, int tamC);
void definirNivelDoJogo (int *p_QtdBombas, int tamL, int tamC);
void lancarBombas(char campo[TAM][TAM], int qtdBombas, int tamL, int tamC);
void lancarNumeros(char campo[TAM][TAM], int tamL, int tamC);
int jogar (int tamL, int tamC, int qtdBombas, char campoUsuario[TAM][TAM], char campo[TAM][TAM]);

int aula_08()
{
    char campo[TAM][TAM];
    char campoUsuario[TAM][TAM];
    int tamL, tamC;
    int qtdBombas;

    // Definir a matriz "campoUsuario"
    definirTamanhoCampo(&tamL, &tamC);

    // Definir Nivel do Jogo
    definirNivelDoJogo(&qtdBombas, tamL, tamC);
    printf("\nQuantidade de Bombas: %d\n", qtdBombas);
    system("pause");

    // Limpar e configurar a matriz "campoUsuario"
    limparCampoUsuario(campoUsuario);
    imprimirCampoUsuario(campoUsuario, tamL, tamC);

    // Limpar e configurar a matriz "campo" - DEBUG
    limparCampo(campo);
    imprimirCampoUsuario(campo, tamL, tamC);

    // Lan�ar bombas
    lancarBombas(campo, qtdBombas, tamL, tamC);
    imprimirCampoUsuario(campo, tamL, tamC);

    printf("\n*** QTD BOMBAS: %d***\n\n", qtdBombas);

    printf("\n*** antes debug ***\n\n");
    lancarNumeros(campo,tamL, tamC);
    printf("\n*** depois debug ***\n\n");

    imprimirCampoUsuario(campo, tamL, tamC);

    jogar(tamL, tamC, qtdBombas, campoUsuario, campo);

    system("pause");
    return 0;
}
void definirTamanhoCampo (int *ptamL, int *ptamC)
{
    printf("\n*** BEMVINDO AO CAMPO MINADO ***\n\n");

    do {
        printf("\nDigite a qtd de linhas do campo minado: ");
        scanf("%d", ptamL);

        printf("\nDigite a qtd de colunas do campo minado: ");
        scanf("%d", ptamC);

        if (*ptamL < 2 || *ptamL > TAM || *ptamC < 2 || *ptamC > TAM) {
            printf("\nDimens�es inv�lidas! Tente novamente... ");
            //getchar();
        }
    } while (*ptamL < 2 || *ptamL > TAM || *ptamC < 2 || *ptamC > TAM);
}
void limparCampoUsuario (char campoUsuario[TAM][TAM])
{
    int l, c;
    for (l=0; l<TAM; l++) {
        for (c=0; c<TAM; c++) {
            campoUsuario[l][c] = '-';
        }
    }
}
void limparCampo (char campo[TAM][TAM])
{
    int l, c;
    for (l=0; l<TAM; l++) {
        for (c=0; c<TAM; c++) {
            campo[l][c] = '0';
        }
    }
}
void imprimirCampoUsuario (char campoUsuario[TAM][TAM], int tamL, int tamC)
{
    int l, c;

    system("cls");
    printf("\n*** BEMVINDO AO CAMPO MINADO ***\n\n");

    for (c=0; c<tamC+1; c++ ) {
        if (c > 0) {
            printf("-"); // Imprimir cabe�alhos das colunas
        }
        printf(" %2d ", c); // Imprimir cabe�alhos das colunas
    }
    printf("\n");

    for (l=0; l<tamL; l++) {
        printf(" %2d  ", l+1); // Imprimir cabe�alhos das linhas
        for (c=0; c<tamC; c++) {
            printf("  %c  ", campoUsuario[l][c]);

            /*
            if (c % 2 == 0) {
                system("color 01");
            } else {
                system("color 0e");
            }
            */
        }
        printf("\n");
    }
}
void definirNivelDoJogo (int *p_QtdBombas, int tamL, int tamC)
{
    int opcao = 0;
    while (opcao < 1 || opcao > 3)
    {
        printf("\nEscolha o n�vel do seu jogo: ");
        printf("\n     1 - FACIL");
        printf("\n     2 - M�DIO");
        printf("\n     3 - DIF�CIL");
        printf("\nOp��o escolhida: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            *p_QtdBombas = round((tamL * tamC) * 0.15);
            break;
        case 2:
            *p_QtdBombas = round((tamL * tamC) * 0.5);
            break;
        case 3:
            *p_QtdBombas = round((tamL * tamC) * 0.75);
            break;

        default:
            printf("Op��o inv�lida! Tente novamente...");
            break;
        }
    }
}
void lancarBombas(char campo[TAM][TAM], int qtdBombas, int tamL, int tamC)
{
    int b;
    srand(time(NULL));
    int aleatL, aleatL_last;
    int aleatC, aleatC_last;

    for (b=0; b<qtdBombas; b++) {
        aleatL_last = aleatL;
        aleatC_last = aleatC;
        aleatL = rand() % tamL;
        aleatC = rand() % tamC;

        if (aleatC != aleatC_last && aleatL != aleatL_last){
            campo[aleatL][aleatC] = '*';
        } else {
            b--;
        }
    }
}

void lancarNumeros(char campo[TAM][TAM], int tamL, int tamC)
{
    int l, c, countBomba;


        for (l=0; l<tamL; l++) {
            for (c=0; c<tamC; c++) {

                if (campo[l][c] != '*') { // Se n�o for bomba
                    countBomba = 0;
                    //fazer o rel�gio
                    if (campo[l-1][c]   == '*' && (l-1>=0))                 { countBomba++; }
                    if (campo[l-1][c+1] == '*' && (l-1>=0) && (c+1<tamC))   { countBomba++; }
                    if (campo[l][c+1]   == '*' && (c+1<tamC))               { countBomba++; }
                    if (campo[l+1][c+1] == '*' && (l+1<tamL) && (c+1<tamC)) { countBomba++; }
                    if (campo[l+1][c]   == '*' && (l+1<tamL))               { countBomba++; }
                    if (campo[l+1][c-1] == '*' && (l+1<tamL) && (c-1>=0))   { countBomba++; }
                    if (campo[l][c-1]   == '*' && (c-1>=0))                 { countBomba++; }
                    if (campo[l-1][c-1] == '*' && (l-1>=0) && (c-1>=0))     { countBomba++; }
                    campo[l][c] = (char)(countBomba + 48);
                }
            }
        }
}

int jogar (int tamL, int tamC, int qtdBombas, char campoUsuario[TAM][TAM], char campo[TAM][TAM])
{
    int i, numJogadas, linha, coluna;

    numJogadas = (tamL * tamC) - qtdBombas;

    for (i=0; i<numJogadas; i++) {
        printf("\n\nEscolha a linha e a coluna que deseja jogar: ");
        scanf("%d %d", &linha, &coluna);

        if ((linha > 0 && linha <= tamL) && (coluna > 0 && coluna <= tamC)) {

            if (campoUsuario[linha-1][coluna-1] == '-') { // Se jogada v�lida (posi��o nunca foi jogada)
                if (campo[linha-1][coluna-1] == '*') { // Se tiver bomba --> GAME OVER
                    printf("\n\n GAME OVER!!! \n\n");
                    return 0;
                } else { // Se n�o tiver bomba --> Marca n�mero
                    campoUsuario[linha-1][coluna-1] = campo[linha-1][coluna-1];
                }
            } else {
                printf("\n\nJogada j� realizada! Tenta novamente... \n\n");
                i--;
            }

        } else {
            printf("\n\nJogada j� realizada! Tenta novamente... \n\n");
            i--;
        }
        imprimirCampoUsuario(campoUsuario, tamL, tamC);
    }
    printf("\n\n PARAB�NS!!! VOC� GANHOU A PARTIDA!!!\n\n");
    return 1;
}

/** @file batalha_naval.c @brief Arquivo do jogo Batalha Naval. */
/*
* Documento de especificações:
* C:\Suporte\Documentos\Google Drive\Fatec\Programação 2\Projetos\atividades\docs\Especificações do Jogo.docx
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <dos.h>

/*
* Registros
*/
struct embarcacoes
{
    char nome[15];
    int colocados[2];
    int tamanho;
    int quantidade;
};

struct
{
    char navios[1][10][44];
    char ataques[1][10][44];
} campo;

struct jogadores
{
    int jogador_id;
    char nome[15];
    int naviosDisponiveis;
    int blocosOcupados;
    int blocosRestantes;
};

struct tabuleiro
{
    //talvez não precise deste registro
};

struct infos
{
    char titulo[30];
    char tela[15];
    char status[30];
    char linha[25][80];
    int selecionado;
} info;

/*
* Constantes
*/
#define MIRA "<+>"
#define CMAR '~'
#define TIRO 'o'
#define NAVIO '#'
#define ATINGIDO 'x'

/*
* Declarações
*/
int batalha_naval();
void desenharTela();
int capturarMenu();
int definirCampos();

struct jogadores jogadorAtual;
struct embarcacoes navios[5];
//struct campos campo;
int menuPosicao;
int menuSelecionado;
int telaAtual;

/*
* Função Principal
*/
int batalha_naval()
{
    int idMenu;

    setlocale(LC_CTYPE, "portuguese_brazil.1252");

    telaAtual = 0;
    desenharTela(telaAtual, 0);
    menuPosicao = 1;

    while (idMenu) {
        idMenu = capturarMenu();
        if (idMenu == 1 && telaAtual == 1) {
            //definirCampos();
            //saida em desenvolvimento
            if (definirCampos() == 9)
            {
                return 0;
            }
        }
    }
    return 1;
}

/*
* Função desenharTela
*/
void desenharTela (int tela, int posicao, int instrucao)
{
    //int i;
    char *linha_1;
    char *linha_2;
    char *linha_3;
    char *linha_4;
    char *linha_5;
    char linha_prepara[25][80];
    int linha, coluna;

    // code
    switch (tela)
    {
    case 0: // intro
        system("cls");
        printf("===============================================================================\n");
        printf("                                                                               \n");
        printf("                                     -*+*+                -                    \n");
        printf("    Trabalho de Programação    -+*+  *:+#+@-  -  :+-   -+W#           -=-      \n");
        printf("                               *+++#= -#+  ==-=:*:#-+ ::==+-       ---+:--     \n");
        printf("          24/09/2017             *@+ +#- #+ -#: *+++=:+++-:      -*@##@:- -    \n");
        printf("                                    *@:-=: =+ :#  ++ -: :+:     --  :#:-- -    \n");
        printf("                                      -== +: *+ =#*=**++: +    --  -@:  ---    \n");
        printf("             Jogo              *@- :+*=*:+#:-++:+-#+  : :=-  --- --=+- - -     \n");
        printf("                               +WW+        -++**::+:++*: : *--  - +# - - -     \n");
        printf("                               -WWW=   -:-       :*-   : :+*-*-+--W+- - -      \n");
        printf("         B A T A L H A         -W@=+# -:---       +*:-**:  -#=W# @* - ---      \n");
        printf("                                @WWWW#             +-:-*+-+#*-::=@  -- -       \n");
        printf("              N A V A L          -#WWW=        by      : =-*:++=W: - --        \n");
        printf("                                   -@WW+                     -=+++ -- -        \n");
        printf("                                     +WW-          HADS         *=+:--         \n");
        printf("                                     -:W# :***#+                  *= -         \n");
        printf("                                  -==**-@+  :#--==@#**+:++         -=          \n");
        printf("        h4mnsoft@gmail.com       =:  ::   -:   :+-        -+*##+:-  *          \n");
        printf("                                  :#:  -:-  -::   -:    -  :+- -*==@:          \n");
        printf("                                     :=#+-        ----   -:-      -+**:        \n");
        printf("                                           :+=====*****======*+-               \n");
        printf("                                                                               \n");
        printf("===============================================================================\n");
        printf("Pressione qualquer tecla para continuar...");
        break;
    case 1: // menu
        linha_1 = "                             =      JOGAR       =                              \n";
        linha_2 = "                             =      PAUSE       =                              \n";
        linha_3 = "                             =    COMO JOGAR    =                              \n";
        linha_4 = "                             =     PONTUAÇÃO    =                              \n";
        linha_5 = "                             =       SAIR       =                              \n";

        switch (posicao)
        {
        case 1:
            linha_1 = "                             = >    JOGAR     < =                              \n";
            break;
        case 2:
            linha_2 = "                             = >    PAUSE     < =                              \n";
            break;
        case 3:
            linha_3 = "                             = >  COMO JOGAR  < =                              \n";
            break;
        case 4:
            linha_4 = "                             = >   PONTUAÇÃO  < =                              \n";
            break;
        case 5:
            linha_5 = "                             = >     SAIR     < =                              \n";
            break;
        }
        system("cls");
        printf("BATALHA NAVAL - Menu                                                           \n");
        printf("===============================================================================\n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                   M E N U                                     \n");
        printf("                                                                               \n");
        printf("                             ====================                              \n");
        printf("%s", linha_1);
        printf("%s", linha_2);
        printf("%s", linha_3);
        printf("%s", linha_4);
        printf("%s", linha_5);
        printf("                             ====================                              \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("===============================================================================\n");
        break;
    case 2: // prepara Nome do Jogador
        system("cls");
        printf("BATALHA NAVAL - Preparação                                          Jogador #%d \n", jogadorAtual.jogador_id);
        printf("===============================================================================\n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                 ============================================                  \n");
        printf("                 =                                          =                  \n");
        printf("                 =                                          =                  \n");
        printf("                 =      Digite o nome do Jogador #%d:        =                  \n", jogadorAtual.jogador_id);
        printf("                 =                                          =                  \n");
        printf("                 =                                          =                  \n");
        printf("                 ============================================                  \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("                                                                               \n");
        printf("===============================================================================\n");
        break;
    case 3: // prepara Navios
        switch (instrucao)
        {
        case 1:
            linha_1 = "Escolha o navio";
            break;
        case 2:
            linha_1 = "Digite o Navio a ser colocado";
            break;
        }

        // Início da composição da tela 3
        // ==============================
        //
        system("cls");
        char linha_prepara[][80] = {
            "BATALHA NAVAL - Preparação                                 Blocos restantes: 30 ",
            "=============================================|==================================",
            "  ",
        };

        // INICIO - bloco que imprime o vetor em formato de tabuleiro
        //strcat(linha_prepara[2], "  indice 2");

        for (linha = 0; linha < 25; linha++)
        {
            printf("%s", linha_prepara[linha]);
            printf("\n");
        }
        // FIM - bloco que imprime o vetor em formato de tabuleiro
        printf("Fim \n");

        for (coluna=0; coluna<10; coluna++)
        {
            printf("  %d ", coluna);
        }
        printf("\n");
        for (linha=0; linha<10; linha++)
        {
            if (linha == 0)
            {
                printf("  -----------------------------------------\n");
            } else {
                printf("  |---|---|---|---|---|---|---|---|---|---|\n");
            }
            printf("%d ", linha);
            for (coluna=0; coluna<10; coluna++)
            {
                printf("| %c ", campo.navios[jogadorAtual.jogador_id][linha][coluna]);
            }
            printf("|\n");
        }
        printf("  -----------------------------------------\n");

        system("pause");
        break;
        //
        // ==============================
        // FIM da composição da tela 3

        system("cls");
        printf("BATALHA NAVAL - Preparação                                 Blocos restantes: 30\n");
        printf("=============================================|=================================\n");
        printf("    0   1   2   3   4   5   6   7   8   9    |                                 \n");
        printf("  -----------------------------------------  |  Nome do Jogador #1:            \n");
        printf("0 |<+>|   |   |   |   |   |   |   |   |   |  |  [%s]\n", jogadorAtual.nome);
        printf("  |---|---|---|---|---|---|---|---|---|---|  |                                 \n");
        printf("1 |   |   |   |   |   |   |   |   |   |   |  |  Navios (tamanho):              \n");
        printf("  -----------------------------------------  |  1. %s (%d blocos)\n", navios[0].nome, navios[0].colocados[jogadorAtual.jogador_id]);
        printf("2 |   |   |   |   |   |   |   |   |   |   |  |  2. %s (%d blocos)\n", navios[1].nome, navios[1].colocados[jogadorAtual.jogador_id]);
        printf("  -----------------------------------------  |  3. %s (%d blocos)\n", navios[2].nome, navios[2].colocados[jogadorAtual.jogador_id]);
        printf("3 |   |   |   |   |   |   |   |   |   |   |  |  4. %s (%d blocos)\n", navios[3].nome, navios[3].colocados[jogadorAtual.jogador_id]);
        printf("  -----------------------------------------  |                                 \n");
        printf("4 |   |   |   |   |   |   |   |   |   |   |  |  Navios disponíveis:            \n");
        printf("  -----------------------------------------  |  %02d navios disponíveis\n", jogadorAtual.naviosDisponiveis);
        printf("5 |   |   |   |   |   |   |   |   |   |   |  |                                 \n");
        printf("  -----------------------------------------  |  Blocos restantes:              \n");
        printf("6 |   |   |   |   |   |   |   |   |   |   |  |  %02d blocos restantes\n", jogadorAtual.blocosRestantes);
        printf("  -----------------------------------------  |                                 \n");
        printf("7 |   |   |   |   |   |   |   |   |   |   |  |                                 \n");
        printf("  -----------------------------------------  |                                 \n");
        printf("8 |   |   |   |   |   |   |   |   |   |   |  |                                 \n");
        printf("  -----------------------------------------  |                                 \n");
        printf("9 |   |   |   |   |   |   |   |   |   |   |  |  %s: \n", linha_1);
        printf("  -----------------------------------------  |  [1-4]>");
        break;
    case 4: // quadro
        break;
    case 5: // estatistica
        break;
    case 6: // ganhou-perdeu
        break;
    default:
        printf("WEEErrOoo!\n");
        break;
    }
}

/*
* Funções capturarMenu
*/
int capturarMenu ()
{
    int tecla;

    fflush(stdin);
    tecla = getch();

    if (tecla == 224) {
        tecla = getch();
        switch (tecla)
        {
        case 72: // Seta acima
            menuPosicao--;
            break;
        case 80: // Seta abaixo
            menuPosicao++;
            break;
        }
    } else {
        if (tecla == 13 && menuPosicao == 5){
            return 0;
        }
        if (tecla == 13){
            if (telaAtual >= 1) {
                return menuPosicao;
            }
            if (telaAtual == 0) {
                telaAtual = 1;
            }
        }
    }

    if (menuPosicao < 1){ menuPosicao = 5; }
    if (menuPosicao > 5){ menuPosicao = 1; }

    desenharTela(telaAtual, menuPosicao, 0);

    return 9;
}

int definirCampos()
{
    int i;
    int navioTamanho[5];
    int navioQuantidade[5];
    int naviosBlocosColocados[5];
    int naviosTotal = 0;
    int blocosTotal = 0;
    int navioEscolhido = 0;
    int ehNumero = 0;
    int linha, coluna;

    // Prenchimento da matriz com os navios disponíveis
    strcpy(navios[0].nome, "Submarino");
        navios[0].tamanho = 2;
        navios[0].quantidade = 4;
    strcpy(navios[1].nome, "Torpedeiro");
        navios[1].tamanho = 3;
        navios[1].quantidade = 3;
    strcpy(navios[2].nome, "Navio-Tanque");
        navios[2].tamanho = 4;
        navios[2].quantidade = 2;
    strcpy(navios[3].nome, "Porta-Avião");
        navios[3].tamanho = 5;
        navios[3].quantidade = 1;

    // Laço para os 2 (dois) jogadores
    for (jogadorAtual.jogador_id = 1; jogadorAtual.jogador_id <= 2; jogadorAtual.jogador_id++) {
        //Coleta nome do jogador
        desenharTela(2, 0, 0);
        scanf("%s", jogadorAtual.nome);

        //Prepara Campo
        //E adiciona para todos o caracter ~
        for (linha=0; linha<10; linha++)
        {
            for (coluna=0; coluna<10; coluna++)
            {
                campo.navios[jogadorAtual.jogador_id][linha][coluna] = CMAR;
            }
        }

        //Calcula quantidade de blocos por navios
        for (i=0; i<5; i++) {
            navios[i].colocados[jogadorAtual.jogador_id] = navios[i].tamanho;
            naviosTotal = naviosTotal + navios[i].quantidade;
            blocosTotal = blocosTotal + (navios[i].quantidade * navios[i].tamanho);
        }
        jogadorAtual.naviosDisponiveis = naviosTotal;
        jogadorAtual.blocosRestantes = blocosTotal;

        desenharTela(3, 0, 1);

        //Recebe o número do navio escolhido
        ehNumero = 0;
        while (!ehNumero)
        {
            fflush(stdin);
            navioEscolhido = getch();

            if (navioEscolhido > 48 && navioEscolhido < 53) {
                ehNumero = aux_isNumber(navioEscolhido);
                printf("%c", navioEscolhido);
            }
        }

        //Coleta posições dos navios
        while (jogadorAtual.blocosRestantes > 0)
        {
            //code
            //aux_delay(1); // Teste de delay
            desenharTela(3, 0, 1);
        }

        system("cls");
        printf("Fim da programação! Pressione qualquer tecla para sair...");
        getch();
        return 9;
    }
    return 0;
}

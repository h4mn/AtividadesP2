/**
# Parte 1 - C

** Mat�rias
* Prog 1
* Modulariza��o
* Ponteiros
* Manipula��o String
* Arquivos

** Avalia��o
* Pr�tica 50%
* Projeto: Batalha Naval (Peso: 0.4)
* Avalia��o Laborat�rio - 2 aulas (Peso: 0.6)

** Plano de aulas
*- 23/09 - Explica��o do jogo
*- 28/09 - Manipula��o String
*- 30/09 - Manipula��o String 2 / Arquivos
*- 05/10 - Arquivos
*- 07/10 - (N�o tem aula)
*- 12/10 - (N�o tem aula)
*- 14/10 - (N�o tem aula)
*- 19/10 - Exerc�cio Pr�tico (String/Arquivos)
*- 21/10 - Prova Pr�tica

# Parte 2 - Unity
** Avalia��o
* Projeto 50%

**/
#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined (_WIN64)
    /* Microsoft Windows (32-bit / 64-bit). ............. */

    #define OS_Windows = 1

    #include <locale.h> // Biblioteca de localiza��es
    #include <ctype.h>
    #include <windows.h>
    #include <conio.h>

#elif __linux__
    /* Linux. ......................................... */

    #define OS_Windows = 0

#endif // defined

float r_gas;

int menu();
int jogo_da_velha();
int batalha_naval();
int campo_minado();
int aula_20170928();
void gasolina();

int main()
{
    // Configura��o do Portugu�s (Acentua��o e Cedilha)
    setlocale(LC_CTYPE, "portuguese_brazil.1252");
    //setlocale(LC_CTYPE, "portuguese-brazilian");

    while (menu() != 0) {
        system("pause");
    }
    return 0;
}

int menu()
{
    char escolha;
    while (escolha != '0') {
        system("cls");
        printf("========== MENU ===========\n");
        printf("1. Jogo da Velha\n");
        printf("2. Campo Minado\n");
        printf("3. Batalha Naval\n");
        printf("4. Aula 28/09\n");
        printf("5. \n");
        printf("6. \n");
        printf("7. \n");
        printf("8. \n");
        printf("9. teste do meu amor\n");
        printf("0. Sair\n");
        printf("===========================\n");
        printf("Digite uma op��o [1 - 0]: ");

        escolha = getchar();

        //Beep(666, 300);

        switch (escolha) {
        case '0':
            return 0;
        case '1':
            jogo_da_velha();
            break;
        case '2':
            campo_minado();
            break;
        case '3':
            batalha_naval();
            break;
        case '4':
            aula_20170928();
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            //teste();
            gasolina();
            break;
        }

        fflush(stdin);

    }

    return escolha;
}

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

//#include "src/aula_01.c"
//#include "src/aula_04.c"

float r_gas;

int menu();
int aula_01();
int aula_04();
int aula_08();
void gasolina();

int main()
{
    // Configura��o do Portugu�s (Acentua��o e Cedilha)
    setlocale(LC_CTYPE, "portuguese_brazil.1252");

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
        printf("3. \n");
        printf("4. \n");
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
            aula_01();
            break;
        case '2':
            aula_08();
            break;
        case '3':
        case '4':
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

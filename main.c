/** @file main.c @brief Arquivo principal. */
#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined (_WIN64)
    /* Microsoft Windows (32-bit / 64-bit). ............. */

    #define OS_Windows = 1

    #include <locale.h> // Biblioteca de localizações
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
int aula_04();
int aula_20170928();
int aux_isNumber();
void testa_isNumber();
void gasolina();

/**
 * Aulas de Programacao II
 */
int main()
{
    // Configuração do Português (Acentuação e Cedilha)
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
        printf("4. Aula de Ponteiros\n");
        printf("5. Aula 28/09\n");
        printf("6. \n");
        printf("7. \n");
        printf("8. Teste da nova funcionalidade\n");
        printf("9. teste do meu amor\n");
        printf("G. Segunda aula de File\n");
        printf("0. Sair\n");
        printf("===========================\n");
        printf("Digite uma opção [1 - 0]: ");

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
            aula_04();
            break;
        case '5':
            aula_20170928();
            break;
        case '6':
        case '7':
        case '8':
            testa_isNumber();
            break;
        case 'G':
            aula_file2();
            break;
        case '9':
            //teste();
            gasolina();
            break;
        }

        fflush(stdin);

    }

    return escolha;
}

#include <conio.h>

int teste()
{
    //textcolor(RED);
    printf("\n<3<3<3 Eu te amo Dediane! <3<3<3\n");

    system("pause");
    return 0;
}

void gasolina ()
{
    const float precoLitro = 2.5;
    int litros;
    printf("\n\nDada a fun��o f(x) = 2.50*x\n");
    printf("Quantos litros 'x' foi abastecido: ");
    scanf("%d", &litros);
    printf("\nRetorno da fun��o f(%d) = 2.50*%d", litros, litros);
    printf("\n\nO pre�o de %d litros de gasolina �: %3.2f\n\n", litros, (float) precoLitro * litros);
    system("pause");
}

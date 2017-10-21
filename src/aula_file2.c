#include <stdio.h>
#include <stdlib.h>

void inserirRegistroPesquisa() {
    printf("Vamos inserir um registro de pesquisa.\n");
    system("pause");
}
void buscarRegistroPesquisa() {
    printf("Vamos buscar um registro de pesquisa.\n");
    system("pause");
}
void relatorioJogadoresPorPeriodo() {
    printf("Vamos buscar Jogadores por Período.\n");
    system("pause");
}

int menu_aula_file2()
{
    //
    int opcao;

    system("cls");
    printf("Benvindo a Pesquisa do Curso de Jogos - FATEC-AM\n");
    printf("\n");
    printf("\n1 - Inserir registro de pesquisa");
    printf("\n2 - Buscar registro de pesquisa");
    printf("\n3 - Relatório de %% de jogadores por período");
    printf("\n");
    printf("\n9 - Sair");
    printf("\n");
    printf("\nDigite a opção que deseja: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        inserirRegistroPesquisa();
        break;
    case 2:
        buscarRegistroPesquisa();
        break;
    case 3:
        relatorioJogadoresPorPeriodo();
        break;
    case 9:

        break;
    default:
        printf("\nOpção inválida! Digite novamente.");
        break;
    }

    return opcao;
}

int aula_file2()
{
    //
    system("cls");
    while (menu_aula_file2() != 9) { }
    system("pause");
}

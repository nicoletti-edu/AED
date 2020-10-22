#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int idade;
    int altura;
} Pessoa;

int main()
{
    char continuar;
    int qnt = 0;
    Pessoa *p;
    do
    {
        system("cls");
        printf("Deseja inserir um novo nome?\n1 - Sim\n0 - Nao\n");
        continuar = getchar();
        fflush(stdin);
        if (continuar == '1')
        {
            qnt++;
            p = realloc(p, qnt * sizeof(Pessoa));
            if (p == NULL)
            {
                printf("Memoria Insuficiente!\n");
                system("pause");
                return 1;
            }
            printf("Insira um nome: ");
            scanf("%s", &*(p + qnt - 1)->nome);
            printf("Insira uma idade: ");
            scanf("%d", &(p + qnt - 1)->idade);
            printf("Insira uma altura: ");
            scanf("%d", &(p + qnt - 1)->altura);
            printf("Inserido com sucesso!");
        }
    } while (continuar != '0');
    system("cls");
    int i = 0;
    while (i < qnt)
    {
        printf("%i - %s\n", i, p->nome);
        printf("Idade: %d\n", p->idade);
        printf("Altura: %d\n", p->altura);
        printf("\n");
        i++;
        p++;
    }

    free(p);
    return 0;
}

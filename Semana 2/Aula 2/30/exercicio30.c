#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int **criarMatriz(int m, int n);
void lerMatriz(int **M, int ncolunas, int nlinhas);
void imprimirMatriz(int **M, int ncolunas, int nlinhas);
int somarMatriz(int **M, int ncolunas, int nlinhas);
int *colunaMatriz(int **M, int ncolunas, int nlinhas, int coluna);
void imprimirVetor(int *vetor, int n);
void liberarMatriz(int **M, int ncolunas);
void slp(int tempo);

int main()
{
    int ncolunas, nlinhas, **M, coluna;
    printf("Insira o numero de colunas: ");
    scanf("%d", &ncolunas);
    printf("Insira o numero de linhas: ");
    scanf("%d", &nlinhas);
    M = criarMatriz(ncolunas, nlinhas);
    int finish = 0;
    do
    {
        //system("cls");
        printf("1 - Ler Numeros\n2 - Imprimir Numeros\n3 - Somar Numeros\n4 - Imprimir Coluna\n5 - Redimensionar Matriz\n6 - Sair\n");
        fflush(stdin);
        switch (getchar())
        {
        case '1':
            lerMatriz(M, ncolunas, nlinhas);
            break;
        case '2':
            imprimirMatriz(M, ncolunas, nlinhas);
            break;
        case '3':
            printf("Valor Da Soma: %d", somarMatriz(M, ncolunas, nlinhas));
            slp(5);
            break;
        case '4':
            printf("Insira o numero da coluna a ser impresso: ");
            scanf("%d", &coluna);
            imprimirVetor(colunaMatriz(M, ncolunas, nlinhas, coluna), nlinhas);
            break;
        case '5':
            liberarMatriz(M, ncolunas);
            printf("Insira o numero de colunas: ");
            scanf("%d", &ncolunas);
            printf("Insira o numero de linhas: ");
            scanf("%d", &nlinhas);
            M = criarMatriz(ncolunas, nlinhas);
            break;
        case '6':
            finish = 1;
            break;
        default:
            printf("Opção inválida!");
            break;
        }
    } while (!finish);

    liberarMatriz(M, ncolunas);
    return 0;
}

void slp(int tempo)
{
#ifdef _WIN32
    Sleep(tempo * 1000);
#else
    sleep(tempo);
#endif
}

int **criarMatriz(int ncolunas, int nlinhas)
{
    int **M = NULL;
    M = (int **)malloc(nlinhas * sizeof(int *));
    for (int i = 0; i < nlinhas; i++)
    {
        M[i] = (int *)malloc(ncolunas * sizeof(int));
        for (int j = 0; j < ncolunas; j++)
        {
            M[i][j] = 0;
        }
    }
    return M;
}

void lerMatriz(int **M, int ncolunas, int nlinhas)
{
    for (int i = 0; i < nlinhas; i++)
    {
        printf("Linha %d\n", i + 1);
        for (int j = 0; j < ncolunas; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }
}

int somarMatriz(int **M, int ncolunas, int nlinhas)
{
    int valor = 0;
    for (int i = 0; i < nlinhas; i++)
    {
        for (int j = 0; j < ncolunas; j++)
        {
            valor += M[i][j];
        }
    }
    return valor;
}

void imprimirMatriz(int **M, int ncolunas, int nlinhas)
{
    for (int i = 0; i < nlinhas; i++)
    {
        for (int j = 0; j < ncolunas; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    slp(5);
}

int *colunaMatriz(int **M, int ncolunas, int nlinhas, int coluna)
{
    if (coluna <= 0)
    {
        printf("Coluna Invalida");
        slp(2);
        return NULL;
    }
    int *vetor = malloc(nlinhas * sizeof(int *));
    for (int i = 0; i < nlinhas; i++)
    {
        for (int j = 0; j < ncolunas; j++)
        {
            if (j == coluna - 1)
            {
                vetor[i] = M[i][j];
            }
        }
    }
    return vetor;
}

void imprimirVetor(int *vetor, int n)
{
    if (vetor == NULL)
        return;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    slp(5);
}

void liberarMatriz(int **M, int ncolunas)
{
    for (int i = 0; i < ncolunas; i++)
        free(M[i]);
    free(M);
}
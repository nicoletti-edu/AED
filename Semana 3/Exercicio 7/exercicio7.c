#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    printf("Insira a quantidade de numeros a serem inseridos: ");
    scanf("%d", &n);

    if (n == 0)
        return 0;

    int *vetor = malloc(n * sizeof(int));
    printf("Insira os numeros: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int numero;
    for (int i = 0; i < n; i++)
    {
        numero = vetor[i];
        for (int j = n-1; j > 0; j--)
        {
            if (vetor[j] == numero && j != i)
            {
                n--;
                if (j == n)
                {
                    vetor = realloc(vetor, n * sizeof(int));
                }
                else
                {
                    memcpy(&vetor[j], &vetor[j + 1], (n - j) * sizeof(int));
                    vetor = realloc(vetor, n * sizeof(int));
                }
            }
        }
    }

    system("cls");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vetor[i]);
    }

    free(vetor);
    return 0;
}

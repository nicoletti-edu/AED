#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,ncolunas,nlinhas, **M;

    M = (int **)malloc(ncolunas * sizeof(int *));
    printf("Insira o numero de colunas: "); scanf("%d", &ncolunas );
    printf("Insira o numero de linhas: "); scanf("%d", &nlinhas );
    for(i=0;i<ncolunas;i++)
        M[i] = malloc(ncolunas * sizeof(int));

    for(i=0;i<ncolunas;i++)
        free(M[i]);
    free(M);
    
    return 0;
}
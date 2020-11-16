#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "filaOrdenada.h"

void pause()
{
    printf("Pressione enter para continuar!");
    getchar();
    fflush(stdin);
    return;
}

int menu(vars *variaveis, fila *filaInfo)
{

    printf("1) Adicionar nome\n");
    printf("2) Remover nome\n");
    printf("3) Listar\n");
    printf("4) Listar Ordenado\n");
    printf("5) Esvaziar\n");
    printf("6) Sair \n");
    fflush(stdin);
    scanf("%d", &variaveis->i);

    switch (variaveis->i)
    {
    case 1:
        push(filaInfo);
        break;
    case 2:
        pop(filaInfo);
        break;
    case 3:
        list(filaInfo);
        break;
    case 4:
        imprimirOrdenada(variaveis, filaInfo);
        break;
    case 5:
        empty(filaInfo);
        break;
    case 6:
return 0;
        break;
    default:
        printf("Valor Invalido\n");
        pause();
        break;
    }

    return 1;
}

int main()
{
    vars *variaveis;
    fila *filaInfo;

    pBuffer = malloc(sizeof(vars) + sizeof(fila) + sizeof(fila));
    variaveis = pBuffer;
    filaInfo = pBuffer + sizeof(vars);

    if (pBuffer == NULL)
    {
        printf("Memoria insuficiente!");
        return 1;
    }

    reset(filaInfo);
    while (menu(variaveis, filaInfo) == 1)
        ;
    clear(filaInfo);
    free(pBuffer);

    return 0;
}
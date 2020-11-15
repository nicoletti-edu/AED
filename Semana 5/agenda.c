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
    printf("4) Esvaziar\n");
    printf("5) Sair \n");
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
        list(variaveis, filaInfo);
        break;
    case 4:
        empty(filaInfo);
        break;
    case 5:
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

    pBuffer = malloc(sizeof(vars) + sizeof(fila));
    variaveis = pBuffer;
    filaInfo = pBuffer + sizeof(vars);
    variaveis->qnt = 0;

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
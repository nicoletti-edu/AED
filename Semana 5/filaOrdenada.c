#include "filaOrdenada.h"
#include <stdio.h>
#include <stdlib.h>

void reset(fila *filaInfo)
{
    filaInfo->first = NULL;
    filaInfo->last = NULL;
    filaInfo->qnt = 0;

    return;
}

int empty(fila *filaInfo)
{
    if (filaInfo->qnt == 0)
    {
        return 1;
    }

    return 0;
}

void push(fila *filaInfo)
{
    tipoFila *node;
    node = malloc(sizeof(tipoFila));

    if (node == NULL)
    {
        printf("Memoria Insuficiente!");
        return;
    }
    if (empty(filaInfo))
    {
        filaInfo->first = node;
        filaInfo->last = node;
        fill(node);
        node->next = NULL;
        node->previous = NULL;
    }
    else
    {
        tipoFila *previous;
        previous = filaInfo->last;
        previous->next = node;
        node->previous = previous;
        fill(node);
        node->next = NULL;
        filaInfo->last = node;
    }

    filaInfo->qnt++;
    return;
}

void pop(fila *filaInfo)
{
    if (empty(filaInfo))
    {
        return;
    }

    tipoFila *node = filaInfo->first;

    if (filaInfo->first == filaInfo->last)
    {
        free(node);
        filaInfo->first = NULL;
        filaInfo->last = NULL;
    }
    else
    {
        tipoFila *next;
        next = node->next;
        next->previous = NULL;
        free(node);
        filaInfo->first = next;
    }

    filaInfo->qnt--;
    return;
}

void clear(fila *filaInfo)
{
    while (!empty(filaInfo))
    {
        pop(filaInfo);
    }

    return;
}

void list(vars *variaveis, fila *filaInfo)
{
    while (!empty(filaInfo))
    {
        printData(filaInfo->first);
        pop(filaInfo);
    }

    return;
}

//Pode inserir qualquer tipo de dados, basta mudar essa função e a struct de dados, such modularity :o
void fill(tipoFila *node)
{
    printf("Insira um nome: ");
    fflush(stdin);
    fgets(node->info.nome, 40, stdin);

    return;
}

void printData(tipoFila *node)
{
    printf("Nome: %s", node->info.nome);

    return;
}
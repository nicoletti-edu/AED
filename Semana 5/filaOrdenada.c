#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaOrdenada.h"

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

void list(fila *filaInfo)
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
    printf("Insira uma idade: ");
    scanf("%d", &node->info.idade);

    return;
}

void printData(tipoFila *node)
{
    printf("Nome: %s Idade: %d\n", node->info.nome, node->info.idade);
    return;
}

void imprimirOrdenada(vars *variaveis, fila *filaInfo)
{

    printf("Ordenar por: \n1)Ordem Crescente\n2)Ordem Decrescente\n");
    scanf("%d", &variaveis->i);
    fila *filaOrdenada = filaInfo + sizeof(fila);
    reset(filaOrdenada);
    while (!empty(filaInfo))
    {
        //Percorre a lista e passa ela de forma ordenada
        pushOrder(filaOrdenada, filaInfo->first, variaveis);
        pop(filaInfo);
    }
    list(filaOrdenada);
    return;
}

void pushOrder(fila *filaInfo, tipoFila *nodo, vars *variaveis)
{
    tipoFila *node;
    node = malloc(sizeof(tipoFila));
    node->info.idade = nodo->info.idade;
    strcpy(node->info.nome, nodo->info.nome);
    if (node == NULL)
    {
        printf("Memoria Insuficiente!");
        return;
    }
    if (empty(filaInfo))
    {
        filaInfo->first = node;
        filaInfo->last = node;
        node->next = NULL;
        node->previous = NULL;
        filaInfo->qnt++;

        return;
    }
    else
    {
        tipoFila *aux = filaInfo->last;
        //verifica o tipo de ordenação e ordena conforme
        if (variaveis->i == 1)
        {
            while (aux->info.idade < node->info.idade)
            {
                if (aux->previous != NULL)
                {
                    aux = aux->previous;
                }
                else
                {
                    filaInfo->first = node;
                    aux->previous = node;
                    node->next = aux;
                    filaInfo->qnt++;
                    return;
                }
            }
        }
        else
        {
            while (aux->info.idade > node->info.idade)
            {
                if (aux->previous != NULL)
                {
                    aux = aux->previous;
                }
                else
                {
                    filaInfo->first = node;
                    aux->previous = node;
                    node->next = aux;
                    filaInfo->qnt++;
                    return;
                }
            }
        }
        //Encaixa o node no lugar devido
        if (aux->next == NULL)
        {
            aux->next = node;
            node->previous = aux;
            node->next = NULL;
            filaInfo->last = node;
            filaInfo->qnt++;
            return;
        }
        node->next = aux->next;
        node->previous = aux;
        node->next->previous = node;
        node->previous->next = node;
        filaInfo->qnt++;
        return;
    }

    filaInfo->qnt++;
    return;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvoreBinaria.h"

void printTree(node *no)
{
    if (no == NULL)
    {
        return;
    }
    printf("%ld\n", no->reg.chave);
    printTree(no->pEsq);
    printTree(no->pDir);
    return;
}

//Retirado de: https://www.tutorialspoint.com/print-binary-tree-in-2-dimensions-in-cplusplus
void printTreeTwoD(node *no, int espaco)
{
    if (no == NULL)
    {
        return;
    }
    espaco += 1;
    printTreeTwoD(no->pDir, espaco);
    for (int i = 0; i < espaco; i++)
    {
        printf("\t");
    }
    printf("%ld\n", no->reg.chave);
    printTreeTwoD(no->pEsq, espaco);
    return;
}

void freeTree(node *no)
{
    if (no == NULL)
    {
        return;
    }
    freeTree(no->pEsq);
    freeTree(no->pDir);
    free(no);
    return;
}

node *createTree(int qnt)
{
    node *root = NULL;
    registro reg;
    for (int i = 0; i < qnt; i++)
    {
        reg.chave = rand() % 100;
        root = insert(reg, root);
    }
    return root;
}

node *insert(registro reg, node *no)
{
    if (no == NULL)
    {
        no = (node *)malloc(sizeof(node));
        if (no == NULL)
        {
            printf("Memória insuficiente!");
            return NULL;
        }
        no->pDir = NULL;
        no->pEsq = NULL;
        no->reg = reg;
        return no;
    }
    if (reg.chave > no->reg.chave)
    {
        no->pDir = insert(reg, no->pDir);
        no = balance(no);
    }
    else if (reg.chave < no->reg.chave)
    {
        no->pEsq = insert(reg, no->pEsq);
        no = balance(no);
    }
    return no;
}

node *balance(node *no)
{
    if (fb(no) < -1 && fb(no->pDir) > 0)
    {
        no->pDir = rotateRight(no->pDir);
        no = rotateLeft(no);
    }
    else if (fb(no) < -1)
    {
        no = rotateLeft(no);
    }
    if (fb(no) > 1 && fb(no->pEsq) < 0)
    {
        no->pEsq = rotateLeft(no->pEsq);
        no = rotateRight(no);
    }
    else if (fb(no) > 1)
    {
        no = rotateRight(no);
    }
    return no;
}

// int delete (registro reg, node *no)
// {
//     if(no == NULL){
//         return 0;
//     }
//     if(reg.chave < no->reg.chave){
//         delete(reg,no->pEsq);
//     }else if (reg.chave < no->reg.chave)
//     {
//         delete(reg, no->pDir);
//     }
//     else if (no->pDir == NULL || no->pEsq == NULL)
//     {
//         node *antigo = no;
//         if (no->pDir == NULL)
//         {
//             no = no->pEsq;
//         }
//         else if (no->pEsq == NULL)
//         {
//             no = no->pDir;
//         }
//         *antigo = NULL;
//         free(antigo);
//     }
//     else
//     {
//         node *aux = procuraMenor(no->pDir);
//         no->reg = aux->reg;
//         delete (no->reg, no->pDir);
//     }
//     no = balance(no);
//     return 1;
// }

// node *find(registro reg, node *no)
// {
//     if (no->reg.chave == reg.chave || no == NULL)
//     {
//         return no;
//     }
//     if (reg.chave > no->reg.chave)
//     {
//         find(reg, no->pDir);
//     }
//     if (reg.chave < no->reg.chave)
//     {
//         find(reg, no->pEsq);
//     }
// }

// node *procuraMenor(node *no)
// {
//     node *menor = no;
//     while (menor->pEsq != NULL)
//     {
//         menor = menor->pEsq;
//     }
//     return menor;
// }

int altura(node *no)
{
    int hEsq, hDir;

    if (no == NULL)
    {
        return 0;
    }
    hEsq = altura(no->pEsq);
    hDir = altura(no->pDir);
    if (hEsq > hDir)
    {
        return hEsq + 1;
    }
    else
    {
        return hDir + 1;
    }
}

int fb(node *no)
{
    if (no == NULL)
    {
        return 0;
    }
    return altura(no->pEsq) - altura(no->pDir);
}

node *rotateRight(node *no)
{
    node *temp = no->pEsq;
    no->pEsq = temp->pDir;
    temp->pDir = no;
    return temp;
}

node *rotateLeft(node *no)
{
    node *temp = no->pDir;
    no->pDir = temp->pEsq;
    temp->pEsq = no;
    return temp;
}

int EhArvoreArvl(node *pRaiz)
{
    int FB;
    if (pRaiz == NULL)
        return 1;
    if (!EhArvoreArvl(pRaiz->pEsq))
        return 0;
    if (!EhArvoreArvl(pRaiz->pDir))
        return 0;
    FB = fb(pRaiz);
    if ((FB > 1) || (FB < -1))
        return 0;
    else
        return 1;
}
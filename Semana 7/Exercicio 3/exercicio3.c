#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvoreBinaria.h"

int main()
{
    printf("Qual cenario quer rodar?\n");
    printf("1 - Cenario um\n");
    printf("2 - Cenario dois\n");
    int i;
    scanf("%i", &i);
    if (i == 1)
        cenarioUm();
    else
        cenarioDois();
    return 0;
}

void cenarioUm()
{
    printf("Cenario 1\n");
    srand(time(0));
    printf("Quantos nos deseja ter na arvore? ");
    int qnt;
    scanf("%i", &qnt);
    node *root = createTree(qnt);
    // printTree(root);
    printTreeTwoD(root, 0);
    printf("Eh arvore avl: ");
    if (EhArvoreArvl(root))
    {
        printf("Sim\n");
    }
    else
    {
        printf("Nao\n");
    }
    freeTree(root);
    return;
}

void cenarioDois()
{
    printf("Cenario 2\n");
    node *root = NULL;
    registro reg;

    printf("Rotação a esquerda\n");
    reg.chave = 1;
    root = NULL;
    root = insert(reg, root);
    reg.chave = 2;
    root = insert(reg, root);
    printTreeTwoD(root, 0);
    reg.chave = 3;
    root = insert(reg, root);
    printf("\nResultado: \n");
    printTreeTwoD(root, 0);
    freeTree(root);

    printf("Rotação a direita\n");
    reg.chave = 3;
    root = NULL;
    root = insert(reg, root);
    reg.chave = 2;
    root = insert(reg, root);
    printTreeTwoD(root, 0);
    reg.chave = 1;
    root = insert(reg, root);
    printf("\nResultado: \n");
    printTreeTwoD(root, 0);
    freeTree(root);

    printf("Rotação dupla a esquerda\n");
    reg.chave = 4;
    root = NULL;
    root = insert(reg, root);
    reg.chave = 2;
    root = insert(reg, root);
    printTreeTwoD(root, 0);
    reg.chave = 3;
    root = insert(reg, root);
    printf("\nResultado: \n");
    printTreeTwoD(root, 0);
    freeTree(root);

    printf("Rotação dupla a direita\n");
    reg.chave = 4;
    root = NULL;
    root = insert(reg, root);
    reg.chave = 6;
    root = insert(reg, root);
    printTreeTwoD(root, 0);
    reg.chave = 5;
    root = insert(reg, root);
    printf("\nResultado: \n");
    printTreeTwoD(root, 0);
    freeTree(root);

    // printf("Delete e rotacao a esquerda\n");
    // reg.chave = 2;
    // root = NULL;
    // root = insert(reg, root);
    // reg.chave = 1;
    // root = insert(reg, root);
    // reg.chave = 3;
    // root = insert(reg, root);
    // reg.chave = 4;
    // root = insert(reg, root);
    // printTreeTwoD(root, 0);
    // reg.chave = 1;
    // delete (reg, root);
    // printf("\nResultado: \n");
    // printTreeTwoD(root, 0);

    return;
}
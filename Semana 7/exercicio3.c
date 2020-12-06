#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct registro
{
    long chave;
} registro;

typedef struct node *ponteiro;

typedef struct node
{
    registro reg;
    ponteiro pEsq, pDir;
} node;

node *createTree(int qnt);
void printTree(node *no);
void freeTree(node *no);
node *insert(registro reg, node *no);
int altura(node *no);
int fb(node *no);
node *rotateRight(node *no);
node *rotateLeft(node *no);
void printTreeTwoD(node *no, int espaco);

int main()
{
    srand(time(0));
    printf("Quantos nós deseja ter na árvore? ");
    int qnt;
    scanf("%i", &qnt);
    node *root = createTree(qnt);
    // printTree(root);
    printTreeTwoD(root, 0);
    printf("Altura da árvore: %i\n", altura(root));
    printf("FB: %i\n", fb(root));
    freeTree(root);
    return 0;
}

void printTree(node *no)
{
    if (no == NULL)
    {
        return;
    }
    printf("%i\n", no->reg.chave);
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
    printf("%i\n", no->reg.chave);
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
    // reg.chave = 1;
    // root = insert(reg, root);
    // reg.chave = 3;
    // root = insert(reg, root);
    // reg.chave = 2;
    // root = insert(reg, root);
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
        if (fb(no) < -1 && fb(no->pDir) > 0)
        {
            no->pDir = rotateRight(no->pDir);
            no = rotateLeft(no);
        }else if(fb(no) < -1){
            no = rotateLeft(no);
        }
    }
    else if (reg.chave < no->reg.chave)
    {
        no->pEsq = insert(reg, no->pEsq);
        if (fb(no) > 1)
        {
            no = rotateRight(no);
        }
    }
    return no;
}

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
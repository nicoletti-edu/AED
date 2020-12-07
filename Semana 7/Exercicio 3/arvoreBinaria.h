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
// int delete (registro reg, node *no);
int altura(node *no);
int fb(node *no);
node *rotateRight(node *no);
node *rotateLeft(node *no);
void printTreeTwoD(node *no, int espaco);
int EhArvoreArvl(node *pRaiz);
void cenarioUm();
void cenarioDois();
node *balance(node *no);
// node *procuraMenor(node *no);
// node *find(registro reg, node *no);
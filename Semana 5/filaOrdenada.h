typedef struct
{
    char nome[40];
} dados;

typedef struct
{
    dados info;
    struct tipoFila *next;
    struct tipoFila *previous;
} tipoFila;

typedef struct
{
    tipoFila *first;
    tipoFila *last;
    int qnt;
} fila;

typedef struct
{
    int i, qnt;
    char name[40];
} vars;

void *pBuffer;

void reset(fila *filaInfo);

int empty(fila *filaInfo);

void push(fila *filaInfo);

void pop(fila *filaInfo);

void clear(fila *filaInfo);

void fill(tipoFila *node);

void printData(tipoFila *node);

void list(vars* variaveis, fila* filaInfo);

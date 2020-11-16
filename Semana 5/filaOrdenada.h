typedef struct
{
    char nome[40];
    int idade;
} dados;

struct nodo
{
    dados info;
    struct nodo *next;
    struct nodo *previous;
};

typedef struct nodo tipoFila;

typedef struct
{
    tipoFila *first;
    tipoFila *last;
    int qnt;
} fila;

typedef struct
{
    int i;
} vars;

void *pBuffer;

void reset(fila *filaInfo);

int empty(fila *filaInfo);

void push(fila *filaInfo);

void pop(fila *filaInfo);

void clear(fila *filaInfo);

void fill(tipoFila *node);

void printData(tipoFila *node);

void list(fila* filaInfo);

void imprimirOrdenada(vars *variaveis, fila *filaInfo);

void pushOrder(fila *filaInfo, tipoFila *nodo, vars *variaveis);
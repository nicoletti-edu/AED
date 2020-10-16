#include <stdio.h>

typedef struct
{
    char *name;
    int i;
}pBuffer;

int main(){
    
    pBuffer *p;
    p = (pBuffer *)malloc(sizeof(pBuffer));
    if(!p){
        printf("Memória Insuficiente!");
        system("pause");
        return 1;
    }
    while(menu(p) == 1)
    free(p);
    return 0;
}

int menu(pBuffer *p)
{
    system("cls");
    printf("1) Adicionar nome\n");
    printf("2) Remover nome\n");
    printf("3) Listar\n");
    printf("4) Sair \n");

    switch (getchar())
    {
    case '1':
        fflush(stdin);
        addName(p);
        break;
    case '2':
        fflush(stdin);
        printf("Ainda n pai");
        break;
    case '3':
        fflush(stdin);
        printf("Ainda n pai");
        break;
    case '4':
        return 0;
        break;
    default:
        fflush(stdin);
        printf("Valor Invalido\n");
        system("pause");
        break;
    }
    return 1;
}

void addName(pBuffer *p){
    printf("Insira um nome: "); scanf("%s",&p->name);
    return;
}
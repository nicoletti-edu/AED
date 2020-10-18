#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[40];
}pessoa;

typedef struct
{
    int i,qnt;
    char name[40];
}vars;

void *pBuffer;

void pause(){
    printf("Pressione enter para continuar!");
    getchar();
    fflush(stdin);
    return;
}

void addName(vars *variaveis){
    pessoa *p;
    variaveis->qnt++;
    pBuffer = realloc(pBuffer,sizeof(vars) + (sizeof(pessoa) * variaveis->qnt));
    variaveis = pBuffer;
    p = pBuffer + sizeof(vars) + (sizeof(pessoa) * (variaveis->qnt - 1));
    fflush(stdin);
    printf("Insira um nome:"); fgets(p->name,40,stdin);
    printf("%s Inserido!",p->name);
    pause();
    return;
}

void list(vars *variaveis){
    pessoa *p;
    p = pBuffer + sizeof(vars);
    variaveis = pBuffer;
    for ( variaveis->i = 0; variaveis->i < variaveis->qnt; variaveis->i++)
    {
        printf("%i - %s", variaveis->i, p->name);
        p++;
    }
    pause();
    return;
}

void removeName(vars *variaveis){

    //pessoa *p, *pessoa;
    // printf("Insira o numero do nome a ser removido:"); scanf("%d", &variaveis->i);
    // fflush(stdin);
    // p = pBuffer + sizeof(vars) + (sizeof(pessoa) * variaveis->i);
    // if(variaveis->i != variaveis->qnt){
    //     proxima = pBuffer + sizeof(vars) + (sizeof(pessoa) * variaveis->i+1);
    //     for (; variaveis->i < variaveis->qnt-1; variaveis->i++)
    //     {
    //         *p = *proxima;
    //         p++;
    //         proxima++;
    //     }
    // }
    variaveis->qnt--;
    pBuffer = realloc(pBuffer, sizeof(vars) + (sizeof(pessoa) * variaveis->qnt) );
    printf("Removido!");
    pause();

}


void search(vars *variaveis){

    pessoa *p;
    p = pBuffer + sizeof(vars);
    printf("Insira o nome a ser buscado: "); fgets(variaveis->name,40,stdin);
    fflush(stdin);
    variaveis = pBuffer;
    for ( variaveis->i = 0; variaveis->i < variaveis->qnt; variaveis->i++)
    {
        if(strcmp(variaveis->name,p->name) == 0){
            printf("%i - %s\n", variaveis->i, p->name);
            pause();
            return;
        }
        p++;
    }
    printf("Fim da busca!\n");
    pause();
    
}

int menu(vars *variaveis)
{
    system("cls");
    printf("1) Adicionar nome\n");
    printf("2) Remover nome\n");
    printf("3) Listar\n");
    printf("4) Buscar\n");
    printf("5) Sair \n");

    switch (getchar())
    {
    case '1':
        fflush(stdin);
        addName(variaveis);
        break;
    case '2':
        fflush(stdin);
        removeName(variaveis);
        break;
    case '3':
        fflush(stdin);
        list(variaveis);
        break;
    case '4':
        fflush(stdin);
        search(variaveis);
        break;
    case '5':
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

int main(){

    vars *variaveis;
    pBuffer = malloc(sizeof(vars));
    variaveis = pBuffer;
    variaveis->qnt = 0;
    if(pBuffer == NULL){
        printf("Memoria insuficiente!");
        return 1;
    }
    while(menu(variaveis) == 1);
    free(pBuffer);
    return 0;
}
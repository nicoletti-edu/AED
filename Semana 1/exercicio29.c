#include <stdio.h>
#include <stdlib.h>
const length = 30;

int main(int argc, char const *argv[])
{
    char *names = malloc(length) + 1;
    menu(&names);
    free(names);
    return 0;
}

void menu(char *names)
{
    printf("1) Adicionar nome\n");
    printf("2) Remover nome\n");
    printf("3) Listar\n");
    printf("4) Sair \n");

    switch (getch())
    {
    case '1':
        printf("1");
        break;
    case '2':
        printf("2");
        break;
    case '3':
        list(names);
        break;
    case '4':
        return;
        break;
    default:
        printf("Valor Invalido");
        break;
    }
    return;
}

void add_name(char *names){
    printf("Insira um nome: ");
    char name[30];
    scanf("%s", &name);
    names = realloc(names, length);
}

void list(char *names)
{
    for (int i = 0; i < strlen(names); i++)
    {
        printf("%c", names[i]);
    }
    return;
}
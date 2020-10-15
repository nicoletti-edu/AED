#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tamanho Maximo do Nome
const length = 30;

int main(int argc, char const *argv[])
{
    char *names = (char *) malloc(length);
    for(int i=0;i<length;i++){
        names[i] = '\0';
    }
    //Quantidade de nomes na lista
    int qnt = 0;
    while (menu(names, &qnt) == 1);
    free(names);
    return 0;
}

int menu(char *names, int *qnt)
{
    system("cls");
    printf("1) Adicionar nome\n");
    printf("2) Remover nome\n");
    printf("3) Listar\n");
    printf("4) Sair \n");

    switch (getch())
    {
    case '1':
        addName(names, qnt);
        break;
    case '2':
        removeName(names, qnt);
        break;
    case '3':
        list(names, qnt);
        break;
    case '4':
        return 0;
        break;
    default:
        printf("Valor Invalido\nPressione Enter para continuar!");
        getch();
        break;
    }
    return 1;
}

//Retorna o endereço da memória vazia mais próximo
char * findEmpty(char *names, int *qnt){
    char *position;
    for (int i = 0; i <= (*qnt); i++)
    {
        if(*(names + (length * i)) == '\0'){
            position = names + (length * i);
            return position;
        }
    }
    return 0;
}


void addName(char *names, int *qnt)
{
    char name[30];
    do
    {
        printf("Insira um nome: ");
        // scanf("%s", &name);
        fflush(stdin);
        fgets(name,32,stdin);
        int len = strlen(name);
        name[len-1] = '\0';
        //Deixar espaço pro \0
        if (strlen(name) > 29)
        {
            printf("Nome excede limite de caracteres\n");
        }
    } while (strlen(name) > 29);
    char *position = findEmpty(names,qnt);
    
    //Faz um calculo pra saber onde guardar o novo nome.
    strcpy(position, name);
    *qnt += 1;
    names = (char *) realloc(names, length * (*qnt + 1));
    //Adiciona um \0 no inicio da proxima string como indicador de espaço vazio
    *(names + length * (*qnt)) = '\0';
    system("cls");
    return;
}


void list(char *names, int *qnt)
{
    for (int i = 0; i < *qnt; i++)
    {
        //Procura o inicio do ultimo espaço alocado
        if(*(names + length * i) != '\0')
        {
            printf("%i - ", i);
            for (int j = 0; j < length; j++)
            {
                if (*(names + length * i + j) != '\0')
                {
                    printf("%c", *(names + length * i + j));
                }
                else
                {
                    break;
                }
            }
            printf("\n");
        }
    }
    printf("Fim da busca!");
    getch();
    system("cls");
    return;
}

void removeName(char *names, int *qnt)
{
    printf("Insira o numero do nome a ser removido: ");
    int i;
    scanf("%i", &i);
    //Verifica se o indice é valido
    if (i <= *qnt)
    {
        //Percorre o nome
        for (int j = 0; j < length; j++)
        {
            if (*(names + length * i + j) != '\0')
            {
                printf("%c", *(names + length * i + j));
                printf(" ");
                *(names + length * i + j) = '\0';
            }
            else
            {
                break;
            }
        }
        if(i == 0 && *qnt == 0){
            printf("Numero Inválido!");
            getch();
            system("cls");
            return;
        }
        *qnt = *qnt - 1;
        memmove(names + length * i, names + length * (i+1),length * (*qnt - i));
        names = (char *) realloc(names, length * (*qnt+1));
        char  * lastname = (names + length * *qnt);
        *lastname  = '\0';
        printf("Removido!");
        getch();
    }else{
        printf("Numero Inválido!");
        getch();
    }
    system("cls");
    return;
}

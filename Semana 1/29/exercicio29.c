#include "exercicio29bib.h"

int main()
{
    char *names = (char *) malloc(length);
    if(!names){
        printf("Memória insuficiente!");
        system("pause");
        return 1;
    }
    for(int i=0;i<length;i++){
        names[i] = '\0';
    }
    //Quantidade de nomes na lista
    int qnt = 0;
    while (menu(names, &qnt) == 1);
    free(names);
    return 0;
}


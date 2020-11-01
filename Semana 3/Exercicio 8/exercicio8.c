#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char linha[80], *palavras = malloc(sizeof(char));
    int letra = 0, space = 1;

    printf("Insira até 80 caracteres:\n");
    fgets(linha, 80, stdin);
    for (int i = 0; i < strlen(linha); i++)
    {
        if (linha[i] == ' ' && space == 0)
        {
            space = 1;
            palavras = (char *) realloc(palavras, sizeof(palavras) + sizeof(char));
            palavras[letra] = '-';
            letra++;
        }
        else if(linha[i] != ' ')
        {
            space = 0;
            palavras = (char *) realloc(palavras, sizeof(palavras) + sizeof(char));
            palavras[letra] = linha[i];
            letra++;
        }
    }
    for (int i = 0; i < letra; i++)
    {
        if(palavras[i] != '-'){
            printf("%c", palavras[i]);
        }else{
            printf("\n");
        }
    }
    
    free(palavras);
    return 0;
}


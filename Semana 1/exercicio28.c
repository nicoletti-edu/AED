#include <stdio.h>

typedef struct
{
    char *nome;
    int i;
}pBuffer;

int main(){
    
    pBuffer *p;
    p = (pBuffer *)malloc(sizeof(pBuffer));
    if(!p){
        printf("Memória Insuficiente!");
        return 1;
    }

    free(p);
    return 0;
}
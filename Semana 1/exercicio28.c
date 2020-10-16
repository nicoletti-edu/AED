#include <stdio.h>

typedef struct
{
    char *nome;
    int i;
}pBuffer;

int main(){
    
    pBuffer *p;
    p = (pBuffer *)malloc(sizeof(pBuffer));


    free(p);
    return 0;
}
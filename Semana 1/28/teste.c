#include <stdio.h>

typedef struct
{
    char *name;
    int i;
}pBuffer;

int main(){
    
    pBuffer *p;
    p = (pBuffer *)malloc(sizeof(pBuffer)*10);
    if(!p){
        printf("Memória Insuficiente!");
        system("pause");
        return 1;
    }
    printf("%i\n", sizeof(pBuffer));
    printf("%i\n", sizeof(p));
    printf("%i\n", sizeof(p)/sizeof(pBuffer));
    system("pause");
    free(p);
    return 0;
}
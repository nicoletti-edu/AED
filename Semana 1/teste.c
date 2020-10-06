#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int length = 30;
    char* names = malloc(length)+1;
    strcpy(names,"Jorge jooj");
    for(int i =0; i<strlen(names);i++){
        printf("%c",names[i]);
    }
    return 0;
}

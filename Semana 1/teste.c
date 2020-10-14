#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main()
{
    int length = 30;
    char* names = malloc(length);
    strcpy(names,"Jorge jooj\0");
    for(int i =0; i<strlen(names);i++){
        printf("%c",names[i]);
    }
    printf("\n");
    names = realloc(names, length * 2);
    strcpy(names+length , "Robeeb\0");
    for(int i = 0; i<30;i++){
        if(*(names+length+i) != '\0'){
            printf("%c",*(names+length+i));
        }else{
            break;
        }
    }
    return 0;
}


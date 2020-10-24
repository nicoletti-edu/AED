#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* reallocNicoletti(void *p, size_t tam);
void printNumbers(int *v,int qnt);

int main ()
{
  int qnt = 0;
  qnt++;
  int *numeros = malloc(sizeof(int) * qnt);
  numeros[0] = 1;
  printNumbers(numeros,qnt);
  qnt++;
  numeros = realloc(numeros, qnt * sizeof(int));
  numeros[1] = 2;
  printNumbers(numeros,qnt);
  free(numeros);
  return 0;
}

void printNumbers(int *v,int qnt){
  printf("\n");
for(int i = 0;i<qnt;i++){
    printf("%i", v[i]);
  }
}

void* reallocNicoletti(void *p, size_t tam){
    void *new;

    if(tam == 0){
        free(p);
        return NULL;
    }

    new = malloc(tam);
    if(new == NULL){
        return NULL;
    }
    
    if(p != NULL){
        memcpy(new,p,tam - sizeof(int));
    }
    return new;
}
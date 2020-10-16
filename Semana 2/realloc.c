#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* reallocNicoletti(void *p, size_t tam);

int main ()
{
    //CÓDIGO QUE TESTA O REALLOC RETIRADO DE: http://www.cplusplus.com/reference/cstdlib/realloc/
  int input,n;
  int count = 0;
  int* numbers = NULL;
  int* more_numbers = NULL;

  do {
     printf ("Enter an integer value (0 to end): ");
     scanf ("%d", &input);
     count++;
    //SUBSTITUIDO O REALLOC POR MINHA FUNÇÃO
     more_numbers = (int*) reallocNicoletti (numbers, count * sizeof(int));

     if (more_numbers!=NULL) {
       numbers=more_numbers;
       numbers[count-1]=input;
     }
     else {
       free (numbers);
       puts ("Error (re)allocating memory");
       exit (1);
     }
  } while (input!=0);

  printf ("Numbers entered: ");
  for (n=0;n<count;n++) printf ("%d ",numbers[n]);
  free (numbers);

  return 0;
}

void* reallocNicoletti(void *p, size_t tam){
    void *novo;

    if(tam == 0){
        free(p);
        return NULL;
    }

    novo = malloc(tam);
    if(!novo){
        return NULL;
    }
    
    if(p != NULL){
        memcpy(novo,p,tam);
    }
    return novo;
}
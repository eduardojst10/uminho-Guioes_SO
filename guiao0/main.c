#include <stdio.h>
#include "api.h"
#define SIZE 10

int main () {

/*
      
   int  *vector;        
   int vector2[SIZE] = {0,1,2,4,5,6,7,8,9,10};
    
    vector = &vector2[0];  
    
    printf("Operacoes através de varáveis globais: fill");
    
    fill(vector2,SIZE,1);

    for (int i = 0; i < SIZE; i++)
        printf("%d,",vector2[i]);

  */

 int v[SIZE];
  int fillValue = 5;

  printf("Filling a vector with %d:\n{", fillValue);
  fill(v, SIZE, fillValue);  
    return 0;
}
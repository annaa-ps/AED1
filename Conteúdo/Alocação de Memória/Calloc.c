/*Calloc: 
-> Retorna um ponteiro para a região de memória alocada ou NULL
-> A diferença entra Calloc e Malloc é a quantidade de parâmetros que a função recebe:
    Malloc = 1 parâmetro
    Calloc = 2 parâmetros
      -> 1º) Qauntidade de elementos pelo qual quero alocar memória
      -> 2º) A quantidade de memória do tipo de elemento que deseja alocar a memória */

#include<stdio.h>
#include<stdlib.h>

int main(){
    int *x;
    
    //x = malloc(sizeof(int)); 

    x = calloc(1, sizeof(int));

    if(x){  // é igual a fazer x != NULL
        printf("Memoria alocada com sucesso!\n");
        *x = 50; // Alterando o conteudo da região de memória que X aponta 
        printf("x: %d\n", *x); 
    }else{
        printf("Erro ao alocar memoria!\n");
    }

    return 0; 
}

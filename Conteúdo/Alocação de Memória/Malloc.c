/*Malloc: 
-> Retorna um ponteiro para a região de memória alocada ou NULL*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int *x;
    
    x = malloc(sizeof(int)); 

    if(x){  // é igual a fazer x != NULL
        printf("Memoria alocada com sucesso!\n");
        *x = 50; // Alterando o conteudo da região de memória que X aponta 
        printf("x: %d\n", *x); 
    }else{
        printf("Erro ao alocar memoria!\n");
    }

    return 0; 
}

#include<stdlib.h>
#include<stdio.h>

/*Aritmética de Ponteiros com Vetor*/

void imprimir(int vet[], int tam){
    int i; 
    for(i=0; i<tam; i++){
        printf("%d ", *(vet + i));
    }
}
int main(){
    int vet[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    imprimir(vet, 10); 

    return 0; 
} 

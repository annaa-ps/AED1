/*Lista de Exercícios de Ponteiro*/

#include<stdlib.h>
#include<stdio.h>

/*1) Escreva um procedimento que receba um vetor inteiro, 
seu tamanho e os endereços de duas variáveis inteiras, 
menor e maior, salve nestas variáveis o menor e o maior 
valor do vetor.*/

void maiorMenor(int vet[], int tam, int *menor, int *maior){
    int i;
    *menor = *vet; 
    *maior = *vet; 

    for(i=0; i<tam; i++){
        if(*menor > *(vet + i)){
            *menor = *(vet + i); 
        }
        if(*maior < *(vet + i)){
            *maior = *(vet + i); 
        }
    }
}

int main(){
    int menor, maior, vet[10] = {1,2,3,4,5,6,7,8,9,10};

    //Retorna lixo de memória ou zero
    printf("Menor: %d\t Maior: %d\n", menor, maior); 
    
    maiorMenor(vet, 10, &menor, &maior);
    printf("\nMenor:%d\t Maior:%d\n", menor, maior); 
    return 0; 
}
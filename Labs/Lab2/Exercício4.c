/*4) Crie um algoritmo com um vetor de números já definido (defina os números que
quiser). O programa irá solicitar um número ao usuário e deverá verificar se o
número está presente no vetor. Exiba uma mensagem informando a posição deste
número no vetor.*/

#include<stdlib.h>
#include<stdio.h>

int main(){
    int vet[] = {6,14,18,2,23,18,22,27,11,31};
    int tam = sizeof(vet), num, i, encontrado = 0;

    printf("Digite um numero:\n");
    scanf("%d", &num);

    while (i < tam){
        if(vet[i]== num){
            encontrado = 1;
            break; 
        }
        i++; 
    }

    if(encontrado){
        printf("O numero %d esta presente no vetor!\t Sua posicao eh: %d\n", num, i); 
    } else {
        printf("O numero %d nao esta presente no vetor!\n", num); 
    }
  
    return 0;
}

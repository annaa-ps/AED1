/*1) Crie um algoritmo que irá solicitar um número inteiro ao usuário. Utilize uma
estrutura condicional para verificar se o número é par ou ímpar. Imprima o resultado.*/

#include<stdlib.h>
#include<stdio.h>

void parImpar (int num){
    if(num % 2 == 0){
        printf("O numero [%d] eh par!\n", num); 
    }else {
        printf("O numero [%d] eh impar!\n", num);
    }
}

int main(){
    int numero;

    printf("Informe um numero:\n");
    scanf("%d", &numero);

    parImpar(numero); 

    return 0;
}
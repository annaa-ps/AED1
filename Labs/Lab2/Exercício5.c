/*5) Crie dois vetores de no mínimo 50 posições. Desenvolva um algoritmo que irá ler 1
valor x e utilizar um loop do tipo for para preencher o primeiro vetor com x*i. Após
isso, utilize outro loop para preencher o segundo vetor com o valores do primeiro,
mas de trás para frente*/
#include<stdlib.h>
#include<stdio.h>

int main(){
    int vet1[50];
    int vet2[50];
    int x, i;

    printf("Informe um valor para X:\n");
    scanf("%d", &x);

    for(i=0; i<50; i++){
        vet1[i] = x * (i+1);
    }

    for(i=0;i<50; i++){
        vet2[i] = vet1[50-1-i];
    }

    printf("Primeiro Vetor:\n"); 
    for(i=0; i<50; i++){
        printf("[%d] ", vet1[i]);
    }

    printf("\n");
    
    printf("\nSegundo Vetor:\n"); 
    for(i=0; i<50; i++){
        printf("[%d] ", vet2[i]);
    } 
  
    return 0; 
}

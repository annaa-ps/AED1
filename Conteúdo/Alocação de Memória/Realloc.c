/*Função Realloc:
  -> Retorna um ponteiro para a nova região de memória;
  -> Se o ponteiro for nulo ela aloca memória;
  -> Se o novo ponteiro for zero a memória é liberada;
  -> Se não houver memória suficiente retorna NULL
  -> a função recebe dois parâmetros 
    1º) O vetor atual;
    2º) O novo tamanho; */

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int i, tam, *vet;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tam); 
  srand(time(NULL)); 

  vet = malloc(tam * sizeof(int)); 

  if(vet){
    printf("Memoria alocada com sucesso!\n");
    for(i=0; i<tam; i++){
      *(vet + i) = rand() % 100; 
    }
    
    printf("\n"); 
    
    for(i=0; i<tam; i++){
      printf("%d ", *(vet+i));  
    }
    
    printf("\n"); 
    
    printf("\nDigite o novo tamanho do vetor: ");
    scanf("%d", &tam); 

    vet = realloc(vet,tam); 

    printf("\nVetor realocado!\n");
    for(i=0; i<tam; i++){
      printf("%d ", *(vet+i));  
    }
    
  }else{
    printf("Erro ao alocar memoria!\n");
  }
  
  return 0;
}

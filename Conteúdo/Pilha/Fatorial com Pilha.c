/*Como similar a recursão do fatorual com a pilha?
  3! = 3*1*2*1 = 6*/

#include<stdlib.h>
#include <stdio.h>
#include<math.h> 

typedef struct no{  
  int valor; 
  struct no *proximo;
}No;

//Função para a operação push(empilhar)
No* empilhar (No *pilha, int num){
    No *novo = malloc(sizeof(No));
    if(novo){
      novo->valor = num;
      novo->proximo = pilha;
      return novo; 
    }else{
        printf("\nErro ao alocar memoria\n");
    }
  return NULL; 
}

//Função para a operação pop(desempilhar)
No* desempilhar(No **pilha){
  No *remover = NULL;
    if(*pilha){
      remover = *pilha;
      *pilha = remover->proximo; 

    }else{
        printf("\nPilha vazia\n"); 
    }
    return remover; 
}

//Função para imprimir a pilha
void imprimir (No *pilha){
  printf("\n\tPILHA\n");
  while(pilha){
    printf("\t%d\n", pilha->valor);
    pilha = pilha->proximo; 
  }
  printf("\n");
}

//Função para calcular o fatorial
int fatorial (int num){
  No *remover, *pilha = NULL;

  while(num > 1){
    pilha = empilhar(pilha, num);
    num--;
  }
  imprimir(pilha);
  
  while(pilha){
    remover = desempilhar(&pilha);
    num = num * remover->valor;
    free(remover);
  }
  return num;
}

int main() {
  int valor;

  printf("Digite um valor maior que 0:\n ");
  scanf("%d", &valor);
  printf("\n\tFatorial de %d = %d\n", valor, fatorial(valor));

  return 0;
}

/*Fila 1 -> FIFO(First Int, Firts Out)*/
#include<stdlib.h>
#include <stdio.h>

typedef struct no{
  int valor;
  struct no*proximo;
}No;

typedef struct {
  No *inicio;
  No *fim;
  int tam; 
}Fila;

//Função para criar a fila
void criar_fila(Fila *fila){
  fila->inicio = NULL;
  fila->fim = NULL; 
  fila->tam = 0;
}
//Função para inserir um elemento na fila
void inserir_na_fila(Fila *fila, int num){
  No *novo = malloc(sizeof(No));
  if(novo){
    novo->valor = num;
    novo->proximo = NULL;
    if(fila->inicio == NULL){
      fila->inicio = novo;
      fila->fim = novo;
    }else{
      fila->fim->proximo = novo; 
      fila->fim = novo; 
    }
    fila->tam++;
  }else{
    printf("\nErro ao alocar memoria!\n");
  }
}

//Função para remover um elemento da fila
No* remover_da_fila(Fila *fila){
  No *remover = NULL;
  if(fila->inicio){
    remover = fila->inicio;
    fila->inicio = remover->proximo;
    fila->tam--;
  }else{
    printf("\n\tFila Vazia!\n");
  }
  return remover;
}

//Função para imprimir a fila
void imprimir(Fila *fila){
  No *aux = fila->inicio;
  printf("\n\t-------FILA-------\n\t");
  while(aux){
    printf("%d ", aux->valor);
    aux = aux->proximo;
  }
  printf("\n\t-------FIM FILA-------\n");
}


int main(){
  No *r;
  Fila fila; 
  int opcao,valor;

  criar_fila(&fila);

  do{
    printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        printf("\nDigite um numero: ");
        scanf("%d", &valor);
        inserir_na_fila(&fila, valor);
        break;
      case 2:
        r = remover_da_fila(&fila);
        if(r){
          printf("\nRemovido: %d\n\n", r->valor); 
          free(r);
        }else{
          printf("Erro ao remover!\n");
        }
        break;
      case 3:
        imprimir(&fila); 
        break;
      default: 
        if(opcao != 0){
          printf("\nOpcao invalida!\n");
        }
    }
  }while(opcao != 0);
  return 0;
}

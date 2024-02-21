/*Pilha*/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int dia, mes, ano; 
}Data; 

typedef struct {
    char nome[50];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

typedef struct{
  No *topo;
  int tam; 
}Pilha;

void criar_pilha(Pilha *p){
  p->topo = NULL;
  p->tam = 0; 
}


Pessoa ler_pessoa(){
    Pessoa p; 

    printf("\nDigite o nome e a data de nascimento dia/mes/ano:\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano); 
    return p; 
}

void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nData: %.2d/%.2d/%.4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

//Função para a operação push(empilhar)
void  empilhar (Pilha *p){
    No *novo = malloc(sizeof(No));
    if(novo){
      novo->p = ler_pessoa();
      novo->proximo = p->topo;
      p->topo = novo; 
      p->tam++;
    }else{
        printf("\nErro ao alocar memoria\n");
    }
}

//Função para a operação pop(desempilhar)
No* desempilhar(Pilha *p){
    if(p->topo){
        No *remover = p->topo;
        p->topo = remover->proximo; 
        p->topo--; 
        return remover;
    }else{
        printf("\nPilha vazia\n"); 
    }
    return NULL; 
}

//Função para imprimir a pilha
void imprimir_pilha(Pilha *p){
  No *aux = p->topo; 
  printf("\n---------PILHA   Tam: %d---------\n", p->tam);
  while(aux){
    imprimir_pessoa(aux->p);
      aux = aux->proximo; 
  }
  printf("\n---------FIM PILHA---------");
}


int main(){
  No *remover;
  Pilha p;  
  int opcao; 

  criar_pilha(&p);
  
  do{
    printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao){
      case 1:
        empilhar(&p); 
        break;
      case 2:
        remover = desempilhar(&p);
        if(remover != NULL){
          printf("\nElemento removido com sucesso!\n");
          imprimir_pessoa(remover->p); 
          free(remover);
        }else{
          printf("\nSem no a remover!\n");
        }
          break;
      case 3:
        imprimir_pilha(&p); 
        break;
      default:
        if (opcao != 0){
          printf("\nOpcao invalida!\n"); 
        }
        break;
    }
  }while(opcao != 0);

    return 0; 
}

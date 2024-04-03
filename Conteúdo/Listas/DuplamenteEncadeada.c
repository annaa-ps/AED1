#include<stdlib.h>
#include<stdio.h>

typedef struct no {
  int valor;
  struct no *proximo;
  struct no *anterior;
} No;

typedef struct {
  No *inicio;
  int tam;
} Lista;

// Função para criar uma lista
void criarLista(Lista *lista) {
  lista->inicio = NULL;
  lista->tam = 0;
}

// Procedimento para inserir no início
void inserirInicio(Lista *lista, int num) {
  No *novo = malloc(sizeof(No));
  if (novo) {
    novo->valor = num;
    novo->proximo = lista->inicio;
    novo->anterior = NULL;
    if (lista->inicio)
      lista->inicio->anterior = novo;
    lista->inicio = novo;
    lista->tam++;
  } else {
    printf("Erro ao alocar memoria!\n");
  }
}

// Procedimento para inserir no fim
void inserirFim(Lista *lista, int num) {
  No *aux, *novo = malloc(sizeof(No));
  if (novo) {
    novo->valor = num;
    novo->proximo = NULL;
    if (lista->inicio == NULL) {
      novo->anterior = NULL;
      lista->inicio = novo;
    } else {
      aux = lista->inicio;
      while (aux->proximo)
        aux = aux->proximo;
      aux->proximo = novo;
      novo->anterior = aux;
    }
    lista->tam++;
  } else {
    printf("Erro ao alocar memoria!\n");
  }
}

// Procedimento para inserir no meio
void inserirMeio(Lista *lista, int num, int ant) {
  No *aux, *novo = malloc(sizeof(No));
  if (novo) {
    novo->valor = num;
    if (lista->inicio == NULL) {
      novo->proximo = NULL;
      novo->anterior = NULL;
      lista->inicio = novo;
    } else {
      aux = lista->inicio;
      while (aux->valor != ant && aux->proximo)
        aux = aux->proximo;
      novo->proximo = aux->proximo;
      novo->anterior = aux;
      if (aux->proximo)
        aux->proximo->anterior = novo;
      aux->proximo = novo;
    }
    lista->tam++;
  } else {
    printf("Erro ao alocar memoria!\n");
  }
}

// Procedimento para inserir de forma ordenada
void inserirOrdenado(Lista *lista, int num) {
  No *aux, *novo = malloc(sizeof(No));
  if (novo) {
    novo->valor = num;
    if (lista->inicio == NULL) {
      novo->proximo = NULL;
      novo->anterior = NULL;
      lista->inicio = novo;
    } else if (novo->valor < lista->inicio->valor) {
      novo->proximo = lista->inicio;
      novo->anterior = NULL;
      lista->inicio->anterior = novo;
      lista->inicio = novo;
    } else {
      aux = lista->inicio;
      while (aux->proximo && novo->valor > aux->proximo->valor)
        aux = aux->proximo;
      novo->proximo = aux->proximo;
      novo->anterior = aux;
      if (aux->proximo)
        aux->proximo->anterior = novo;
      aux->proximo = novo;
    }
    lista->tam++;
  } else {
    printf("\nErro ao alocar memoria!\n");
  }
}

// Função para remover
No *remover(Lista *lista, int num) {
  No *aux, *remover = NULL;
  if (lista->inicio) {
    if (lista->inicio->valor == num) {
      remover = lista->inicio;
      lista->inicio = remover->proximo;
      if (lista->inicio)
        lista->inicio->anterior = NULL;
      lista->tam--;
    } else {
      aux = lista->inicio;
      while (aux->proximo && aux->proximo->valor != num)
        aux = aux->proximo;
      if (aux->proximo) {
        remover = aux->proximo;
        aux->proximo = remover->proximo;
        if (aux->proximo)
          aux->proximo->anterior = aux;
        lista->tam--;
      }
    }
  }
  return remover;
}

// Função para buscar
No *buscar(Lista *lista, int num) {
  No *aux, *no = NULL;
  aux = lista->inicio;
  while (aux && aux->valor != num)
    aux = aux->proximo;
  if (aux)
    no = aux;
  return no;
}

// Função para imprimir a lista
void imprimirLista(Lista lista) {
  No *no = lista.inicio;
  printf("\nLista com Tamanho: %d\n", lista.tam);
  while (no) {
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n\n");
}

int main() {
  int opcao, valor, anterior;
  Lista lista;
  No *removido;

  criarLista(&lista);

  do {
    printf("\n\t0 - Sair\n\t1 - Inserir no Inicio\n\t2 - Inserir no Fim\n\t3 - Inserir no Meio\n\t4- Inserir Ordenado\n\t5- Remover\n\t6 - Imprimir\n\t7 - Buscar\n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("\nDigite um valor: ");
      scanf("%d", &valor);
      inserirInicio(&lista, valor);
      break;
    case 2:
      printf("\nDigite um valor: ");
      scanf("%d", &valor);
      inserirFim(&lista, valor);
      break;
    case 3:
      printf("\nDigite um valor e o valor de referecia: ");
      scanf("%d%d", &valor, &anterior);
      inserirMeio(&lista, valor, anterior);
      break;
    case 4:
      printf("\nDigite um valor:");
      scanf("%d", &valor);
      inserirOrdenado(&lista, valor);
      break;
    case 5:
      printf("\nDigite um valor a ser removido: ");
      scanf("%d", &valor);
      removido = remover(&lista, valor);
      if (removido) {
        printf("Elemento removido: %d\n", removido->valor);
        free(removido);
      } else {
        printf("\nElemento inexistente!\n");
      }
      break;
    case 6:
      imprimirLista(lista);
    case 7:
      printf("\nDigite o valor a ser buscado: ");
      scanf("%d", &valor);
      removido = buscar(&lista, valor);
      if (removido) {
        printf("\nValor encontrado: %d\n", removido->valor);
      } else {
        printf("\nValor nao encontrado!\n");
      }
      break;
    default:
      if (opcao != 0) {
        printf("Opcao invalida!\n");
      }
    }

  } while (opcao != 0);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de dados da fila
#define TAMANHO_MAX 100

typedef struct {
    int dados[TAMANHO_MAX];
    int inicio, fim;
} Fila;

// Funções da fila
void inicializarFila(Fila *fila) {
    fila->inicio = -1;
    fila->fim = -1;
}

int filaVazia(Fila *fila) {
    return (fila->inicio == -1 && fila->fim == -1);
}

void inserir(Fila *fila, int item) {
    if ((fila->fim + 1) % TAMANHO_MAX == fila->inicio) {
        printf("Fila cheia\n");
        return;
    } else if (filaVazia(fila)) {
        fila->inicio = 0;
        fila->fim = 0;
    } else {
        fila->fim = (fila->fim + 1) % TAMANHO_MAX;
    }
    fila->dados[fila->fim] = item;
}

int remover(Fila *fila) {
    int item;
    if (filaVazia(fila)) {
        printf("Fila vazia\n");
        exit(1);
    } else if (fila->inicio == fila->fim) {
        item = fila->dados[fila->inicio];
        fila->inicio = -1;
        fila->fim = -1;
    } else {
        item = fila->dados[fila->inicio];
        fila->inicio = (fila->inicio + 1) % TAMANHO_MAX;
    }
    return item;
}

// Definição da estrutura de dados da pilha
#define TAMANHO_PILHA 100

typedef struct {
    int dados[TAMANHO_PILHA];
    int topo;
} Pilha;

// Funções da pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

void empilhar(Pilha *pilha, int item) {
    if (pilha->topo == TAMANHO_PILHA - 1) {
        printf("Pilha cheia\n");
        return;
    }
    pilha->dados[++pilha->topo] = item;
}

int desempilhar(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
        exit(1);
    }
    return pilha->dados[pilha->topo--];
}

void mostrarPilha(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Elementos da pilha: ");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%d ", pilha->dados[i]);
    }
    printf("\n");
}

void mostrarFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Elementos da fila: ");
    for (int i = fila->inicio; i != fila->fim; i = (i + 1) % TAMANHO_MAX) {
        printf("%d ", fila->dados[i]);
    }
    printf("%d\n", fila->dados[fila->fim]);
}

int main() {
    Fila fila;
    Pilha pilha;
    int escolha, item;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    do {
        printf("\n1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Mostrar elementos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &item);
                inserir(&fila, item);
                empilhar(&pilha, item); // Insere na pilha também
                break;
            case 2:
                item = remover(&fila);
                printf("Elemento removido: %d\n", item);
                break;
            case 3:
                printf("Fila:\n");
                mostrarFila(&fila);
                printf("Pilha:\n");
                mostrarPilha(&pilha);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção invalida\n");
        }
    } while (escolha != 4);

    return 0;
}

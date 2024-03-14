#include "Fila.h"
// Inicializar a fila circular
void iniciarFilaCircular(FilaCircular* fila) {
    fila->cabeca = (No*)malloc(sizeof(No));
    fila->cabeca->prox = fila->cabeca;
    fila->cabeca->ant = fila->cabeca;
}

// Inserir um elemento na fila circular (no final)
void enfileirarCircular(FilaCircular* fila, int novoDado) {
    No* novo = (No*)malloc(sizeof(No));
    novo->num = novoDado;
    novo->prox = fila->cabeca;
    novo->ant = fila->cabeca->ant;
    fila->cabeca->ant->prox = novo;
    fila->cabeca->ant = novo;
}

// Remover um elemento da fila circular (no início)
int desenfileirarCircular(FilaCircular* fila) {
    if (fila->cabeca->prox == fila->cabeca) {
        printf("\nA fila circular esta vazia!\n");
        return -1; // Valor de erro
    }

    // Obter o nó a ser removido (primeiro da fila)
    No* remover = fila->cabeca->prox;
    int valorRemovido = remover->num;

    // Remover o nó e ajustar os ponteiros
    fila->cabeca->prox = remover->prox;
    remover->prox->ant = fila->cabeca;
    free(remover);

    return valorRemovido;
}

// Mostrar os elementos da fila circular
void mostrarFilaCircular(FilaCircular fila) {
    if (fila.cabeca->prox == fila.cabeca) {
        printf("\nA fila circular esta vazia!\n");
        return;
    }

    No* atual = fila.cabeca->prox;
    printf("\nFila Circular: ");
    while (atual != fila.cabeca) {
        printf("[%d] ", atual->num);
        atual = atual->prox;
    }
    printf("\n");
}

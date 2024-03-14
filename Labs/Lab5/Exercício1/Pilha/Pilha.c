#include"Pilha.h"

// Inicializar a pilha
void iniciarPilha(Pilha* pilha) {
    pilha->cabeca = (No*)malloc(sizeof(No));
    pilha->cabeca->prox = pilha->cabeca;
    pilha->cabeca->ant = pilha->cabeca;
}

// Empilhar um elemento na pilha (no topo)
void empilhar(Pilha* pilha, int novoDado) {
    No* novo = (No*)malloc(sizeof(No));
    novo->num = novoDado;
    novo->prox = pilha->cabeca->prox;
    novo->ant = pilha->cabeca;
    pilha->cabeca->prox->ant = novo;
    pilha->cabeca->prox = novo;
}

// Desempilhar um elemento da pilha (do topo)
int desempilhar(Pilha* pilha) {
    if (pilha->cabeca->prox == pilha->cabeca) {
        printf("A pilha esta vazia!\n");
        return -1; // Valor de erro
    }

    // Obter o nó a ser removido (topo da pilha)
    No* remover = pilha->cabeca->prox;
    int valorRemovido = remover->num;

    // Remover o nó e ajustar os ponteiros
    pilha->cabeca->prox = remover->prox;
    remover->prox->ant = pilha->cabeca;
    free(remover);

    return valorRemovido;
}

// Mostrar os elementos da pilha
void mostrarPilha(Pilha pilha) {
    if (pilha.cabeca->prox == pilha.cabeca) {
        printf("\nA pilha esta vazia!\n");
        return;
    }

    No* atual = pilha.cabeca->prox;
    printf("\nPilha: ");
    while (atual != pilha.cabeca) {
        printf("%d ", atual->num);
        atual = atual->prox;
    }
    printf("\n");
}

#include"Lista.h"

// Inicializar a lista circular
void iniciarListaCircular(ListaCircular* lista) {
    lista->cabeca = (No*)malloc(sizeof(No));
    lista->cabeca->prox = lista->cabeca;
    lista->cabeca->ant = lista->cabeca;
}

// Inserir um elemento na lista circular antes de um valor específico
void inserirCircular(ListaCircular* lista, int novoDado, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->num = novoDado;

    No* atual = lista->cabeca->prox;

    while (atual != lista->cabeca) {
        if (atual->num == valor) {
            novo->prox = atual;
            novo->ant = atual->ant;
            atual->ant->prox = novo;
            atual->ant = novo;
            return;
        }
        atual = atual->prox;
    }

    printf("\nValor %d nao encontrado na lista. Inserindo no final.\n", valor);
    novo->prox = lista->cabeca;
    novo->ant = lista->cabeca->ant;
    lista->cabeca->ant->prox = novo;
    lista->cabeca->ant = novo;
}

// Remover um elemento da lista circular
void removerCircular(ListaCircular* lista, int valor) {
    No* atual = lista->cabeca->prox;

    while (atual != lista->cabeca) {
        if (atual->num == valor) {
            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
            free(atual);
            return;
        }
        atual = atual->prox;
    }

    printf("\nElemento %d nao encontrado na lista!\n", valor);
}

// Mostrar os elementos da lista circular
void mostrarListaCircular(ListaCircular lista) {
    if (lista.cabeca->prox == lista.cabeca) {
        printf("A lista circular está vazia!\n");
        return;
    }

    No* atual = lista.cabeca->prox;
    printf("\nLista Circular: ");
    while (atual != lista.cabeca) {
        printf("%d ", atual->num);
        atual = atual->prox;
    }
    printf("\n");
}

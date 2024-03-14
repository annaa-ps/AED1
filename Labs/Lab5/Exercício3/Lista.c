#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Função para criar uma nova lista de prioridade
ListaPrioridade* criar_lista_prioridade() {
    ListaPrioridade* lista = (ListaPrioridade*)malloc(sizeof(ListaPrioridade));
    if (lista == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a lista de prioridade\n");
        exit(EXIT_FAILURE);
    }
    lista->cabeca = NULL;
    return lista;
}

// Função para liberar a memória da lista de prioridade
void destruir_lista_prioridade(ListaPrioridade* lista) {
    if (lista == NULL)
        return;

    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(lista);
}

// Função para inserir um elemento na lista de acordo com a prioridade
void inserir(ListaPrioridade* lista, int valor, int prioridade) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo nó\n");
        exit(EXIT_FAILURE);
    }
    novoNo->valor = valor;
    novoNo->prioridade = prioridade;

    if (lista->cabeca == NULL || prioridade > lista->cabeca->prioridade) {
        novoNo->prox = lista->cabeca;
        lista->cabeca = novoNo;
    } else {
        No* atual = lista->cabeca;
        while (atual->prox != NULL && atual->prox->prioridade >= prioridade) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    }
}

// Função para imprimir a lista de prioridade
void imprimir_lista_prioridade(ListaPrioridade* lista) {
    if (lista == NULL || lista->cabeca == NULL) {
        printf("Lista de prioridade vazia\n");
        return;
    }
    printf("Lista de prioridade:\n");
    No* atual = lista->cabeca;
    while (atual != NULL) {
        printf("Valor: %d, Prioridade: %d\n", atual->valor, atual->prioridade);
        atual = atual->prox;
    }
}

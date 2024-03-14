#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>

// Estrutura do nó da lista
typedef struct No {
    int num;
    struct No* prox;
    struct No* ant;
} No;

// Estrutura da lista
typedef struct {
    No* cabeca;
} ListaCircular;

void iniciarListaCircular(ListaCircular* lista);

void inserirCircular(ListaCircular* lista, int novoDado, int valor);

void removerCircular(ListaCircular* lista, int valor);

void mostrarListaCircular(ListaCircular lista);


#endif // LISTA_H_INCLUDED

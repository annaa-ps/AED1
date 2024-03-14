#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da pilha
typedef struct No {
    int num;
    struct No* prox;
    struct No* ant;
} No;

// Estrutura da pilha
typedef struct {
    No* cabeca;
} Pilha;


void iniciarPilha(Pilha* pilha);

void empilhar(Pilha* pilha, int novoDado);

int desempilhar(Pilha* pilha);

void mostrarPilha(Pilha pilha);


#endif // PILHA_H_INCLUDED

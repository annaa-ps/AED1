#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da fila
typedef struct No {
    int num;
    struct No* prox;
    struct No* ant;
} No;

// Estrutura da fila
typedef struct {
    No* cabeca;
} FilaCircular;

void iniciarFilaCircular(FilaCircular* fila);

void enfileirarCircular(FilaCircular* fila, int novoDado);

int desenfileirarCircular(FilaCircular* fila);

void mostrarFilaCircular(FilaCircular fila);


#endif // FILA_H_INCLUDED

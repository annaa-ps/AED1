#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>

typedef struct No {
    int valor;
    int prioridade;
    struct No* prox;
} No;

typedef struct ListaPrioridade {
    No* cabeca;
} ListaPrioridade;


ListaPrioridade* criar_lista_prioridade();
void destruir_lista_prioridade(ListaPrioridade* lista);
void inserir(ListaPrioridade* lista, int valor, int prioridade);
void imprimir_lista_prioridade(ListaPrioridade* lista);


#endif

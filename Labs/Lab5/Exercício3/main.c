#include "lista.h"

int main() {
    ListaPrioridade* lista = criar_lista_prioridade();

    // Inser��o de elementos na lista de acordo com a prioridade
    inserir(lista, 1, 1);
    inserir(lista, 2, 1);
    inserir(lista, 3, 1);
    inserir(lista, 4, 0);
    inserir(lista, 5, 0);
    inserir(lista, 6, 2);
    inserir(lista, 7, 2);

    // Impress�o da lista de prioridade
    imprimir_lista_prioridade(lista);

    // Libera��o de mem�ria
    destruir_lista_prioridade(lista);

    return 0;
}

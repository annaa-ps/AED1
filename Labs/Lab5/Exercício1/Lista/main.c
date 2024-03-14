#include "Lista.h"

int main() {
    ListaCircular lista;
    int escolha, dado, valor;

    iniciarListaCircular(&lista);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir elemento antes de um valor\n");
        printf("2. Remover elemento\n");
        printf("3. Mostrar lista\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &dado);
                printf("\nDigite o valor antes do qual deseja inserir: ");
                scanf("%d", &valor);
                inserirCircular(&lista, dado, valor);
                break;
            case 2:
                printf("\nDigite o numero a ser removido: ");
                scanf("%d", &valor);
                removerCircular(&lista, valor);
                break;
            case 3:
                mostrarListaCircular(lista);
                break;
            case 4:
                printf("\nSaindo do programa.\n");
                exit(0);
            default:
                printf("\nOpcao invalida!\n");
        }
    }

    return 0;
}

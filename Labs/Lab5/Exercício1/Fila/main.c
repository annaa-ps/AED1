#include"Fila.h"

int main() {
    FilaCircular fila;
    int escolha, dado;

    iniciarFilaCircular(&fila);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Mostrar fila\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("\nDigite o numero a ser enfileirado: ");
                scanf("%d", &dado);
                enfileirarCircular(&fila, dado);
                break;
            case 2:
                printf("\nElemento desenfileirado: %d\n", desenfileirarCircular(&fila));
                break;
            case 3:
                mostrarFilaCircular(fila);
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

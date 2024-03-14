#include"Pilha.h"

int main() {
    Pilha pilha;
    int escolha, dado;

    iniciarPilha(&pilha);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Mostrar pilha\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("\nDigite o numero a ser empilhado: ");
                scanf("%d", &dado);
                empilhar(&pilha, dado);
                break;
            case 2:
                printf("\nElemento desempilhado: %d\n", desempilhar(&pilha));
                break;
            case 3:
                mostrarPilha(pilha);
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

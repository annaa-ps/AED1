#include <stdio.h>
#include <stdlib.h>

int potenciaComRecursao(int base, int expoente) {
    if (expoente == 0)
        return 1;
    else
        return base * potenciaComRecursao(base, expoente - 1);
}

int main() {
    int base, expoente;
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente (nao negativo): ");
    scanf("%d", &expoente);
    if (expoente < 0) {
        printf("O expoente deve ser nao negativo.\n");
        return 1;
    }
    int resultado = potenciaComRecursao(base, expoente);
    printf("%d elevado a %d eh: %d\n", base, expoente, resultado);
    return 0;
}

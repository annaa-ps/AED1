#include <stdio.h>
#include <stdlib.h>

int potenciaSemRecursao(int base, int expoente) {
    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
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
    int resultado = potenciaSemRecursao(base, expoente);
    printf("%d elevado a %d eh: %d\n", base, expoente, resultado);
    return 0;
}

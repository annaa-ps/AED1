#include <stdio.h>
#include <stdlib.h>

int somaSemRecursao(int N) {
    int soma = 0;
    for (int i = 1; i <= N; i++) {
        soma += i;
    }
    return soma;
}

int main() {
    int N;
    printf("Digite um numero inteiro N: ");
    scanf("%d", &N);
    int resultado = somaSemRecursao(N);
    printf("A soma de 1 ate %d eh: %d\n", N, resultado);
    return 0;
}

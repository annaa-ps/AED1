#include <stdio.h>
#include <stdlib.h>

int somaComRecursao(int N) {
    if (N <= 1)
        return N;
    else
        return N + somaComRecursao(N - 1);
}

int main() {
    int N;
    printf("Digite um umero inteiro N: ");
    scanf("%d", &N);
    int resultado = somaComRecursao(N);
    printf("A soma de 1 ate %d eh: %d\n", N, resultado);
    return 0;
}

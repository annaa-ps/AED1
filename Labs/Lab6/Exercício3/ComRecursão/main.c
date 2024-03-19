#include <stdio.h>
#include <stdlib.h>
int fibonacciComRecursao(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacciComRecursao(n - 1) + fibonacciComRecursao(n - 2);
}

int main() {
    int n;
    printf("Digite o valor de n para calcular o n-esimo termo da sequencia de Fibonacci: ");
    scanf("%d", &n);
    printf("O %d-esimo termo da sequencia de Fibonacci eh: %d\n", n, fibonacciComRecursao(n));
    return 0;
}

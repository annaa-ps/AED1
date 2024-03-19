#include <stdio.h>
#include <stdlib.h>

int fibonacciSemRecursao(int n) {
    int a = 0, b = 1, temp;

    if (n == 0)
        return a;
    else if (n == 1)
        return b;

    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

int main() {
    int n;
    printf("Digite o valor de n para calcular o n-esimo termo da sequencia de Fibonacci: ");
    scanf("%d", &n);
    printf("O %d-esimo termo da sequencia de Fibonacci eh: %d\n", n, fibonacciSemRecursao(n));
    return 0;
}

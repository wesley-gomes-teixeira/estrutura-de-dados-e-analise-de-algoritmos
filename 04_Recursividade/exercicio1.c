#include <stdio.h>
int somaNaturais(int n) {
    if (n == 1) {
        return 1;
    }
    return n + somaNaturais(n - 1);
}
int main() {
    int n, resultado;
    printf("Digite um valor para n: ");
    scanf("%d", &n);
    resultado = somaNaturais(n);
    printf("A soma dos primeiros %d números naturais é %d\n", n, resultado);
    return 0;
}
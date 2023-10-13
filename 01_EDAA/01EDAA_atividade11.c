/*11) Calcule e mostre a tabuada de multiplicação de um número informado pelo usuário no
teclado.
Exemplo:
Informe um número: 7*/

#include <stdio.h>


int main() {
    int numero;


    printf("Informe um número, 0 para sair: ");
    scanf("%d", &numero);


    while (numero != 0) {
        printf("Tabuada de multiplicação para %d:\n", numero);
        for (int i = 0; i <= 10; i++) {
            printf("%d x %d = %d\n", numero, i, numero * i);
        }
        printf("Insira outro numero ou digite 0 encerrar: ");
        scanf("%d", &numero);
    }


    printf("Tabuada encerrada!\n");


    return 0;
}

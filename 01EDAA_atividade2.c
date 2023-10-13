/*
*2) Receba o ano de nascimento de uma pessoa, o ano atual e imprima:
*/
a. A idade da pessoa no ano atual.
b. A idade que a pessoa terá em 2050.

#include <stdio.h>


int main() {
    int anoNascimento, anoAtual, idadeAtual, idade2050;


    printf("Digite o ano do seu nascimento: ");
    scanf("%d", &anoNascimento);


    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);


    idadeAtual = anoAtual - anoNascimento;
    idade2050 = 2050 - anoNascimento;


    printf("A idade da pessoa no ano atual é: %d anos\n", idadeAtual);
    printf("A idade da pessoa em 2050 será: %d anos\n", idade2050);


    return 0;
}

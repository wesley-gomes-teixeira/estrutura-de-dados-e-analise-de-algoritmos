/*8) Receba o peso de uma pessoa, calcule e apresente o novo peso:

a. Se a pessoa engordar 15%.
b. Se a pessoa emagrecer 20%.*/

#include <stdio.h>


int main() {
    float pesoAtual, novoPeso;
    char opcao;


    printf("Digite o peso atual da pessoa: ");
    scanf("%f", &pesoAtual);


    /
    printf("Escolha uma opção:\n");
    printf("a) Engordar 15%%\n");
    printf("b) Emagrecer 20%%\n");
    printf("Digite a opção (a/b): ");
    scanf(" %c", &opcao);


   
    if (opcao == 'a' || opcao == 'A') {
        novoPeso = pesoAtual + (0.15 * pesoAtual);
    } else if (opcao == 'b' || opcao == 'B') {
        novoPeso = pesoAtual - (0.20 * pesoAtual);
    }


    printf("O novo peso da pessoa é: %.2f\n", novoPeso);


    return 0;
}

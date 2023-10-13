/*4) Faça um programa que receba o salário de um funcionário, calcule e mostre o novo
salário, sabendo-se que ele teve um aumento de 25%.
*/
#include <stdio.h>


int main() {
    char continuar;
   
    do {
        float salarioAtual, novoSalario;


        printf("Digite o salário atual do funcionário: ");
        scanf("%f", &salarioAtual);


        novoSalario = salarioAtual + (0.25 * salarioAtual);


        printf("O novo salário do funcionário com aumento de 25%% é: R$ %.2f\n", novoSalario);


        printf("Deseja calcular o novo salário novamente? (S/N): ");
        scanf(" %c", &continuar);


    } while (continuar == 'S' || continuar == 's');


    return 0;
}

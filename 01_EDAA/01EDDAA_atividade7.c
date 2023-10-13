/*7) Receba o valor do salário mínimo e o valor do salário de um funcionário. O algoritmo
deve calcular e apresentar a quantidade de salários mínimos que esse funcionário
recebe.*/

#include <stdio.h>


int main() {
    float salarioMinimo, salarioFuncionario, qtdSalariosMinimos;


    printf("Digite o valor do salário mínimo: ");
    scanf("%f", &salarioMinimo);


    printf("Digite o valor do salário do funcionário: ");
    scanf("%f", &salarioFuncionario);


    qtdSalariosMinimos = salarioFuncionario / salarioMinimo;


    printf("O funcionário recebe %.2f salários mínimos.\n", qtdSalariosMinimos);


    return 0;
}

/*
*3) Receba a cotação do dólar em reais e um valor que o usuário possui em dólares.
Imprima este valor em reais.
*/

#include <stdio.h>


int main() {
    float cotacaoDolar, valorDolar, valorReais;
   
    printf("Digite a cotação do dólar em reais: ");
    scanf("%f", &cotacaoDolar);


    printf("Digite o valor em dólares: ");
    scanf("%f", &valorDolar);


    valorReais = cotacaoDolar * valorDolar;


    printf("O valor em reais é: R$ %.2f\n", valorReais);


    return 0;
}

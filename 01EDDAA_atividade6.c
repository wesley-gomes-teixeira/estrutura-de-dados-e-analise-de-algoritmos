/*6) Receba uma temperatura em Celsius, calcule e mostre essa temperatura em Fahrenheit.
OBS: F = (C * 1,8) + 32.*/

#include <stdio.h>


int main() {
    float temperaturaCelsius, temperaturaFahrenheit;


    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &temperaturaCelsius);


    temperaturaFahrenheit = (temperaturaCelsius * 1.8) + 32.0;


    printf("A temperatura em Fahrenheit é: %.2f\n", temperaturaFahrenheit);


    return 0;
}

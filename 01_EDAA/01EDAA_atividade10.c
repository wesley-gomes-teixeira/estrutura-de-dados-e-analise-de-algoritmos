/*10) Receba o raio, calcule e apresente:

a. O comprimento de uma esfera: C = 2 * π * R.
b. A área de uma esfera: A = π * R2
c. O volume de uma esfera: V = 3⁄4 * π * R3*/

#include <stdio.h>
#include <math.h>
int main() {
    float raio, comprimento, area, volume;


    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);


    comprimento = 2.0 * M_PI * raio;
    area = M_PI * raio * raio;
    volume = (3.0 / 4.0) * M_PI * raio * raio * raio;


    printf("Comprimento da esfera: %.2f\n", comprimento);
    printf("Área da esfera: %.2f\n", area);
    printf("Volume da esfera: %.2f\n", volume);


    return 0;
}

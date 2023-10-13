/*9) Receba os valores dos dois catetos de um triângulo, calcule e apresente o valor da
hipotenusa. OBS - Teorema de Pitágoras: a
2 = b2 + c2*/

#include <stdio.h>
#include <math.h>


int main() {
    float catetoA, catetoB, hipotenusa;


    printf("Digite o valor do 1° cateto (a): ");
    scanf("%f", &catetoA);


    printf("Digite o valor do 2° cateto (b): ");
    scanf("%f", &catetoB);


    hipotenusa = sqrt(catetoA * catetoA + catetoB * catetoB);


    printf("O valor da hipotenusa é: %.2f\n", hipotenusa);


    return 0;
}

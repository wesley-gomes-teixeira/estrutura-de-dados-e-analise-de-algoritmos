/*
1) Receba três notas, calcule e apresente a média aritmética delas.
*/
#include <stdio.h>


int main() {
    float nota1, nota2, nota3, media;


    printf("Digite a 1°nota: ");
    scanf("%f", &nota1);


    printf("Digite a 2°nota: ");
    scanf("%f", &nota2);


    printf("Digite a 3°nota: ");
    scanf("%f", &nota3);


   
    media = (nota1 + nota2 + nota3) / 3.0;
   
    printf("A média aritmética das notas é: %.2f\n", media);


    return 0;
}

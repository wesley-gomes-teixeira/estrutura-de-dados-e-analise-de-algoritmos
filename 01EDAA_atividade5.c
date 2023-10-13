/*5) Calcule e apresente a área de um losango. As diagonais maior e menor do losango
devem ser informadas pelo usuário. OBS: AREA = (DIAGONAL MAIOR * DIAGONAL
MENOR) / 2.*/

#include <stdio.h>


int main() {
    float diagonalMaior, diagonalMenor, area;


    printf("Digite o valor da diagonal maior: ");
    scanf("%f", &diagonalMaior);


    printf("Digite o valor da diagonal menor: ");
    scanf("%f", &diagonalMenor);


    area = (diagonalMaior * diagonalMenor) / 2.0;


    printf("A área do losango é: %.2f\n", area);


    return 0;
}

#include <stdio.h>
#include <ctype.h>


int main() {
   int resultado;
   char c;


   printf("Digite um caractere: ");
   scanf(" %c", &c);


   if (islower(c)) {
       printf("Verdadeiro, isso é uma letra minúscula\n");
       resultado = 1;
   } else {
       printf("Falso, isso não é uma letra minúscula\n");
       resultado = 0;
   }


   return 0;
}

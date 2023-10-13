#include <stdio.h>
#include <ctype.h>


int main() {
   int resultado;
   char c;


   printf("Digite um caractere: ");
   scanf(" %c", &c);


   if (isdigit(c)) {
       printf("Verdadeiro, isso é um codigo\n");
       resultado = 1;
   } else {
       printf("Falso, isso não é uma codigo\n");
       resultado = 0;
   }


   return 0;
}

#include <stdio.h>
#include <ctype.h>


int main() {
   int resultado;
   char c;


   printf("Digite um caractere: ");
   scanf(" %c", &c);


   if (isalpha(c)) {
       printf("Verdadeiro, isso é uma letra\n");
       resultado = 1;
   } else {
       printf("Falso, isso não é uma letra\n");
       resultado = 0;
   }


   return 0;
}

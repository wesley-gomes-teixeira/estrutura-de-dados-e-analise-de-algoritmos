#include <stdio.h>
#include <ctype.h>


int main() {
   int resultado;
   char c;


   printf("Digite um caractere: ");
   scanf(" %c", &c);


   if (isalnum(c)) {
       printf("Verdadeiro, isso é uma letra ou um dígito\n");
       return 1;
   } else {
       printf("Falso, isso não é uma letra ou um dígito\n");
       return 0;
   }

}
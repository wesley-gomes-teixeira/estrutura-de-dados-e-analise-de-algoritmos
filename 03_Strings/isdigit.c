#include <stdio.h>
#include <ctype.h>


int main() {
   int resultado;
   char c;


   printf("Digite um caractere: ");
   scanf(" %c", &c);


   if (isdigit(c)) {
       printf("Verdadeiro, isso é um codigo\n");
       return 1;
   } else {
       printf("Falso, isso não é uma codigo\n");
       return 0;
   }

}
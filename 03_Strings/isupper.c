#include <stdio.h>
#include <ctype.h>


int main() {
   int resultado;
   char c;


   printf("Digite um caractere: ");
   scanf(" %c", &c);


   if (isupper(c)) {
       printf("Verdadeiro, isso é uma letra maiúscula\n");
       return 1;
   } else {
       printf("Falso, isso não é uma letra maiúscula\n");
       return 0;
   }

}
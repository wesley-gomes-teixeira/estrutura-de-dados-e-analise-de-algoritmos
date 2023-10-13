#include <stdio.h>
#include <stdlib.h>


#define VERDADEIRO 1
#define FALSO 0


typedef int elemento;


typedef struct nodo *nodo_pt;
typedef struct nodo {
   elemento e;
   nodo_pt prox;
   nodo_pt ant;
} tnodo;


typedef struct tipo_fila {
   nodo_pt inicio, fim;
} fila;


void NewFila (fila *f) {
   f->inicio = NULL;
   f->fim = NULL;
}


int FilaVazia (fila *f) {
   return ((f->inicio == NULL) && (f->fim == NULL));
}


void Enfileirar (fila *f, elemento x) {
   nodo_pt p;
   p = (nodo_pt) malloc (sizeof (tnodo));
   p->e = x;
   p->prox = NULL;
   if (FilaVazia (f)) {
       p->ant = NULL;
       f->inicio = p;
   } else {
       p->ant = f->fim;
       f->fim->prox = p;
   }
   f->fim = p;
}


int main() {
   fila minhaFila;
   NewFila(&minhaFila);


   Enfileirar(&minhaFila, 0);Enfileirar(&minhaFila, 1);Enfileirar(&minhaFila, 2);Enfileirar(&minhaFila, 3);Enfileirar(&minhaFila, 4);


   printf("Elementos na fila: ");
   nodo_pt atual = minhaFila.inicio;
   while (atual != NULL) {
       printf("%d ", atual->e);
       atual = atual->prox;
   }


   return 0;
}
/*
* Vantagens:poder recorrer em ambas direções,  e a remoção do elemento da fila mais eficiente.
* Descantagens: complexidade do codigo e o uso da memoria onde ocupa mais memoria pelo o uso do campo adicionado do ponteiro
*/


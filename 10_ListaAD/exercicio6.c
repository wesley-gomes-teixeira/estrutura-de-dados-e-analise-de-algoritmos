#ifndef LISTA_H
#define LISTA_H

typedef struct nodo {
  elemento e;
  struct nodo *prox;
} pt_nodo;

typedef struct {
  pt_nodo *inicio;
} lista;

void CriarLista (lista *l);
void Desalistar (lista *l);
void Alistar (lista *l, elemento e);
int ListaVazia (lista *l);
pt_nodo *PesquisarLista (lista l, elemento e);

#endif

#include <stdlib.h>
#include "lista.h"

void CriarLista (lista *l) {
  l->inicio = NULL;
}

void Desalistar (lista *l) {
  pt_nodo *p = l->inicio;
  l->inicio = l->inicio->prox;
  free (p);
}

void Alistar (lista *l, elemento e) {
  pt_nodo *novo = malloc (sizeof (pt_nodo));
  novo->e = e;
  novo->prox = l->inicio;
  l->inicio = novo;
}

int ListaVazia (lista *l) {
  return l->inicio == NULL;
}

pt_nodo *PesquisarLista (lista l, elemento e) {
  pt_nodo *p = l.inicio;
  while (p != NULL && p->e != e)
    p = p->prox;
  return p;
}

#include <stdio.h>
#include "lista.h"

int main () {
  char c, op = 's', lixo;
  int i = 0;
  pt_nodo *predecessor = NULL;
  lista list;
  CriarLista (&list);
  srand (time (NULL));
  do {
    c = (char) ((rand () % 26) + 65);
    printf ("\n\n%d) Alistando: %c", i++, c);
    Alistar (&list, &c);
    ImprimirLista (list);
    printf ("\n\nDeseja alistar uma nova letra (s/n)? ");
    scanf ("%c", &op); scanf ("%c", &lixo);
  } while (op == 's');

  system ("clear || cls"); ImprimirLista (list); printf ("\n");
  do {
    printf ("\nInforme a letra a ser substituida: ");
    scanf ("%c", &c);
    scanf ("%c", &lixo);
    predecessor = PesquisarLista (&list, &c);
    if (predecessor != NULL) {
      printf ("\n\nLetra encontrada na posicao: %p", *predecessor);
      Desalistar (predecessor);
      printf ("\n\nInforme a letra substituta: ");
      scanf ("%c", &c); scanf ("%c", &lixo);
      Alistar (predecessor, &c);
      ImprimirLista (list);
    }
    else
      printf ("\n\nLetra nao encontrada!");
    printf ("\n\nDeseja substituir outra letra (s/n)? ");
    scanf ("%c", &op); scanf ("%c", &lixo);
  } while (op == 's');
  system ("clear || cls"); i = 0; ImprimirLista (list); printf ("\n\n");
  while (!ListaVazia (&list)) {
    c = Desalistar (&list);
    printf ("\n%d) Desalistando: %c", i++, c);
    ImprimirLista (list); printf ("\n");
    Esperar (2L);
  }
  printf ("\n\n"); Esperar (6L);
  return 0;
}
#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 15

typedef struct fila {
  int item[MAX];
  int inicio;
  int fim;
} fila;

void CriarFila(fila *f);
int FilaVazia(fila *f);
int FilaCheia(fila *f);
void Enfileirar(fila *f, int x);
int Desenfileirar(fila *f);

void CriarFila(fila *f) {
  f->inicio = 0;
  f->fim = 0;
}

int FilaVazia(fila *f) {
  return (f->inicio == f->fim);
}

int FilaCheia(fila *f) {
  return ((f->fim + 1) % MAX == f->inicio);
}

void Enfileirar(fila *f, int x) {
  if (FilaCheia(f)) {
    f->fim = (f->fim - 1) % MAX;
    f->item[f->fim] = x;
  } else {
    f->item[f->fim] = x;
    f->fim = (f->fim + 1) % MAX;
  }
}

int Desenfileirar(fila *f) {
  int x;

  if (FilaVazia(f)) {
    printf("Fila vazia!\n");
    return -1;
  } else {
    x = f->item[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    return x;
  }
}

#endif

#ifndef FILA_H
#define FILA_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    char *palavra;
    char *sinonimo;
} elemento ;

typedef struct Nodo_str {
    elemento e;
    struct Nodo_str* prox;
} Nodo;

typedef struct {
    Nodo* inicio;
    Nodo* fim;
} Fila;

void CriarFila(Fila* f);
void InserirFila(Fila* f, elemento e);
elemento ExcluirFila(Fila* f);
elemento* PesquisarFila(Fila f, char *chave);

#endif // FILA_H

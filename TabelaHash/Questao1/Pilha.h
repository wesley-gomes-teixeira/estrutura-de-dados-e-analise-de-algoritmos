#ifndef PILHA_H
#define PILHA_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    char *palavra;
    char *sinonimo;
} elemento;

typedef struct Nodo_str {
    elemento e;
    struct Nodo_str* prox;
} Nodo;

typedef Nodo* Pilha;

void CriarPilha(Pilha* p);
void InserirPilha(Pilha* p, elemento e);
elemento ExcluirPilha(Pilha* p);
elemento* PesquisarPilha(Pilha p, char *chave);

#endif // PILHA_H

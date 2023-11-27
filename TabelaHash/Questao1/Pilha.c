#include "Pilha.h"
#include <string.h>

void CriarPilha(Pilha* p) {
    *p = NULL;
}

void InserirPilha(Pilha* p, elemento e) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    novo->e = e;
    novo->prox = *p;
    *p = novo;
}

elemento ExcluirPilha(Pilha* p) {
    if (*p == NULL) {
        printf("Erro: Pilha vazia\n");
        elemento e = {"", ""};
        return e;
    }
    Nodo* temp = *p;
    elemento e = temp->e;
    *p = (*p)->prox;
    free(temp);
    return e;
}

elemento* PesquisarPilha(Pilha p, char *chave) {
    while (p != NULL) {
        if (strcmp(p->e.palavra, chave) == 0) {
            return &(p->e);
        }
        p = p->prox;
    }
    return NULL;
}

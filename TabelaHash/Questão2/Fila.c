#include "Fila.h"
#include <string.h>

void CriarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void InserirFila(Fila* f, elemento e) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return;
    }
    novo->e = e;
    novo->prox = NULL;
    if (f->fim != NULL) {
        f->fim->prox = novo;
    }
    f->fim = novo;
    if (f->inicio == NULL) {
        f->inicio = novo;
    }
}

elemento ExcluirFila(Fila* f) {
    if (f->inicio == NULL) {
        printf("Erro: Fila vazia\n");
        elemento e = {"", ""};
        return e;
    }
    Nodo* temp = f->inicio;
    elemento e = temp->e;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return e;
}

elemento* PesquisarFila(Fila f, char *chave) {
    Nodo* p = f.inicio;
    while (p != NULL) {
        if (strcmp(p->e.palavra, chave) == 0) {
            return &(p->e);
        }
        p = p->prox;
    }
    return NULL;
}

#include <stdio.h>

#define TAM 100

// Definindo o tipo de elemento (pode ser alterado conforme sua necessidade)
typedef int elemento;

struct tipo_lista {
    elemento vet[TAM];
    int inicio, fim;
};
typedef struct tipo_lista lista;

void CriarLista(lista *l) {
    (*l).inicio = -1;
    (*l).fim = -1;
}

int ListaVazia(lista *l) {
    return ((*l).inicio == -1 && (*l).fim == -1);
}

int ListaCheia(lista *l) {
    return ((*l).fim == TAM - 1);
}

void Alistar(lista *l, elemento e, int pos) {
    int i;
    if (ListaCheia(l)) {
        printf("\n ERRO: lista cheia!");
    } else if (pos < (*l).inicio || pos > (*l).fim + 1) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [%d, %d].", (*l).inicio, (*l).fim);
    } else {
        for (i = (*l).fim; i >= pos; i--) {
            (*l).vet[i + 1] = (*l).vet[i];
        }
        (*l).vet[pos] = e;
        if (ListaVazia(l)) {
            (*l).inicio = 0;
        }
        (*l).fim++;
    }
}

elemento Desalistar(lista *l, int pos) {
    int i;
    elemento e;
    if (ListaVazia(l)) {
        printf("\n ERRO: lista vazia!");
        return (elemento)0;
    } else if (pos < (*l).inicio || pos > (*l).fim) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [%d, %d].", (*l).inicio, (*l).fim);
        return (elemento)0;
    } else {
        e = (*l).vet[pos];
        for (i = pos; i < (*l).fim; i++) {
            (*l).vet[i] = (*l).vet[i + 1];
        }
        (*l).fim--;
        if ((*l).inicio == (*l).fim + 1) {
            (*l).inicio = -1;
            (*l).fim = -1;
        }
        return e;
    }
}

void ImprimeLista(lista *l) {
    if (ListaVazia(l)) {
        printf("A lista está vazia.\n");
    } else {
        printf("Conteúdo da lista:\n");
        for (int i = (*l).inicio; i <= (*l).fim; i++) {
            printf("%d: %d\n", i, (*l).vet[i]);
        }
    }
}

int main() {
    lista l;
    CriarLista(&l);

    Alistar(&l, 42, 0);
    Alistar(&l, 23, 1);
    Alistar(&l, 15, 0);

    ImprimeLista(&l);

    Desalistar(&l, 0);

    ImprimeLista(&l);

    return 0;
}

#include <stdio.h>
#define VERDADEIRO 1
#define FALSO 0

#define TAM 50

struct tipo_fila {
    int vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;

void CriarFila(fila *f) {
    (*f).inicio = -1;
    (*f).fim = -1;
}

int FilaVazia(fila *f) {
    return ((*f).inicio == -1 && (*f).fim == -1);
}

int FilaCheia(fila *f) {
    return ((*f).fim == TAM - 1);
}

void Enfileirar(fila *f, int numero) {
    if (FilaCheia(f)) {
        printf("Fila cheia. Não é possível enfileirar.\n");
    } else {
        if (FilaVazia(f)) {
            (*f).inicio = 0;
        }
        (*f).vet[++(*f).fim] = numero;
    }
}

int Desenfileirar(fila *f) {
    int numero;
    if (!FilaVazia(f)) {
        numero = (*f).vet[(*f).inicio++];
    } else {
        printf("Não é possível desenfileirar, pois a fila esta vazia.\n");
        numero = -1;
    }
    return numero;
}

void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("A fila está vazia.\n");
    } else {
        printf("Conteúdo da fila:\n");
        for (int i = (*f).inicio; i <= (*f).fim; i++) {
            printf("%d ", (*f).vet[i]);
        }
        printf("\n");
    }
}

int main() {
    fila f;
    int numero;
    CriarFila(&f);

    numero = 10;
    Enfileirar(&f, numero);
    numero = 20;
    Enfileirar(&f, numero);

    numero = Desenfileirar(&f);
    printf("Elemento desenfileirado: %d\n", numero);
    numero = Desenfileirar(&f);
    printf("Elemento desenfileirado: %d\n", numero);

    return 0;
}

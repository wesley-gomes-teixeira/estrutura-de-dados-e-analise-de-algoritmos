#include <stdio.h>

typedef struct {
    int tamanho;
    int elementos[10];
} Deque;

void criarDeque(Deque *deque) {
    deque->tamanho = 0;
}

void pushFront(Deque *deque, int valor) {
    if (deque->tamanho == 10) {
        printf("O deque está cheio.\n");
        return;
    }

    deque->elementos[deque->tamanho] = valor;
    deque->tamanho++;
}

void pushBack(Deque *deque, int valor) {
    if (deque->tamanho == 10) {
        printf("O deque está cheio.\n");
        return;
    }

    deque->elementos[deque->tamanho - 1] = valor;
    deque->tamanho++;
}

int popFront(Deque *deque) {
    if (deque->tamanho == 0) {
        printf("O deque está vazio.\n");
        return -1;
    }

    int valor = deque->elementos[0];
    deque->elementos[0] = 0;
    deque->tamanho--;

    return valor;
}

int popBack(Deque *deque) {
    if (deque->tamanho == 0) {
        printf("O deque está vazio.\n");
        return -1;
    }

    int valor = deque->elementos[deque->tamanho - 1];
    deque->elementos[deque->tamanho - 1] = 0;
    deque->tamanho--;

    return valor;
}

int front(Deque *deque) {
    if (deque->tamanho == 0) {
        printf("O deque está vazio.\n");
        return -1;
    }

    return deque->elementos[0];
}

int back(Deque *deque) {
    if (deque->tamanho == 0) {
        printf("O deque está vazio.\n");
        return -1;
    }

    return deque->elementos[deque->tamanho - 1];
}

void liberarDeque(Deque *deque) {
    // Não é necessário liberar a memória dos elementos do deque, pois eles são inicializados com o valor 0.
    // Basta limpar o campo tamanho para indicar que o deque está vazio.
    deque->tamanho = 0;
}

int main() {
    Deque deque;
    criarDeque(&deque);

    // Insere 3 elementos no início do deque
    pushFront(&deque, 3);
    pushFront(&deque, 2);
    pushFront(&deque, 1);

    // Imprime o conteúdo do deque
    printf("Conteúdo do deque:\n");
    for (int i = 0; i < deque.tamanho; i++) {
        printf("%d ", deque.elementos[i]);
    }
    printf("\n");

    // Remove o primeiro elemento do deque
    int valor = popFront(&deque);
    printf("Removendo elemento do início: %d\n", valor);

    // Remove o último elemento do deque
    valor = popBack(&deque);
    printf("Removendo elemento do final: %d\n", valor);

    // Imprime o conteúdo do deque
    printf("Conteúdo do deque:\n");
    for (int i = 0; i < deque.tamanho; i++) {
        printf("%d ", deque.elementos[i]);
    }
    printf("\n");

    // Libera o deque
    liberarDeque(&deque);

    return 0;
}

#ifndef DEQUE_H
#define DEQUE_H

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Deque;

void criarDeque(Deque *deque);
int vazio(Deque *deque);
void pushFront(Deque *deque, int valor);
void pushBack(Deque *deque, int valor);
int popFront(Deque *deque);
int popBack(Deque *deque);
int front(Deque *deque);
int back(Deque *deque);
int tamanho(Deque *deque);
void imprimirDeque(Deque *deque);
void liberarDeque(Deque *deque);

#endif

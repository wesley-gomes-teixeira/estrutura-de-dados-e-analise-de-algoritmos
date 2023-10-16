#ifndef PILHA_H
#define PILHA_H

// Definição de uma estrutura para representar um livro
typedef struct {
    char titulo[100];
    char autor[100];
    int edicao;
} Livro;

// Definição de uma estrutura para representar um nó na pilha duplamente encadeada
typedef struct Node {
    Livro livro;
    struct Node* anterior;
    struct Node* proximo;
} Node;

// Definição de uma estrutura para representar a pilha duplamente encadeada
typedef struct {
    Node* topo;
} Pilha;

// Função para criar uma pilha duplamente encadeada vazia
void criarPilha(Pilha* pilha);

// Função para empilhar um livro na pilha duplamente encadeada
void empilharLivro(Pilha* pilha, Livro livro);

// Função para desempilhar um livro da pilha duplamente encadeada
Livro desempilharLivro(Pilha* pilha);

// Função para imprimir o conteúdo da pilha duplamente encadeada na tela
void imprimirPilha(Pilha* pilha);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Pilha pilha;
    criarPilha(&pilha);

    // Exercício 1: Empilhando livros
    Livro livro1 = {"Livro 1", "Autor 1", 1};
    Livro livro2 = {"Livro 2", "Autor 2", 2};
    Livro livro3 = {"Livro 3", "Autor 3", 3};

    empilharLivro(&pilha, livro1);
    empilharLivro(&pilha, livro2);
    empilharLivro(&pilha, livro3);

    // Exercício 2: Imprimindo a pilha
    printf("Conteúdo da pilha duplamente encadeada:\n");
    imprimirPilha(&pilha);

    return 0;
}



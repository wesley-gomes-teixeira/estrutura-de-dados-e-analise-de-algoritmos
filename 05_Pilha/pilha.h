// pilha.h

#ifndef _PILHA_H_
#define _PILHA_H_

#include <stdio.h> // Inclua a diretiva de inclusão para a biblioteca padrão de entrada e saída

#define MAX_TAM 100

// Estrutura de dados para a pilha
typedef struct {
    int topo;            // Índice do topo da pilha
    int elementos[MAX_TAM]; // Array para armazenar os elementos da pilha
} Pilha;

// Procedimento para criar uma pilha vazia
void CriaPilha(Pilha *pilha) {
    pilha->topo = -1; // Inicializa o topo com -1
}

// Função para verificar se a pilha está vazia
int PilhaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

// Função para verificar se a pilha está cheia
int PilhaCheia(Pilha *pilha) {
    return (pilha->topo == MAX_TAM - 1);
}

// Procedimento para empilhar um elemento na pilha
void Empilha(Pilha *pilha, int elemento) {
    if (!PilhaCheia(pilha)) {
        pilha->elementos[++pilha->topo] = elemento;
    } else {
        printf("Erro: Pilha cheia.\n");
    }
}

// Função para desempilhar um elemento da pilha
int Desempilha(Pilha *pilha) {
    if (!PilhaVazia(pilha)) {
        return pilha->elementos[pilha->topo--];
    } else {
        printf("Erro: Pilha vazia.\n");
        return -1; // Valor de erro
    }
}

// Procedimento para imprimir o conteúdo da pilha
void ImprimePilha(Pilha *pilha) {
    int i;
    if (PilhaVazia(pilha)) {
        printf("Pilha vazia.\n");
    } else {
        printf("Conteúdo da pilha:\n");
        for (i = 0; i <= pilha->topo; i++) {
            printf("%d ", pilha->elementos[i]);
        }
        printf("\n");
    }
}

#endif // _PILHA_H_

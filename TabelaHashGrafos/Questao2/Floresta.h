#ifndef FLORESTA_H
#define FLORESTA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct Arvore {
    No* raiz;
} Arvore;

typedef struct Floresta {
    Arvore** arvores;
    char** categorias;
    int tamanho;
} Floresta;

No* criarNo(int valor);
Arvore* criarArvore();
Floresta* criarFloresta();
void liberarFloresta(Floresta* floresta);
void inserir(Arvore* arvore, int valor);
void remover(Arvore* arvore, int valor);
No* pesquisar(Arvore* arvore, int valor);
void preOrdem(No* no);
void emOrdem(No* no);
void posOrdem(No* no);
void inserirArvore(Floresta* floresta, char* categoria);
Arvore* obterArvore(Floresta* floresta, char* categoria);

#endif // FLORESTA_H

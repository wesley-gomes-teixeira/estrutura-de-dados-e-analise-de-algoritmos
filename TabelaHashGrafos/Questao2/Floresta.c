#include "Floresta.h"

No* criarNo(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

Arvore* criarArvore() {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

Floresta* criarFloresta() {
    Floresta* floresta = (Floresta*)malloc(sizeof(Floresta));
    floresta->arvores = NULL;
    floresta->categorias = NULL;
    floresta->tamanho = 0;
    return floresta;
}

void liberarArvore(No* no) {
    if (no != NULL) {
        liberarArvore(no->esquerda);
        liberarArvore(no->direita);
        free(no);
    }
}

void liberarFloresta(Floresta* floresta) {
    for (int i = 0; i < floresta->tamanho; i++) {
        liberarArvore(floresta->arvores[i]->raiz);
        free(floresta->categorias[i]);
        free(floresta->arvores[i]);
    }
    free(floresta->categorias);
    free(floresta->arvores);
    free(floresta);
}

No* inserirAux(No* no, int valor) {
    if (no == NULL) {
        return criarNo(valor);
    }
    if (valor < no->valor) {
        no->esquerda = inserirAux(no->esquerda, valor);
    } else if (valor > no->valor) {
        no->direita = inserirAux(no->direita, valor);
    }
    return no;
}

void inserir(Arvore* arvore, int valor) {
    arvore->raiz = inserirAux(arvore->raiz, valor);
}

No* minimoAux(No* no) {
    No* atual = no;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* removerAux(No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }
    if (valor < raiz->valor) {
        raiz->esquerda = removerAux(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = removerAux(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        No* temp = minimoAux(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = removerAux(raiz->direita, temp->valor);
    }
    return raiz;
}

void remover(Arvore* arvore, int valor) {
    arvore->raiz = removerAux(arvore->raiz, valor);
}

No* pesquisarAux(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    if (raiz->valor < valor) {
        return pesquisarAux(raiz->direita, valor);
    }
    return pesquisarAux(raiz->esquerda, valor);
}

No* pesquisar(Arvore* arvore, int valor) {
    return pesquisarAux(arvore->raiz, valor);
}


void preOrdem(No* no) {
    if (no != NULL) {
        printf("%d ", no->valor);
        preOrdem(no->esquerda);
        preOrdem(no->direita);
    }
}

void emOrdem(No* no){
    if (no != NULL){
        preOrdem(no->esquerda);
        printf("%d ", no->valor);
        preOrdem(no->direita);
    }
}


void posOrdem(No* no) {
    if (no != NULL) {
        posOrdem(no->esquerda);
        posOrdem(no->direita);
        printf("%d ", no->valor);
    }
}


void inserirArvore(Floresta* floresta, char* categoria) {
    floresta->arvores = (Arvore**)realloc(floresta->arvores, sizeof(Arvore*) * (floresta->tamanho + 1));
    floresta->categorias = (char**)realloc(floresta->categorias, sizeof(char*) * (floresta->tamanho + 1));
    floresta->arvores[floresta->tamanho] = criarArvore();
    floresta->categorias[floresta->tamanho] = strdup(categoria);
    floresta->tamanho++;
}

Arvore* obterArvore(Floresta* floresta, char* categoria) {
    for (int i = 0; i < floresta->tamanho; i++) {
        if (strcmp(floresta->categorias[i], categoria) == 0) {
            return floresta->arvores[i];
        }
    }
    return NULL;
}

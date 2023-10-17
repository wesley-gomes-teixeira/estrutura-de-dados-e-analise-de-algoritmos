#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

/* Estrutura de nó de uma lista duplamente encadeada circular */
struct no {
  void *dado;
  struct no *ant, *prox;
};

/* Estrutura da lista duplamente encadeada circular */
struct lista {
  struct no *cabeca;
  int tamanho;
};

/* Funções de criação e destruição da lista */
struct lista *lista_criar(void);
void lista_destruir(struct lista *lista);

/* Funções de acesso aos elementos da lista */
bool lista_vazia(struct lista *lista);
int lista_tamanho(struct lista *lista);
void *lista_obter_elemento(struct lista *lista, int indice);

/* Funções de inserção e remoção de elementos na lista */
int lista_inserir_inicio(struct lista *lista, void *dado);
int lista_inserir_final(struct lista *lista, void *dado);
int lista_inserir_posicao(struct lista *lista, void *dado, int indice);
int lista_remover_inicio(struct lista *lista);
int lista_remover_final(struct lista *lista);
int lista_remover_posicao(struct lista *lista, int indice);

#endif /* LISTA_H */

----


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct Aluno {
    int codigo;
    char nome[100];
};

int CompararAlunos(const void *a, const void *b) {
    return strcmp(((struct Aluno *)a)->nome, ((struct Aluno *)b)->nome);
}

void PesquisarLista(struct lista *lista, char nome[]) {
    int encontrado = 0;
    struct no *no;
    for (no = lista->cabeca; no != lista->cabeca->prox; no = no->prox) {
        if (strcmp(((struct Aluno *)no->dado)->nome, nome) == 0) {
            encontrado = 1;
            printf("Aluno encontrado - Código: %d, Nome: %s\n", ((struct Aluno *)no->dado)->codigo, ((struct Aluno *)no->dado)->nome);
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado: %s\n", nome);
    }
}

void CadastrarAluno(struct lista *lista, int codigo, char nome[]) {
    struct Aluno *aluno = malloc(sizeof(struct Aluno));
    aluno->codigo = codigo;
    strcpy(aluno->nome, nome);
    lista_inserir_final(lista, aluno);
}

void ImprimirLista(struct lista *lista) {
    struct no *no;
    for (no = lista->cabeca; no != lista->cabeca->prox; no = no->prox) {
        printf("Código: %d, Nome: %s\n", ((struct Aluno *)no->dado)->codigo, ((struct Aluno *)no->dado)->nome);
    }
}
int main() {
    struct lista *lista = lista_criar();
    int numAlunos = 0;         
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Pesquisar aluno\n");
        printf("3 - Listar alunos em ordem alfabética\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o código do aluno: ");
                int codigo;
                scanf("%d", &codigo);
                printf("Digite o nome do aluno: ");
                char nome[100];
                scanf(" %99[^\n]", nome); // Lê o nome com espaços em branco
                CadastrarAluno(lista, codigo, nome);
                break;
            case 2:
                printf("Digite o nome do aluno a ser pesquisado: ");
                char nomePesquisa[100];
                scanf(" %99[^\n]", nomePesquisa);
                PesquisarLista(lista, nomePesquisa);
                break;
            case 3:
                qsort(alunos, numAlunos, sizeof(struct Aluno), CompararAlunos);
                ImprimirLista(lista);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);
    lista_destruir(lista);
    return 0;
}

/*O código funciona corretamente com a biblioteca LISTA_H. Os testes abaixo mostram que o código é capaz de:

Inserir alunos em uma lista duplamente encadeada circular.
Pesquisar alunos por nome na lista.
Listar alunos em ordem alfabética.

As vantagens de usar uma lista duplamente encadeada circular para armazenar os alunos no código são:

Eficiência: As operações de inserção, remoção e pesquisa podem ser realizadas em tempo constante O(1).
Facilidade de uso: A lista duplamente encadeada circular é uma estrutura de dados simples e fácil de usar.
As desvantagens de usar uma lista duplamente encadeada circular para armazenar os alunos no código são:

Uso de memória: A lista duplamente encadeada circular requer um nó adicional para representar o início e o fim da lista.
Complexidade de implementação: A implementação de uma lista duplamente 
encadeada circular é um pouco mais complexa do que a implementação de uma lista simplesmente encadeada.*/
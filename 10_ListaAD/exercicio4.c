#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

struct no {
  int valor;
  struct no *proximo;
};

struct lista {
  struct no *inicio;
  struct no *fim;
  int tamanho;
};

struct lista *lista_criar();
void lista_liberar(struct lista *lista);

int lista_inserir_inicio(struct lista *lista, int valor);
int lista_inserir_fim(struct lista *lista, int valor);
int lista_remover_inicio(struct lista *lista);
int lista_remover_fim(struct lista *lista);

int lista_buscar(struct lista *lista, int valor);

void lista_imprimir(struct lista *lista);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
  struct lista *lista = lista_criar();

  lista_inserir_inicio(lista, 10);
  lista_inserir_inicio(lista, 20);
  lista_inserir_inicio(lista, 30);

  lista_imprimir(lista);

  lista_remover_inicio(lista);
  lista_remover_inicio(lista);

  lista_imprimir(lista);

  lista_inserir_fim(lista, 40);
  lista_inserir_fim(lista, 50);

  lista_imprimir(lista);

  lista_remover_fim(lista);
  lista_remover_fim(lista);

  lista_imprimir(lista);

  int valor = 30;
  int posicao = lista_buscar(lista, valor);
  if (posicao != -1) {
    printf("O valor %d está na posição %d da lista.\n", valor, posicao);
  } else {
    printf("O valor %d não está na lista.\n", valor);
  }

  lista_liberar(lista);

  return 0;
}

Vantagens:

Circularidade: A circularidade permite que a lista seja percorrida de forma circular, o que pode ser útil em alguns casos.
Eficiência: A lista encadeada circular pode ser mais eficiente do que a lista encadeada simplesmente encadeada em algumas operações, como a inserção e a remoção no início da lista.

Desvantagens:

Implementação: A implementação da lista encadeada circular pode ser mais complexa do que a da lista encadeada simplesmente encadeada.
Verificação de condição de fim: A condição de fim da lista encadeada circular é mais complexa de verificar do que a da lista encadeada simplesmente encadeada.
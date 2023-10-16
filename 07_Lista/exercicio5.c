#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} ListaInteiros;

void inicializarLista(ListaInteiros *lista) {
    lista->tamanho = 0;
}

void inserirElemento(ListaInteiros *lista, int elemento) {
    if (lista->tamanho < MAX_SIZE) {
        lista->elementos[lista->tamanho] = elemento;
        lista->tamanho++;
    } else {
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
    }
}

void imprimirLista(ListaInteiros *lista) {
    printf("Lista de elementos: ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

int main() {
    ListaInteiros lista;
    inicializarLista(&lista);
    
    int elemento;
    int posicao;
    int opcao;

    printf("Insira 10 números inteiros na lista:\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &elemento);
        inserirElemento(&lista, elemento);
    }

    do {
        imprimirLista(&lista);

        printf("Digite a posição (1 a %d) para retirar um elemento (ou 0 para sair): ", lista.tamanho);
        scanf("%d", &posicao);

        if (posicao == 0) {
            break;
        } else if (posicao < 1 || posicao > lista.tamanho) {
            printf("Posição inválida. Tente novamente.\n");
        } else {
            int elementoRetirado = lista.elementos[posicao - 1];
            for (int i = posicao - 1; i < lista.tamanho - 1; i++) {
                lista.elementos[i] = lista.elementos[i + 1];
            }
            lista.tamanho--;
            printf("Elemento retirado: %d\n", elementoRetirado);
        }
    } while (lista.tamanho > 0);

    printf("Fim da execução.\n");

    return 0;
}

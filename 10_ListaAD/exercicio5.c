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

/*O teste da biblioteca lista.h pode ser feito usando o código do teste da biblioteca lista.h original.
 O código funcionará da mesma forma, pois as operações de inserção, remoção e pesquisa são as mesmas para ambas as bibliotecas.

Vantagens:
Eficiência: As operações de inserção, remoção e pesquisa são eficientes, pois não é necessário percorrer a lista 
inteira para encontrar o elemento desejado.
Conveniência: É possível percorrer a lista em ambas as direções, o que pode ser útil em alguns casos.


Desvantagens:
Uso de memória: Se a lista for pequena, o uso de um nó extra pode não ser significativo. No entanto,
se a lista for grande, o uso de memória extra pode ser significativo.
Complexidade: A complexidade adicional da implementação de uma lista duplamente encadeada circular pode 
ser um problema se o código for executado em um ambiente de tempo real ou se a eficiência for crítica.*/
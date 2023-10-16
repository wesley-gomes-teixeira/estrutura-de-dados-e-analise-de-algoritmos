#include <stdio.h>
#include <stdlib.h>

// Definição de uma estrutura para representar um livro
typedef struct {
    char titulo[100];
    char autor[100];
    int edicao;
} Livro;

// Definição de uma estrutura para representar um nó na pilha
typedef struct Node {
    Livro livro;
    struct Node* proximo;
} Node;

// Função para criar um nó
Node* criarNode(Livro livro) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode != NULL) {
        novoNode->livro = livro;
        novoNode->proximo = NULL;
    }
    return novoNode;
}

// Definição de uma estrutura para representar a pilha
typedef struct {
    Node* topo;
} Pilha;

// Função para criar uma pilha vazia
void criarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

// Função para empilhar um livro na pilha
void empilharLivro(Pilha* pilha, Livro livro) {
    Node* novoNode = criarNode(livro);
    if (novoNode != NULL) {
        novoNode->proximo = pilha->topo;
        pilha->topo = novoNode;
    }
}

// Função para desempilhar um livro da pilha
Livro desempilharLivro(Pilha* pilha) {
    if (pilha->topo != NULL) {
        Node* topoAntigo = pilha->topo;
        pilha->topo = topoAntigo->proximo;
        Livro livroDesempilhado = topoAntigo->livro;
        free(topoAntigo);
        return livroDesempilhado;
    } else {
        Livro livroVazio;
        livroVazio.titulo[0] = '\0';
        livroVazio.autor[0] = '\0';
        livroVazio.edicao = 0;
        return livroVazio;
    }
}

// Função para imprimir o conteúdo da pilha na tela
void imprimirPilha(Pilha* pilha) {
    Node* atual = pilha->topo;
    printf("Conteúdo da pilha:\n");
    while (atual != NULL) {
        printf("Título: %s\nAutor: %s\nEdição: %d\n\n", atual->livro.titulo, atual->livro.autor, atual->livro.edicao);
        atual = atual->proximo;
    }
}

int main() {
    Pilha pilha;
    criarPilha(&pilha);
    
    int opcao;
    do {
        printf("Opções:\n");
        printf("1. Empilhar livro\n");
        printf("2. Desempilhar livro\n");
        printf("3. Imprimir pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        if (opcao == 1) {
            Livro novoLivro;
            printf("Digite o título do livro: ");
            scanf(" %[^\n]s", novoLivro.titulo);
            printf("Digite o autor do livro: ");
            scanf(" %[^\n]s", novoLivro.autor);
            printf("Digite a edição do livro: ");
            scanf("%d", &novoLivro.edicao);
            empilharLivro(&pilha, novoLivro);
        } else if (opcao == 2) {
            Livro livroDesempilhado = desempilharLivro(&pilha);
            printf("Livro desempilhado:\n");
            printf("Título: %s\nAutor: %s\nEdição: %d\n\n", livroDesempilhado.titulo, livroDesempilhado.autor, livroDesempilhado.edicao);
        } else if (opcao == 3) {
            imprimirPilha(&pilha);
        }
    } while (opcao != 4);
    
    return 0;
}

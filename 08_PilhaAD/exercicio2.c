#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Definição de uma estrutura para representar a pilha
typedef struct {
    Node* topo;
} Pilha;

// Função para criar um nó
Node* criarNode(Livro livro) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode != NULL) {
        novoNode->livro = livro;
        novoNode->proximo = NULL;
    }
    return novoNode;
}

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

// Função para imprimir o conteúdo da pilha em um arquivo binário
void imprimirPilhaEmArquivo(Pilha* pilha, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita binária.\n");
        return;
    }
    
    Node* atual = pilha->topo;
    while (atual != NULL) {
        fwrite(&(atual->livro), sizeof(Livro), 1, arquivo);
        atual = atual->proximo;
    }
    
    fclose(arquivo);
}

// Função para ler o conteúdo do arquivo binário e empilhar na pilha
void lerArquivoParaPilha(Pilha* pilha, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura binária.\n");
        return;
    }
    
    Livro livroLido;
    while (fread(&livroLido, sizeof(Livro), 1, arquivo) == 1) {
        empilharLivro(pilha, livroLido);
    }
    
    fclose(arquivo);
}

// Função para calcular quantos livros precisam ser desempilhados para encontrar um livro desejado
int encontrarLivro(Pilha* pilha, const char* tituloDesejado) {
    int passos = 0;
    Pilha pilhaAux;
    criarPilha(&pilhaAux);

    while (pilha->topo != NULL) {
        Livro livroAtual = desempilharLivro(pilha);
        empilharLivro(&pilhaAux, livroAtual);
        passos++;

        if (strcmp(livroAtual.titulo, tituloDesejado) == 0) {
            while (pilhaAux.topo != NULL) {
                empilharLivro(pilha, desempilharLivro(&pilhaAux));
            }
            return passos;
        }
    }

    while (pilhaAux.topo != NULL) {
        empilharLivro(pilha, desempilharLivro(&pilhaAux));
    }
    return -1; // Livro não encontrado
}

int main() {
    Pilha pilha;
    criarPilha(&pilha);
    
    int opcao;
    char nomeArquivo[100];
    
    do {
        printf("Opções:\n");
        printf("1. Empilhar livro\n");
        printf("2. Desempilhar livro\n");
        printf("3. Imprimir pilha na tela\n");
        printf("4. Imprimir pilha em arquivo binário\n");
        printf("5. Ler pilha de arquivo binário\n");
        printf("6. Encontrar livro por título\n");
        printf("7. Sair\n");
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
        } else if

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    int codigo;
    char nome[100];
};

int CompararAlunos(const void *a, const void *b) {
    return strcmp(((struct Aluno *)a)->nome, ((struct Aluno *)b)->nome);
}

void PesquisarLista(struct Aluno alunos[], int n, char nome[]) {
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            encontrado = 1;
            printf("Aluno encontrado - Código: %d, Nome: %s\n", alunos[i].codigo, alunos[i].nome);
            break;
        }
    }
    if (!encontrado) {
        printf("Aluno não encontrado: %s\n", nome);
    }
}

void CadastrarAluno(struct Aluno alunos[], int *n, int codigo, char nome[]) {
    struct Aluno novoAluno;
    novoAluno.codigo = codigo;
    strcpy(novoAluno.nome, nome);
    alunos[*n] = novoAluno;
    (*n)++;
}

void ImprimirLista(struct Aluno alunos[], int n) {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < n; i++) {
        printf("Código: %d, Nome: %s\n", alunos[i].codigo, alunos[i].nome);
    }
}
int main() {
    struct Aluno alunos[100];  
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
                CadastrarAluno(alunos, &numAlunos, codigo, nome);
                break;
            case 2:
                printf("Digite o nome do aluno a ser pesquisado: ");
                char nomePesquisa[100];
                scanf(" %99[^\n]", nomePesquisa);
                PesquisarLista(alunos, numAlunos, nomePesquisa);
                break;
            case 3:
                qsort(alunos, numAlunos, sizeof(struct Aluno), CompararAlunos);
                ImprimirLista(alunos, numAlunos);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);
    return 0;
}
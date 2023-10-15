#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0

#define TAM 11 

struct tipo_fila {
    float vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;

void CriarFila(fila *f) {
    (*f).inicio = -1; 
    (*f).fim = -1; }

int FilaVazia(fila *f) {
    return ((*f).inicio == -1 && (*f).fim == -1);
}

int FilaCheia(fila *f) {
    return ((*f).fim == TAM - 1); 
}

void Enfileirar(fila *f, float numero) {
    if (FilaCheia(f)) {
        printf("Fila cheia. Não é possível enfileirar.\n");
    } else {
        if (FilaVazia(f)) {
            (*f).inicio = 0;
        }
        (*f).vet[++(*f).fim] = numero;
    }
}

float Desenfileirar(fila *f) {
    float numero;
    if (!FilaVazia(f)) {
        numero = (*f).vet[(*f).inicio++];
    } else {
        printf("Fila vazia. Não é possível desenfileirar.\n");
        numero = -1;
    }
    return numero;
}

void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("A fila está vazia.\n");
    } else {
        printf("Conteúdo da fila:\n");
        for (int i = (*f).inicio; i <= (*f).fim; i++) {
            printf("%.2f ", (*f).vet[i]);
        }
        printf("\n");
    }
}

void LerSequencia(fila *f) {
    float numero;

    for (int i = 0; i < 10; i++) {
        printf("Digite um número real: ");
        scanf("%f", &numero);
        Enfileirar(f, numero);
    }
}

void GravarArquivo(fila *f, char *nome_arquivo) {
    FILE *arquivo;
    float numero;

    arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (!FilaVazia(f)) {
        numero = Desenfileirar(f);
        fprintf(arquivo, "%.2f\n", numero);
    }

    fclose(arquivo);
}

void LerArquivo(fila *f, char *nome_arquivo) {
    FILE *arquivo;
    float numero;

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (!feof(arquivo)) {
        fscanf(arquivo, "%f", &numero);
        Enfileirar(f, numero);
    }

    fclose(arquivo);
}

int main() {
    fila f;
    int opcao;
    char nome_arquivo[20];

    CriarFila(&f);

    do {
        printf("1 - Ler uma seqüência de números\n");
        printf("2 - Gravar em arquivo\n");
        printf("3 - Ler de arquivo\n");
        printf("4 - Imprimir\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                LerSequencia(&f);
                break;
            case 2:
                printf("Digite o nome do arquivo: ");
                scanf("%s", nome_arquivo);
                GravarArquivo(&f, nome_arquivo);
                break;
            case 3:
                printf("Digite o nome do arquivo: ");
                scanf("%s", nome_arquivo);
                LerArquivo(&f, nome_arquivo);
                break;
            case 4:
                ImprimeFila(&f);
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
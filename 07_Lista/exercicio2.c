#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct {
    float vet[TAM];
    int inicio, fim;
} ListaReais;

void CriarLista(ListaReais *l) {
    (*l).inicio = 0;
    (*l).fim = 0;
}

int ListaVazia(ListaReais *l) {
    return ((*l).inicio == (*l).fim);
}

int ListaCheia(ListaReais *l) {
    return ((*l).fim == TAM);
}

void Enfileirar(ListaReais *l, float num) {
    if (ListaCheia(l))
        printf("\nERRO: lista cheia!");
    else {
        (*l).vet[(*l).fim] = num;
        (*l).fim++;
    }
}

float Desenfileirar(ListaReais *l) {
    if (ListaVazia(l)) {
        printf("\nERRO: lista vazia!");
        return 0;
    } else {
        float num = (*l).vet[(*l).inicio];
        for (int i = 0; i < (*l).fim - 1; i++) {
            (*l).vet[i] = (*l).vet[i + 1];
        }
        (*l).fim--;
        return num;
    }
}

void SalvarListaEmArquivo(ListaReais *l) {
    FILE *arquivo = fopen("lista_reais.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    for (int i = 0; i < l->fim; i++) {
        fprintf(arquivo, "%.2f\n", l->vet[i]);
    }
    fclose(arquivo);
}

void LerListaDoArquivo(ListaReais *l) {
    FILE *arquivo = fopen("lista_reais.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de lista de números reais não encontrado.\n");
        return;
    }
    CriarLista(l);
    while (!feof(arquivo) && l->fim < TAM) {
        fscanf(arquivo, "%f", &l->vet[l->fim]);
        l->fim++;
    }
    fclose(arquivo);
}

void ImprimirLista(ListaReais *l) {
    printf("Conteúdo da lista de números reais:\n");
    for (int i = 0; i < l->fim; i++) {
        printf("%.2f ", l->vet[i]);
    }
    printf("\n");
}

int main() {
    ListaReais lista;
    CriarLista(&lista);

    for (int i = 0; i < TAM; i++) {
        float num;
        printf("Digite um número real: ");
        scanf("%f", &num);
        Enfileirar(&lista, num);
    }

    ImprimirLista(&lista);

    int opcao;

    do {
        printf("\n=== Opções ===\n");
        printf("1. Desenfileirar um número\n");
        printf("2. Salvar lista em arquivo\n");
        printf("3. Ler lista do arquivo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                float num = Desenfileirar(&lista);
                printf("Número desenfileirado: %.2f\n", num);
                break;
            }
            case 2:
                SalvarListaEmArquivo(&lista);
                printf("Lista salva no arquivo 'lista_reais.txt'.\n");
                break;
            case 3:
                LerListaDoArquivo(&lista);
                ImprimirLista(&lista);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

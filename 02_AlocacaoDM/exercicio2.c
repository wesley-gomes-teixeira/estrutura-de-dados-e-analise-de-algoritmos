#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Pessoa
typedef struct {
    long long cpf;
    char nome[100];
    double salario;
} Pessoa;

// Função para alocar memória dinamicamente e retornar um ponteiro para o vetor de Pessoa
Pessoa *alocarMemoria(int n) {
    Pessoa *pessoas = (Pessoa *)calloc(n, sizeof(Pessoa));
    if (pessoas == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return pessoas;
}

// Função para preencher o vetor de Pessoa
void preencherPessoas(Pessoa *pessoas, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o CPF da pessoa %d: ", i + 1);
        scanf("%lld", &pessoas[i].cpf);
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]s", pessoas[i].nome);
        printf("Digite o salário da pessoa %d: ", i + 1);
        scanf("%lf", &pessoas[i].salario);
    }
}

// Função para imprimir o vetor de Pessoa
void imprimirPessoas(Pessoa *pessoas, int n) {
    printf("Pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("Pessoa %d\n", i + 1);
        printf("CPF: %lld\n", pessoas[i].cpf);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Salário: %.2lf\n\n", pessoas[i].salario);
    }
}

// Função para liberar a memória alocada com calloc
void liberarMemoria(Pessoa *pessoas) {
    free(pessoas);
}

int main() {
    int n;
    printf("Digite o número de pessoas: ");
    scanf("%d", &n);

    // Alocação dinâmica de memória
    Pessoa *pessoas = alocarMemoria(n);

    // Preencher o vetor de Pessoa
    preencherPessoas(pessoas, n);

    // Imprimir o vetor de Pessoa
    imprimirPessoas(pessoas, n);

    // Liberar a memória alocada
    liberarMemoria(pessoas);

    return 0;
}

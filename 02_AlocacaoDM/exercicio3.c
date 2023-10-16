#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Veiculo
typedef struct {
    long long numero_chassi;
    char marca[50];
    char modelo[50];
    double preco;
} Veiculo;

// Função para alocar memória dinamicamente e retornar um ponteiro para o vetor de Veiculo
Veiculo *alocarMemoria(int tamanho) {
    Veiculo *veiculos = (Veiculo *)malloc(tamanho * sizeof(Veiculo));
    if (veiculos == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return veiculos;
}

// Função para preencher o vetor de Veiculo
void preencherVeiculos(Veiculo *veiculos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o número do chassi do veículo %d: ", i + 1);
        scanf("%lld", &veiculos[i].numero_chassi);
        printf("Digite a marca do veículo %d: ", i + 1);
        scanf(" %[^\n]s", veiculos[i].marca);
        printf("Digite o modelo do veículo %d: ", i + 1);
        scanf(" %[^\n]s", veiculos[i].modelo);
        printf("Digite o preço do veículo %d: ", i + 1);
        scanf("%lf", &veiculos[i].preco);
    }
}

// Função para imprimir o vetor de Veiculo
void imprimirVeiculos(Veiculo *veiculos, int tamanho) {
    printf("Veículos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Veículo %d\n", i + 1);
        printf("Número do chassi: %lld\n", veiculos[i].numero_chassi);
        printf("Marca: %s\n", veiculos[i].marca);
        printf("Modelo: %s\n", veiculos[i].modelo);
        printf("Preço: %.2lf\n\n", veiculos[i].preco);
    }
}

// Função para redimensionar o vetor de Veiculo com realloc
Veiculo *realocarMemoria(Veiculo *veiculos, int tamanho_atual, int novo_tamanho) {
    Veiculo *novo_veiculos = (Veiculo *)realloc(veiculos, novo_tamanho * sizeof(Veiculo));
    if (novo_veiculos == NULL) {
        printf("Falha na realocação de memória.\n");
        exit(1);
    }
    return novo_veiculos;
}

int main() {
    int tamanho_inicial, tamanho_atual;
    printf("Digite o tamanho inicial do vetor de veículos: ");
    scanf("%d", &tamanho_inicial);

    // Alocação dinâmica de memória
    Veiculo *veiculos = alocarMemoria(tamanho_inicial);
    tamanho_atual = tamanho_inicial;

    // Preencher o vetor de Veiculo
    preencherVeiculos(veiculos, tamanho_atual);

    // Imprimir o vetor de Veiculo
    imprimirVeiculos(veiculos, tamanho_atual);

    // Redimensionar o vetor de Veiculo para um tamanho maior
    int novo_tamanho = tamanho_atual + 5;
    if (novo_tamanho > tamanho_atual) {
        veiculos = realocarMemoria(veiculos, tamanho_atual, novo_tamanho);
        tamanho_atual = novo_tamanho;

        // Preencher os elementos adicionais
        for (int i = tamanho_atual - 5; i < tamanho_atual; i++) {
            printf("Digite os dados para o novo veículo %d:\n", i + 1);
            printf("Número do chassi: ");
            scanf("%lld", &veiculos[i].numero_chassi);
            printf("Marca: ");
            scanf(" %[^\n]s", veiculos[i].marca);
            printf("Modelo: ");
            scanf(" %[^\n]s", veiculos[i].modelo);
            printf("Preço: ");
            scanf("%lf", &veiculos[i].preco);
        }
    }

    // Imprimir o vetor de Veiculo após a realocação
    imprimirVeiculos(veiculos, tamanho_atual);

    // Liberar a memória alocada
    free(veiculos);

    return 0;
}

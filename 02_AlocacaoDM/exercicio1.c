#include <stdio.h>
#include <stdlib.h>

// Função para alocar memória dinamicamente e retornar um ponteiro para o array
int *alocarMemoria(int n) {
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1); 
    return array;
}

// Função para preencher o array
void preencherArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = i * 10;
    }
}

// Função para imprimir o array
void imprimirArray(int *array, int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função para liberar a memória alocada com malloc
void liberarMemoria(int *array) {
    free(array);
}

int main() {
    int *array, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Alocação dinâmica de memória
    array = alocarMemoria(n);

    // Preencher o array
    preencherArray(array, n);

    // Imprimir o array
    imprimirArray(array, n);

    // Liberar a memória alocada
    liberarMemoria(array);

    return 0;
}

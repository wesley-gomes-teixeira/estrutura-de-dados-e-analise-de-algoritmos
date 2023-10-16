#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    char nome[100];
    float valor_unitario;
    int quantidade_em_estoque;
} Produto;

typedef struct {
    Produto produtos[MAX_PRODUTOS];
    int num_produtos;
} ListaDeProdutos;

void cadastrarProduto(ListaDeProdutos *lista) {
    if (lista->num_produtos < MAX_PRODUTOS) {
        Produto novoProduto;
        printf("Nome do produto: ");
        scanf("%s", novoProduto.nome);
        printf("Valor unitário: ");
        scanf("%f", &novoProduto.valor_unitario);
        printf("Quantidade em estoque: ");
        scanf("%d", &novoProduto.quantidade_em_estoque);
        lista->produtos[lista->num_produtos] = novoProduto;
        lista->num_produtos++;
        printf("Produto cadastrado com sucesso!\n");
    } else {
        printf("A lista de produtos está cheia.\n");
    }
}

void pesquisarProduto(ListaDeProdutos *lista) {
    char nome[100];
    printf("Nome do produto a ser pesquisado: ");
    scanf("%s", nome);
    int encontrado = 0;

    for (int i = 0; i < lista->num_produtos; i++) {
        if (strcmp(nome, lista->produtos[i].nome) == 0) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", lista->produtos[i].nome);
            printf("Valor unitário: %.2f\n", lista->produtos[i].valor_unitario);
            printf("Quantidade em estoque: %d\n", lista->produtos[i].quantidade_em_estoque);

            char opcao;
            printf("Deseja excluir este produto? (S/N): ");
            scanf(" %c", &opcao);
            if (opcao == 'S' || opcao == 's') {
                for (int j = i; j < lista->num_produtos - 1; j++) {
                    lista->produtos[j] = lista->produtos[j + 1];
                }
                lista->num_produtos--;
                printf("Produto excluído com sucesso.\n");
            }
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não cadastrado!\n");
    }
}

void salvarLista(ListaDeProdutos *lista) {
    FILE *arquivo = fopen("lista_produtos.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fwrite(lista, sizeof(ListaDeProdutos), 1, arquivo);
    fclose(arquivo);
}

void carregarLista(ListaDeProdutos *lista) {
    FILE *arquivo = fopen("lista_produtos.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de lista de produtos não encontrado.\n");
        return;
    }
    fread(lista, sizeof(ListaDeProdutos), 1, arquivo);
    fclose(arquivo);
}

int main() {
    ListaDeProdutos lista;
    lista.num_produtos = 0;

    int opcao;

    do {
        printf("\n=== Farmácia ===\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Pesquisar Produto\n");
        printf("3. Salvar Lista\n");
        printf("4. Carregar Lista\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(&lista);
                break;
            case 2:
                pesquisarProduto(&lista);
                break;
            case 3:
                salvarLista(&lista);
                break;
            case 4:
                carregarLista(&lista);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

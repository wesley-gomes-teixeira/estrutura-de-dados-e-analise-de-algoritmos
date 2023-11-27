#include <stdio.h>
#include "Floresta.h"


void exibirMenu() {
    printf("\n1. Inserir valor em uma árvore\n");
    printf("2. Pesquisar valor em uma árvore\n");
    printf("3. Remover valor de uma árvore\n");
    printf("4. Exibir caminhamento pré-ordem de uma árvore\n");
    printf("5. Exibir caminhamento em-ordem de uma árvore\n");
    printf("6. Exibir caminhamento pós-ordem de uma árvore\n");
    printf("7. Inserir nova árvore de categoria\n");
    printf("8. Sair\n");
}

int main() {
    Floresta* floresta = criarFloresta();

    int opcao;
    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char categoria[100];
                int valor;

                printf("Digite a categoria da árvore: ");
                scanf("%s", categoria);

                Arvore* arvore = obterArvore(floresta, categoria);
                if (arvore == NULL) {
                    printf("Categoria não encontrada.\n");
                    break;
                }

                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(arvore, valor);
                break;
            }
            case 2: {
                char categoria[100];
                int valor;

                printf("Digite a categoria da árvore: ");
                scanf("%s", categoria);

                Arvore* arvore = obterArvore(floresta, categoria);
                if (arvore == NULL) {
                    printf("Categoria não encontrada.\n");
                    break;
                }

                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &valor);
                No* resultado = pesquisar(arvore, valor);
                if (resultado != NULL) {
                    printf("Valor encontrado na árvore.\n");
                } else {
                    printf("Valor não encontrado na árvore.\n");
                }
                break;
            }
            case 3: {
                char categoria[100];
                int valor;

                printf("Digite a categoria da árvore: ");
                scanf("%s", categoria);

                Arvore* arvore = obterArvore(floresta, categoria);
                if (arvore == NULL) {
                    printf("Categoria não encontrada.\n");
                    break;
                }

                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                remover(arvore, valor);
                break;
            }
            case 4: {
                char categoria[100];

                printf("Digite a categoria da árvore: ");
                scanf("%s", categoria);

                Arvore* arvore = obterArvore(floresta, categoria);
                if (arvore == NULL) {
                    printf("Categoria não encontrada.\n");
                    break;
                }

                printf("Caminhamento pré-ordem: ");
                preOrdem(arvore->raiz);
                printf("\n");
                break;
            }
            case 5: {
                char categoria[100];

                printf("Digite a categoria da árvore: ");
                scanf("%s", categoria);

                Arvore* arvore = obterArvore(floresta, categoria);
                if (arvore == NULL) {
                    printf("Categoria não encontrada.\n");
                    break;
                }

                printf("Caminhamento em-ordem: ");
                emOrdem(arvore->raiz);
                printf("\n");
                break;
            }
            case 6: {
                char categoria[100];

                printf("Digite a categoria da árvore: ");
                scanf("%s", categoria);

                Arvore* arvore = obterArvore(floresta, categoria);
                if (arvore == NULL) {
                    printf("Categoria não encontrada.\n");
                    break;
                }

                printf("Caminhamento pós-ordem: ");
                posOrdem(arvore->raiz);
                printf("\n");
                break;
            }
            case 7: {
                char novaCategoria[100];
                printf("Digite a nova categoria: ");
                scanf("%s", novaCategoria);
                inserirArvore(floresta, novaCategoria);
                printf("Nova árvore de categoria criada.\n");
                break;
            }
            case 8:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 8);

    liberarFloresta(floresta);

    return 0;
}

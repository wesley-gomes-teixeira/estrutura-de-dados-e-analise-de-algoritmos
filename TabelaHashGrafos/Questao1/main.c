#include <stdio.h>
#include "ArvoreBinariaDePesquisa.h" 

int main() {
    TipoDicionario Dicionario;
    Registro x;
    int opcao;

    Inicia(&Dicionario);

    do {
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Pesquisar\n");
        printf("4 - Imprimir chaves em ordem\n");
        printf("5 - Imprimir chaves em pré-ordem\n");
        printf("6 - Imprimir chaves em pós-ordem\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite uma chave para inserir: ");
                scanf("%d", &x.Chave);
                Insere(x, &Dicionario);
                break;
            case 2:
                printf("Digite uma chave para remover: ");
                scanf("%d", &x.Chave);
                Retira(x, &Dicionario);
                break;
            case 3:
                printf("Digite uma chave para pesquisar: ");
                scanf("%d", &x.Chave);
                Pesquisa(&x, Dicionario);
                break;
            case 4:
                printf("Chaves em ordem:\n");
                Central(Dicionario);
                break;
            case 5:
                printf("Chaves em pré-ordem:\n");
                PreOrdem(Dicionario);
                break;
            case 6:
                printf("Chaves em pós-ordem:\n");
                PosOrdem(Dicionario);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}

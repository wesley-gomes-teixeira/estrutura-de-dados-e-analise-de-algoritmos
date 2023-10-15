#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_PILHA 10

typedef struct {
    char cpf[12];
    char nome[100];
    char departamento[100];
    char cargo[100];
    double salario;
} Funcionario;

typedef struct {
    Funcionario elementos[TAMANHO_PILHA];
    int topo;
} PilhaCircular;

void CriarPilhaCircular(PilhaCircular *pilha) {
    pilha->topo = -1;
}

int PilhaCircularVazia(PilhaCircular *pilha) {
    return (pilha->topo == -1);
}

int PilhaCircularCheia(PilhaCircular *pilha) {
    return ((pilha->topo == TAMANHO_PILHA - 1) || (pilha->topo == TAMANHO_PILHA - 1 && pilha->topo == -1));
}

void Empilhar(PilhaCircular *pilha, Funcionario funcionario) {
    if (PilhaCircularCheia(pilha)) {
        pilha->topo = 0;
    } else {
        pilha->topo++;
    }

    pilha->elementos[pilha->topo] = funcionario;
}

void Desempilhar(PilhaCircular *pilha) {
    if (!PilhaCircularVazia(pilha)) {
        pilha->topo--;
    }
}

void ImprimirPilhaCircular(PilhaCircular *pilha) {
    int index = pilha->topo;

    if (PilhaCircularVazia(pilha)) {
        printf("A pilha circular está vazia.\n");
    } else {
        printf("Conteúdo da pilha circular:\n");

        do {
            Funcionario funcionario = pilha->elementos[index];
            printf("CPF: %s\n", funcionario.cpf);
            printf("Nome: %s\n", funcionario.nome);
            printf("Departamento: %s\n", funcionario.departamento);
            printf("Cargo: %s\n", funcionario.cargo);
            printf("Salário: %.2lf\n", funcionario.salario);
            printf("------------------------------\n");

            index--;

            if (index < 0) {
                index = TAMANHO_PILHA - 1;
            }
        } while (index != pilha->topo);
    }
}

int main() {
    PilhaCircular pilha;
    CriarPilhaCircular(&pilha);

    int opcao;

    printf("Bem-vindo ao Sistema de Cadastro de Funcionários!\n");

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Cadastrar Funcionário\n");
        printf("2. Remover Funcionário\n");
        printf("3. Listar Funcionários\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!PilhaCircularCheia(&pilha)) {
                    Funcionario funcionario;
                    printf("Digite os dados do funcionário:\n");
                    printf("CPF: ");
                    scanf("%s", funcionario.cpf);
                    printf("Nome: ");
                    scanf(" %99[^\n]", funcionario.nome);
                    printf("Departamento: ");
                    scanf(" %99[^\n]", funcionario.departamento);
                    printf("Cargo: ");
                    scanf(" %99[^\n]", funcionario.cargo);
                    printf("Salário: ");
                    scanf("%lf", &funcionario.salario);
                    Empilhar(&pilha, funcionario);
                    printf("Funcionário cadastrado com sucesso!\n");
                } else {
                    printf("A pilha está cheia. Remova um funcionário antes de cadastrar um novo.\n");
                }
                break;

            case 2:
                if (!PilhaCircularVazia(&pilha)) {
                    Desempilhar(&pilha);
                    printf("Funcionário removido com sucesso!\n");
                } else {
                    printf("A pilha está vazia. Não há funcionários para remover.\n");
                }
                break;

            case 3:
                ImprimirPilhaCircular(&pilha);
                break;

            case 4:
                printf("Saindo do programa. Obrigado por usar nosso sistema!\n");
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (opcao != 4);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10

typedef struct {
    char cpf[12];
    char nome[100];
    char endereco[200];
    char telefone[15];
    char celular[15];
    char data_nascimento[11];
    char data_admissao[11];
    char departamento[100];
    char cargo[100];
    float salario;
} Funcionario;

typedef struct {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int num_funcionarios;
} ListaFuncionarios;

void inicializarLista(ListaFuncionarios *lista) {
    lista->num_funcionarios = 0;
}

void cadastrarFuncionario(ListaFuncionarios *lista, Funcionario funcionario) {
    if (lista->num_funcionarios < MAX_FUNCIONARIOS) {
        lista->funcionarios[lista->num_funcionarios] = funcionario;
        lista->num_funcionarios++;
        printf("Funcionário cadastrado com sucesso!\n");
    } else {
        printf("A lista de funcionários está cheia. Não é possível cadastrar mais funcionários.\n");
    }
}

void listarFuncionarios(ListaFuncionarios *lista) {
    for (int i = 0; i < lista->num_funcionarios; i++) {
        printf("Funcionário #%d:\n", i + 1);
        printf("CPF: %s\n", lista->funcionarios[i].cpf);
        printf("Nome: %s\n", lista->funcionarios[i].nome);
        printf("Endereço: %s\n", lista->funcionarios[i].endereco);
        printf("Telefone: %s\n", lista->funcionarios[i].telefone);
        printf("Celular: %s\n", lista->funcionarios[i].celular);
        printf("Data de Nascimento: %s\n", lista->funcionarios[i].data_nascimento);
        printf("Data de Admissão: %s\n", lista->funcionarios[i].data_admissao);
        printf("Departamento: %s\n", lista->funcionarios[i].departamento);
        printf("Cargo: %s\n", lista->funcionarios[i].cargo);
        printf("Salário: %.2f\n\n", lista->funcionarios[i].salario);
    }
}

void salvarFuncionariosEmArquivo(ListaFuncionarios *lista) {
    FILE *arquivo = fopen("funcionarios.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(lista, sizeof(ListaFuncionarios), 1, arquivo);
    fclose(arquivo);
}

void carregarFuncionariosDoArquivo(ListaFuncionarios *lista) {
    FILE *arquivo = fopen("funcionarios.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de funcionários não encontrado.\n");
        return;
    }
    fread(lista, sizeof(ListaFuncionarios), 1, arquivo);
    fclose(arquivo);
}

int pesquisarFuncionarioPorCPF(ListaFuncionarios *lista, const char *cpf) {
    for (int i = 0; i < lista->num_funcionarios; i++) {
        if (strcmp(cpf, lista->funcionarios[i].cpf) == 0) {
            return i; // Retorna o índice do funcionário encontrado
        }
    }
    return -1; // Retorna -1 se o funcionário não for encontrado
}

int main() {
    ListaFuncionarios lista;
    inicializarLista(&lista);

    int opcao;

    do {
        printf("\n=== Opções ===\n");
        printf("1. Cadastrar Funcionário\n");
        printf("2. Listar Funcionários\n");
        printf("3. Salvar Funcionários em Arquivo\n");
        printf("4. Carregar Funcionários do Arquivo\n");
        printf("5. Pesquisar Funcionário por CPF\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Funcionario novoFuncionario;
                printf("CPF: ");
                scanf("%s", novoFuncionario.cpf);
                printf("Nome: ");
                scanf("%s", novoFuncionario.nome);
                printf("Endereço: ");
                scanf("%s", novoFuncionario.endereco);
                printf("Telefone: ");
                scanf("%s", novoFuncionario.telefone);
                printf("Celular: ");
                scanf("%s", novoFuncionario.celular);
                printf("Data de Nascimento (dd/mm/aaaa): ");
                scanf("%s", novoFuncionario.data_nascimento);
                printf("Data de Admissão (dd/mm/aaaa): ");
                scanf("%s", novoFuncionario.data_admissao);
                printf("Departamento: ");
                scanf("%s", novoFuncionario.departamento);
                printf("Cargo: ");
                scanf("%s", novoFuncionario.cargo);
                printf("Salário: ");
                scanf("%f", &novoFuncionario.salario);
                cadastrarFuncionario(&lista, novoFuncionario);
                break;
            }
            case 2:
                listarFuncionarios(&lista);
                break;
            case 3:
                salvarFuncionariosEmArquivo(&lista);
                printf("Funcionários salvos no arquivo 'funcionarios.bin'.\n");
                break;
            case 4:
                carregarFuncionariosDoArquivo(&lista);
                printf("Funcionários carregados do arquivo 'funcionarios.bin'.\n");
                break;
            case 5: {
                char cpf[12];
                printf("Digite o CPF para pesquisar: ");
                scanf("%s", cpf);
                int indice = pesquisarFuncionarioPorCPF(&lista, cpf);
                if (indice >= 0) {
                    printf("Funcionário encontrado:\n");
                    printf("CPF: %s\n", lista.funcionarios[indice].cpf);
                    printf("Nome: %s\n", lista.funcionarios[indice].nome);
                    printf("Endereço: %s\n", lista.funcionarios[indice].endereco);
                    printf("Telefone: %s\n", lista.funcionarios[indice].telefone);
                    printf("Celular: %s\n", lista.funcionarios[indice].celular);
                    printf("Data de Nascimento: %s\n", lista.funcionarios[indice].data_nascimento);
                    printf("Data de Admissão: %s\n", lista.funcionarios[indice].data_admissao);
                    printf("Departamento: %s\n", lista.funcionarios[indice].departamento);
                    printf("Cargo: %s\n", lista.funcionarios[indice].cargo);
                    printf("Salário: %.2f\n", lista.funcionarios[indice].salario);
                } else {
                    printf("Funcionário não encontrado.\n");
                }
                break;
            }
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABELA 10  
// Estrutura
typedef struct {
    int dia;
    int mes;
    int ano;
} DataAdmissao;

// Estrutura dos dados do funcionário
typedef struct Funcionario {
    char nome[100];
    DataAdmissao dataAdmissao;
    float salario;
    struct Funcionario* proximo;
} Funcionario;

// Estrutura da tabela hash
typedef struct {
    Funcionario* inicio;
} EntradaTabela;

EntradaTabela tabela[TAM_TABELA];

// Função para calcular o índice na tabela hash a partir do nome
int CalcularIndiceHash(char* nome) {
    unsigned long hash = 5381;
    int c;

    while ((c = *nome++)) {
        hash = ((hash << 5) + hash) + c; 
    }

    return hash % TAM_TABELA;
}

// Função para cadastrar
void CadastrarFuncionario(char* nome, int dia, int mes, int ano, float salario) {
    int indice = CalcularIndiceHash(nome);

    Funcionario* novoFuncionario = (Funcionario*)malloc(sizeof(Funcionario));
    if (novoFuncionario == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    strcpy(novoFuncionario->nome, nome);
    novoFuncionario->dataAdmissao.dia = dia;
    novoFuncionario->dataAdmissao.mes = mes;
    novoFuncionario->dataAdmissao.ano = ano;
    novoFuncionario->salario = salario;
    novoFuncionario->proximo = NULL;

    // Inserir ordenado na lista
    Funcionario* atual = tabela[indice].inicio;
    Funcionario* anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) < 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        novoFuncionario->proximo = tabela[indice].inicio;
        tabela[indice].inicio = novoFuncionario;
    } else {
        anterior->proximo = novoFuncionario;
        novoFuncionario->proximo = atual;
    }

    printf("Funcionário cadastrado com sucesso.\n");
}

// Função para PesquisarPorNome
void PesquisarPorNome(char* nome) {
    int indice = CalcularIndiceHash(nome);

    Funcionario* atual = tabela[indice].inicio;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Nome: %s, Data de Admissão: %02d/%02d/%04d, Salário: %.2f\n",
                   atual->nome, atual->dataAdmissao.dia, atual->dataAdmissao.mes,
                   atual->dataAdmissao.ano, atual->salario);
            return;
        }
        atual = atual->proximo;
    }

    printf("Funcionário não encontrado.\n");
}

// Função para pesquisar por data de admissão
void PesquisarPorData(int dia, int mes, int ano) {
    for (int i = 0; i < TAM_TABELA; i++) {
        Funcionario* atual = tabela[i].inicio;

        while (atual != NULL) {
            if (atual->dataAdmissao.dia == dia && atual->dataAdmissao.mes == mes &&
                atual->dataAdmissao.ano == ano) {
                printf("Nome: %s, Data de Admissão: %02d/%02d/%04d, Salário: %.2f\n",
                       atual->nome, atual->dataAdmissao.dia, atual->dataAdmissao.mes,
                       atual->dataAdmissao.ano, atual->salario);
                return;
            }
            atual = atual->proximo;
        }
    }

    printf("Funcionário não encontrado.\n");
}

// Função para excluir 
void ExcluirFuncionario(char* nome) {
    int indice = CalcularIndiceHash(nome);

    Funcionario* atual = tabela[indice].inicio;
    Funcionario* anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Funcionário não encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        tabela[indice].inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Funcionário excluído com sucesso.\n");
}

// salvar arquivo binário
void SalvarTabela() {
    FILE* arquivo = fopen("tabela.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < TAM_TABELA; i++) {
        Funcionario* atual = tabela[i].inicio;

        while (atual != NULL) {
            fwrite(atual, sizeof(Funcionario), 1, arquivo);
            atual = atual->proximo;
        }
    }

    fclose(arquivo);
    printf("Tabela salva com sucesso.\n");
}

// carregar tabela hash de um arquivo binário
void CarregarTabela() {
    FILE* arquivo = fopen("tabela.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de tabela não encontrado. Criando uma nova tabela.\n");
        return;
    }

    for (int i = 0; i < TAM_TABELA; i++) {
        tabela[i].inicio = NULL;
        Funcionario funcionario;

        while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
            CadastrarFuncionario(funcionario.nome, funcionario.dataAdmissao.dia,
                                 funcionario.dataAdmissao.mes, funcionario.dataAdmissao.ano,
                                 funcionario.salario);
        }
    }

    fclose(arquivo);
    printf("Tabela carregada com sucesso.\n");
}

// Função para imprimir a tabela
void ImprimirTabela() {
    for (int i = 0; i < TAM_TABELA; i++) {
        Funcionario* atual = tabela[i].inicio;

        while (atual != NULL) {
            printf("Nome: %s, Data de Admissão: %02d/%02d/%04d, Salário: %.2f\n",
                   atual->nome, atual->dataAdmissao.dia, atual->dataAdmissao.mes,
                   atual->dataAdmissao.ano, atual->salario);
            atual = atual->proximo;
        }
    }
}

// Função principal
int main() {
    CarregarTabela();

    int opcao;
    char nome[100];
    int dia, mes, ano;
    float salario;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar Funcionário\n");
        printf("2 - Pesquisar por Nome\n");
        printf("3 - Pesquisar por Data de Admissão\n");
        printf("4 - Excluir Funcionário\n");
        printf("5 - Salvar Tabela\n");
        printf("6 - Imprimir Tabela\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome: ");
                scanf("%s", nome);
                printf("Data de Admissão (dd mm aaaa): ");
                scanf("%d %d %d", &dia, &mes, &ano);
                printf("Salário: ");
                scanf("%f", &salario);
                CadastrarFuncionario(nome, dia, mes, ano, salario);
                break;
            case 2:
                printf("Nome: ");
                scanf("%s", nome);
                PesquisarPorNome(nome);
                break;
            case 3:
                printf("Data de Admissão (dd mm aaaa): ");
                scanf("%d %d %d", &dia, &mes, &ano);
                PesquisarPorData(dia, mes, ano);
                break;
            case 4:
                printf("Nome: ");
                scanf("%s", nome);
                ExcluirFuncionario(nome);
                break;
            case 5:
                SalvarTabela();
                break;
            case 6:
                ImprimirTabela();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define VERDADEIRO 1
#define FALSO 0

#define TAM 50 

struct tipo_funcionario {
    char cpf[11]; char nome[100]; char endereco[100]; char telefone[15]; char celular[15];
    struct tm data_nascimento; struct tm data_admissao;
    char departamento[50]; char cargo[50];
    float salario;
};

typedef struct tipo_funcionario funcionario;

void CriarFila(fila *f) {
    (*f).inicio = -1; 
    (*f).fim = -1; 
}

int FilaVazia(fila *f) {
    return ((*f).inicio == -1 && (*f).fim == -1);
}

int FilaCheia(fila *f) {
    return ((*f).fim == TAM - 1); 
}

void Enfileirar(fila *f, funcionario *registro) {
    if (FilaCheia(f)) {
        printf("Fila cheia. Não é possível enfileirar.\n");
    } else {
        if (FilaVazia(f)) {
            (*f).inicio = 0;
        }
        (*f).vet[++(*f).fim] = *registro;
    }
}

funcionario Desenfileirar(fila *f) {
    funcionario registro;
    if (!FilaVazia(f)) {
        registro = (*f).vet[(*f).inicio++];
    } else {
        printf("Fila vazia. Não é possível desenfileirar.\n");
        registro.cpf[0] = '\0';
    }
    return registro;
}

void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("A fila está vazia.\n");
    } else {
        printf("Conteúdo da fila:\n");
        for (int i = (*f).inicio; i <= (*f).fim; i++) {
            printf("CPF: %s\n", (*f).vet[i].cpf);
            printf("Nome: %s\n", (*f).vet[i].nome);
            printf("Endereço: %s\n", (*f).vet[i].endereco);
            printf("Telefone: %s\n", (*f).vet[i].telefone);
            printf("Celular: %s\n", (*f).vet[i].celular);
            printf("Data de nascimento: %d/%d/%d\n",
                   (*f).vet[i].data_nascimento.tm_mday,
                   (*f).vet[i].data_nascimento.tm_mon + 1,
                   (*f).vet[i].data_nascimento.tm_year + 1900);
            printf("Data de admissão: %d/%d/%d\n",
                   (*f).vet[i].data_admissao.tm_mday,
                   (*f).vet[i].data_admissao.tm_mon + 1,
                   (*f).vet[i].data_admissao.tm_year + 1900);
            printf("Departamento: %s\n", (*f).vet[i].departamento);
            printf("Cargo: %s\n", (*f).vet[i].cargo);
            printf("Salário: %.2f\n", (*f).vet);
        }
    }
}
            

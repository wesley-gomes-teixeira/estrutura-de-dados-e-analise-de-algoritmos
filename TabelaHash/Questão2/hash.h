/* Arquivo: hash.h
* Biblicoteca de operações para tabela hash implementada com lista e alocação
dinâmica de memória.
*/
#include "Fila.h"
/*
* Estrutura de cada entrada da tabela hash.
*/
typedef struct TipoEntrada {
char* chave;
Fila f;
} entrada;
/*
* Definição do tipo hash.
*/
typedef entrada hash[TAM];
/*
* Cria uma tabela hash vazia.
*/
void CriarHash (hash h) {
int i;
for (i = 0; i < TAM; i++)
CriarFila (&(h[i].f));
}

/*
* Função de hash.
*/
int FuncaoHash (char *chave) {
int i, soma = 0;
for (i = 0; chave[i] != '\0'; i++)
soma += chave[i];
return (soma % TAM);
}
/*
* Imsere um elemento na tabela hash.
*/
void InserirHash(Hash h, char *chave, Elemento *e) {
    int i, tam_chave;
    i = FuncaoHash(chave);
    tam_chave = strlen(chave) + 1; 
    if (h[i].f.inicio != NULL)
        free(h[i].chave); //Na colisão, remove a chave anterior para inserir a chave
    h[i].chave = (char*) malloc(sizeof(char) * tam_chave);
    if (h[i].chave == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return;
    }
    strcpy(h[i].chave, chave);
    InserirFila(&(h[i].f), *e);
}
/*
* Procura um elemento na tabela hash.
* Se o elemento procurado estiver na tabela hash, retorna o endereco do elemento.
* Se o elemento procurado não estiver na tabela hash, retorna NULL.
*/
elemento* PesquisarHash (hash h, char *chave) {
int i;
i = FuncaoHash (chave);
return PesquisarFila (h[i].f, chave);
}

/*
* Retira um elemento da tabela hash.
*/
elemento ExcluirHash (hash h, char *chave) {
int i;
i = FuncaoHash (chave);
return ExcluirFila (&(h[i].f));
}
/*
* Limpa a tabela hash.
*/
void LimparHash (hash h) {
int i;
for (i = 0; i < TAM; i++) {
if (h[i].f.inicio != NULL) {
while (h[i].f.inicio != NULL) {
ExcluirFila (&(h[i].f));
}
free (h[i].chave);
}
}
}

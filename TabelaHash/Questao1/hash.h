/* Arquivo: hash.h
* Biblicoteca de operações para tabela hash implementada com lista e alocação
dinâmica de memória.
*/
#include "Pilha.h"
/*
* Estrutura de cada entrada da tabela hash.
*/
typedef struct TipoEntrada {
char* chave;
Pilha p;
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
CriarPilha (&(h[i].p));
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
void InserirHash (hash h, char *chave, elemento *e) {
int i, tam_chave;
i = FuncaoHash (chave);
tam_chave = strlen (chave) + 1; 
if (h[i].p != NULL)
free (h[i].chave); //Na colisão, remove a chave anterior para inserir a chave

h[i].chave = (char*) malloc (sizeof (char) * tam_chave);
strcpy (h[i].chave, chave);
InserirPilha (&(h[i].p), *e);
}
/*
* Procura um elemento na tabela hash.
* Se o elemento procurado estiver na tabela hash, retorna o endereco do elemento.
* Se o elemento procurado não estiver na tabela hash, retorna NULL.
*/
elemento* PesquisarHash (hash h, char *chave) {
int i;
i = FuncaoHash (chave);
return PesquisarPilha (h[i].p, chave);
}

/*
* Retira um elemento da tabela hash.
*/
elemento ExcluirHash (hash h, char *chave) {
int i;
i = FuncaoHash (chave);
return ExcluirPilha (&(h[i].p));
}
/*
* Limpa a tabela hash.
*/
void LimparHash (hash h) {
int i;
for (i = 0; i < TAM; i++) {
if (h[i].p != NULL) {
while (h[i].p != NULL) {
ExcluirPilha (&(h[i].p));
}
free (h[i].chave);
}
}
}

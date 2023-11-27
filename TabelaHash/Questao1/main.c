#include <stdio.h>		//printf (), scanf().
#include <stdlib.h>		//system ().
#include <string.h>		//strcmp ().
#define TAM 3
typedef struct  
{
    char *palavra;
    char *sinonimo;
};

#include "Pilha.h"
void CadastrarDicionario (Pilha* p);
void PesquisarDicionario (Pilha* p);
void ExcluirPalavra (Pilha* p);
int main () 
{
    Pilha p;
    CriarPilha(&p);
    printf ("\nC A D A S T R O!\n\n\n");
    CadastrarDicionario (&p);
    system ("clear || cls");
    printf ("\nP E S Q U I S A!\n\n\n");
    PesquisarDicionario (&p);
    system ("clear || cls");
    printf ("\nE X C L U S A O!\n\n\n");
    ExcluirPalavra (&p);
    printf ("\n\n");
    system ("pause");
    return 0;
}
void CadastrarDicionario (Pilha* p) 
{
    char op, lixo, termo[256];
    int i = 0, tam;
    elemento e;
    do
    {
        printf ("\n\n\n%d) Informe uma palavra: ", i);
        scanf ("%s", termo);
        tam = strlen (termo) + 1;
        e.palavra = (char *) malloc (sizeof (char) * tam);
        strcpy (e.palavra, termo);
        printf ("\n%d) Informe o sinonimo da palavra: ", i++);
        scanf ("%s", termo);
        tam = strlen (termo) + 1;
        e.sinonimo = (char *) malloc (sizeof (char) * tam);
        strcpy (e.sinonimo, termo);
        InserirPilha(p, e);
        scanf ("%c", &lixo);
        printf ("\n\nDeseja inserir uma nova palavra (s/n)? ");
        scanf ("%c", &op);
    }
    while (op == 's');
}
void PesquisarDicionario (Pilha* p) 
{
    char op, lixo, palavra[256];
    elemento* e;
    do
    {
        printf ("\n\n\nInforme uma palavra: ");
        scanf ("%s", palavra);
        scanf ("%c", &lixo);
        e = PesquisarPilha(*p, palavra);
        if (e)
        {
            printf ("\nPalavra: %s", e->palavra);
            printf ("\nSinonimo: %s", e->sinonimo);
        }
        else
            printf ("\nPalavra nao encontrada!");
        printf ("\n\nDeseja realizar uma nova pesquisa (s/n)? ");
        scanf ("%c", &op);
    }
    while (op == 's');
}
void ExcluirPalavra (Pilha* p) 
{
    char op, lixo, palavra[256];
    int i = 0;
    elemento e;
    do
    {
        printf ("\n\n\n%d) Informe uma palavra: ", i++);
        scanf ("%s", palavra);
        scanf ("%c", &lixo);
        e = ExcluirPilha(p);
        if (strcmp(e.palavra, palavra) == 0)
        {
            printf ("\nPalavra: %s", e.palavra);
            printf ("\nSinonimo: %s", e.sinonimo);
            printf ("\nExclusao realizada com sucesso!");
        }
        else
            printf ("\nPalavra nao encontrada!");
        printf ("\n\nDeseja excluir uma nova palavra (s/n)? ");
        scanf ("%c", &op);
    }
    while (op == 's');
}

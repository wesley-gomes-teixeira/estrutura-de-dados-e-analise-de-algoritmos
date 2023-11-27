#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
} Registro;

typedef struct Nodo_str *Apontador;

typedef struct Nodo_str {
    Registro Reg;
    Apontador Esq, Dir;
} Nodo;

typedef Apontador TipoDicionario;

void Inicia(TipoDicionario *Dicionario) {
    *Dicionario = NULL;
}

void Insere(Registro x, Apontador *p) {
    if (*p == NULL) {
        *p = (Apontador) malloc(sizeof(Nodo));
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
    if (x.Chave < (*p)->Reg.Chave) {
        Insere(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave)
        Insere(x, &(*p)->Dir);
    else
        printf(" Registro existente na árvore \n");
}

void Pesquisa(Registro *x, Apontador p) {
    if (p == NULL) {
        printf("Erro: Registro não está na árvore\n");
        return;
    }
    if (x->Chave < p->Reg.Chave) {
        Pesquisa(x, p->Esq);
        return;
    }
    if (x->Chave > p->Reg.Chave)
        Pesquisa(x, p->Dir);
    else
        *x = p->Reg;
}

void Central(Apontador p) {
    if (p != NULL) {
        Central(p->Esq);
        printf("%d\n", p->Reg.Chave);
        Central(p->Dir);
    }
}

void PreOrdem(Apontador p) {
    if (p != NULL) {
        printf("%d\n", p->Reg.Chave);
        PreOrdem(p->Esq);
        PreOrdem(p->Dir);
    }
}

void PosOrdem(Apontador p) {
    if (p != NULL) {
        PosOrdem(p->Esq);
        PosOrdem(p->Dir);
        printf("%d\n", p->Reg.Chave);
    }
}

void Antecessor(Apontador *q, Apontador *r) {
    if ((*r)->Dir != NULL) {
        Antecessor(q, &(*r)->Dir);
        return;
    }
    (*q)->Reg = (*r)->Reg;
    Apontador aux = *r;
    *r = (*r)->Esq;
    free(aux);
}

void Retira(Registro x, Apontador *p) {
    Apontador Aux;
    if (*p == NULL) {
        printf("Erro: Registro não está na árvore\n");
        return;
    }
    if (x.Chave < (*p)->Reg.Chave) {
        Retira(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave) {
        Retira(x, &(*p)->Dir);
        return;
    }
    if ((*p)->Dir == NULL) {
        Aux = *p;
        *p = (*p)->Esq;
        free(Aux);
        return;
    }
    if ((*p)->Esq != NULL) {
        Antecessor(&(*p), &(*p)->Esq);
        return;
    }
    Aux = *p;
    *p = (*p)->Dir;
    free(Aux);
}
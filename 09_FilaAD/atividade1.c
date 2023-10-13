#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Pedido {
   char nome[100]; char telefone[12]; char endereco[60]; char produto[75]; float valor; struct Pedido* prox;
}
Pedido;


typedef struct FilaPedidos {
   Pedido* inicio;
   Pedido* fim;
} FilaPedidos;


void inicializarFila(FilaPedidos* fila) {
   fila->inicio = NULL;
   fila->fim = NULL;
}


void enfileirarPedido(FilaPedidos* fila, Pedido pedido) {
   Pedido* novoPedido = (Pedido*)malloc(sizeof(Pedido));
   *novoPedido = pedido;
   novoPedido->prox = NULL;


   if (fila->fim == NULL) {
       fila->inicio = novoPedido;
       fila->fim = novoPedido;
   } else {
       fila->fim->prox = novoPedido;
       fila->fim = novoPedido;
   }
}


void imprimirFila(FilaPedidos fila) {
   Pedido* atual = fila.inicio;
   while (atual != NULL) {
       printf("Nome: %s\n", atual->nome);
       printf("Telefone: %s\n", atual->telefone);
       printf("Endereço: %s\n", atual->endereco);
       printf("Produto: %s\n", atual->produto);
       printf("Valor: %.2f\n\n", atual->valor);
       atual = atual->prox;
   }
}


void salvarFilaEmArquivo(FilaPedidos fila, const char* nomeArquivo) {
   FILE* arquivo = fopen(nomeArquivo, "w");
   Pedido* atual = fila.inicio;


   while (atual != NULL) {
       fprintf(arquivo, "Nome: %s\n", atual->nome);
       fprintf(arquivo, "Telefone: %s\n", atual->telefone);
       fprintf(arquivo, "Endereço: %s\n", atual->endereco);
       fprintf(arquivo, "Produto: %s\n", atual->produto);
       fprintf(arquivo, "Valor: %.2f\n\n", atual->valor);
       atual = atual->prox;
   }


   fclose(arquivo);
}


void carregarFilaDeArquivo(FilaPedidos* fila, const char* nomeArquivo) {
   FILE* arquivo = fopen(nomeArquivo, "r");


   if (arquivo == NULL) {
       printf("Erro ao abrir o arquivo.\n");
       return;
   }


   Pedido pedido;
   char linha[256];


   while (fgets(linha, sizeof(linha), arquivo)) {
       if (strstr(linha, "Nome:")) {
           sscanf(linha, "Nome: %[^\n]", pedido.nome);
       } else if (strstr(linha, "Telefone:")) {
           sscanf(linha, "Telefone: %[^\n]", pedido.telefone);
       } else if (strstr(linha, "Endereço:")) {
           sscanf(linha, "Endereço: %[^\n]", pedido.endereco);
       } else if (strstr(linha, "Produto:")) {
           sscanf(linha, "Produto: %[^\n]", pedido.produto);
       } else if (strstr(linha, "Valor:")) {
           sscanf(linha, "Valor: %f", &pedido.valor);
           enfileirarPedido(fila, pedido);
       }
   }


   fclose(arquivo);
}


int pedidosNaFrenteDoCliente(FilaPedidos fila, const char* nomeCliente) {
   Pedido* atual = fila.inicio;
   int pedidosNaFrente = 0;


   while (atual != NULL) {
       if (strcmp(atual->nome, nomeCliente) != 0) {
           pedidosNaFrente++;
       } else {
           break;
       }
       atual = atual->prox;
   }


   return pedidosNaFrente;
}


int main() {
   FilaPedidos fila;
   inicializarFila(&fila);


   int opcao;


   do {
       printf("Escolha um numero abaixo: \n1 - Criar pedido\n2 - Imprimir fila\n3 - Salvar fila\n4 - Carregar fila\n");
       printf("5 - Pedidos na frente\n0 - Sair\nDigite sua escolha: ");
       scanf("%d", &opcao);


       switch (opcao) {
           case 1: {
               Pedido novoPedido;
               printf("Digite seu nome: ");
               scanf(" %[^\n]", novoPedido.nome);
               printf("Telefone: ");
               scanf(" %[^\n]", novoPedido.telefone);
               printf("Endereço de entrega: ");
               scanf(" %[^\n]", novoPedido.endereco);
               printf("Produto: ");
               scanf(" %[^\n]", novoPedido.produto);
               printf("Valor: ");
               scanf("%f", &novoPedido.valor);
               enfileirarPedido(&fila, novoPedido);
               break;
           }
           case 2: {
               imprimirFila(fila);
               break;
           }
           case 3: {
               salvarFilaEmArquivo(fila, "pedidos.txt");
               break;
           }
           case 4: {
               carregarFilaDeArquivo(&fila, "pedidos.txt");
               break;
           }
           case 5: {
               char nomeCliente[100];
               printf("Digite o nome: ");
               scanf(" %[^\n]", nomeCliente);
               int pedidosFrente = pedidosNaFrenteDoCliente(fila, nomeCliente);
               printf("Pedidos na frente: %d\n", pedidosFrente);
               break;
           }
           case 0:
               printf("Saindo do programa.\n");
               break;
       }
   } while (opcao != 0);
   return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef char* string;
typedef struct Node {
   char data;
   struct Node* next;
} Node;

typedef struct Queue {
   Node* front;
   Node* rear;
} Queue;

void CriarFila(Queue* q) {
   q->front = q->rear = NULL;
}

int FilaVazia(Queue* q) {
   return q->front == NULL;
}

void Enfileirar(Queue* q, char data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = NULL;

   if (FilaVazia(q)) {
       q->front = q->rear = newNode;
   } else {
       q->rear->next = newNode;
       q->rear = newNode;
   }
}

char Desenfileirar(Queue* q) {
   if (FilaVazia(q)) {
       return '\0'; 
   }

   Node* temp = q->front;
   char data = temp->data;
   q->front = q->front->next;
   free(temp);
   return data;
}

void strread(string* s) {
   int cont = 0;
   char letra;
   Queue f;
   CriarFila(&f);
   scanf("%c", &letra);
   while (letra != '\n') {
       Enfileirar(&f, letra);
       cont++;
       scanf("%c", &letra);
   }
   cont++;

   *s = (char*)malloc(sizeof(char) * (cont + 1));
   cont = 0;

   while (!FilaVazia(&f)) {
       (*s)[cont++] = Desenfileirar(&f);
   }
   (*s)[cont] = '\0';
}


int main() {
   string palavra;
   printf("\nInforme seu nome: ");
   strread(&palavra);
   printf("\nNome informado: %s", palavra);
   printf("\n\n");
   free(palavra);
   return 0;
}
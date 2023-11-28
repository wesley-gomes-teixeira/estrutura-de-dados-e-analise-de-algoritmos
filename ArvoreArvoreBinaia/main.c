#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Definição da estrutura da árvore
typedef struct Tree {
    Node* root;
} Tree;

// Função auxiliar para calcular a altura de um nó
int nodeHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Função para inicializar a árvore como vazia
void initTree(Tree* tree) {
    tree->root = NULL;
}

// Função auxiliar para criar um novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore
void insertNode(Tree* tree, int value) {
    if (tree->root == NULL) {
        tree->root = createNode(value);
    } else {
        Node* current = tree->root;
        while (1) {
            if (value < current->data) {
                if (current->left == NULL) {
                    current->left = createNode(value);
                    break;
                } else {
                    current = current->left;
                }
            } else if (value > current->data) {
                if (current->right == NULL) {
                    current->right = createNode(value);
                    break;
                } else {
                    current = current->right;
                }
            } else {
                // Ignorar valores duplicados 
                break;
            }
        }
    }
}

// Função para verificar se a árvore está vazia
int isEmpty(Tree* tree) {
    return tree->root == NULL;
}

// Função auxiliar para encontrar o nó mínimo em uma subárvore
Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Função para remover um nó da árvore
Node* removeNode(Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = removeNode(root->left, value);
    } else if (value > root->data) {
        root->right = removeNode(root->right, value);
    } else {
        // Nó encontrado, realizar a remoção
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Nó com dois filhos, encontrar o sucessor (menor valor à direita)
        Node* temp = findMin(root->right);

        // Copiar o valor do sucessor para o nó atual
        root->data = temp->data;

        // Remover o sucessor recursivamente
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

// Função para chamar a remoção do nó na árvore
void removeFromTree(Tree* tree, int value) {
    tree->root = removeNode(tree->root, value);
}

// Função para pesquisar a ocorrência de um valor em algum nó da árvore
int searchValue(Tree* tree, int value) {
    Node* current = tree->root;
    while (current != NULL) {
        if (value == current->data) {
            return 1; // Valor encontrado
        } else if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return 0; // Valor não encontrado
}

// Função para informar a altura da árvore
int treeHeight(Tree* tree) {
    return nodeHeight(tree->root);
}

// Função para informar a profundidade da árvore
int treeDepth(Tree* tree) {
    return nodeHeight(tree->root);
}

// Função para informar a profundidade de um nó
int nodeDepth(Node* root, int value, int depth) {
    if (root == NULL) {
        return -1; // Valor não encontrado
    }

    if (value == root->data) {
        return depth; // Valor encontrado
    } else if (value < root->data) {
        return nodeDepth(root->left, value, depth + 1);
    } else {
        return nodeDepth(root->right, value, depth + 1);
    }
}

// Função para informar o nível de um nó
int nodeLevel(Tree* tree, int value) {
    return nodeDepth(tree->root, value, 0);
}

// Função para informar o grau da árvore
int treeDegree(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDegree = treeDegree(root->left);
    int rightDegree = treeDegree(root->right);

    return (leftDegree > rightDegree ? leftDegree : rightDegree) + (root->left != NULL || root->right != NULL);
}

// Função para informar o grau de um nó
int nodeDegree(Node* node) {
    return node == NULL ? 0 : (node->left != NULL || node->right != NULL) + nodeDegree(node->left) + nodeDegree(node->right);
}

// Função para informar o nó de maior grau
Node* maxDegreeNode(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    Node* maxDegree = root;

    if (nodeDegree(root->left) > nodeDegree(maxDegree)) {
        maxDegree = root->left;
    }

    if (nodeDegree(root->right) > nodeDegree(maxDegree)) {
        maxDegree = root->right;
    }

    Node* leftMax = maxDegreeNode(root->left);
    Node* rightMax = maxDegreeNode(root->right);

    if (nodeDegree(leftMax) > nodeDegree(maxDegree)) {
        maxDegree = leftMax;
    }

    if (nodeDegree(rightMax) > nodeDegree(maxDegree)) {
        maxDegree = rightMax;
    }

    return maxDegree;
}

// Função para informar o diâmetro da árvore
int treeDiameter(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = nodeHeight(root->left);
    int rightHeight = nodeHeight(root->right);

    int leftDiameter = treeDiameter(root->left);
    int rightDiameter = treeDiameter(root->right);

    return (leftHeight + rightHeight + 1) > (leftDiameter > rightDiameter ? leftDiameter : rightDiameter)
               ? (leftHeight + rightHeight + 1)
               : (leftDiameter > rightDiameter ? leftDiameter : rightDiameter);
}

// ... (Funções de percurso)

// Função para liberar a memória alocada pelos nós da árvore
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Função principal para teste
int main() {
    Tree myTree;
    initTree(&myTree);

    // Inserir alguns valores na árvore
    insertNode(&myTree, 10);
    insertNode(&myTree, 5);
    insertNode(&myTree, 15);
    insertNode(&myTree, 3);
    insertNode(&myTree, 7);

    // Verificar se a árvore está vazia
    printf("A arvore esta vazia? %s\n", isEmpty(&myTree) ? "Sim" : "Nao");

    // Remover um nó da árvore
    removeFromTree(&myTree, 5);

    // Verificar se a árvore está vazia novamente
    printf("A arvore esta vazia? %s\n", isEmpty(&myTree) ? "Sim" : "Nao");

    // Pesquisar ocorrência de um valor na árvore
    int searchValueResult = searchValue(&myTree, 7);
    printf("Valor 7 encontrado na arvore? %s\n", searchValueResult ? "Sim" : "Nao");

    // Informar a altura da árvore
    printf("Altura da arvore: %d\n", treeHeight(&myTree));

    // Informar a profundidade da árvore
    printf("Profundidade da arvore: %d\n", treeDepth(&myTree));

    // Informar a profundidade de um nó
    int depthOfNode = nodeDepth(myTree.root, 15, 0);
    printf("Profundidade do no com valor 15: %d\n", depthOfNode);

    // Informar o nível de um nó
    int levelOfNode = nodeLevel(&myTree, 15);
    printf("Nivel do no com valor 15: %d\n", levelOfNode);

    // Informar o grau da árvore
    printf("Grau da arvore: %d\n", treeDegree(myTree.root));

    // Informar o grau de um nó
    int degreeOfNode = nodeDegree(myTree.root);
    printf("Grau do no com valor %d: %d\n", myTree.root->data, degreeOfNode);

    // Informar o nó de maior grau
    Node* maxDegree = maxDegreeNode(myTree.root);
    printf("No de maior grau: %d\n", maxDegree->data);

    // Informar o diâmetro da árvore
    printf("Diametro da arvore: %d\n", treeDiameter(myTree.root));

    // Liberar a memória alocada pelos nós da árvore
    freeTree(myTree.root);

    return 0;
}

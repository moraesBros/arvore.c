#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

Node *root; // Raiz da árvore

// Função para criar um novo nó
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para contar o número de nós na árvore
int countNodes(Node* root) {
    if (root == NULL) {
        return 0; // Árvore vazia tem 0 nós
    }
    
    // Conta o nó atual + nós na subárvore esquerda + nós na subárvore direita
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Função principal para testar o código
int main() {
    // Construindo uma árvore binária de exemplo
    root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(12);
    root->right->right = newNode(20);
    root->left->left->left = newNode(1);
    
    // Contando o número de nós na árvore
    int nodeCount = countNodes(root);
    
    printf("O número de nós na árvore é: %d\n", nodeCount);
    
    return 0;
}

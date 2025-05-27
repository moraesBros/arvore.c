#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

Node *root; // Raiz

// Criar um novo nó
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Contar o número de folhas na árvore
int countLeaves(Node* root) {
    if (root == NULL) {
        return 0; // Árvore vazia
    }
    
    if (root->left == NULL && root->right == NULL) {
        return 1; // Encontrou uma folha
    }
    
    // Soma as folhas das subárvores esquerda e direita
    return countLeaves(root->left) + countLeaves(root->right);
}

// Testar o código
int main() {
    // Construi uma árvore binária
    root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(12);
    root->right->right = newNode(20);
    root->left->left->left = newNode(1);
    root->right->right->left = newNode(18);
    
    // Contando o número de folhas
    int leavesCount = countLeaves(root);
    
    printf("O número de folhas na árvore é: %d\n", leavesCount);
    
    return 0;
}

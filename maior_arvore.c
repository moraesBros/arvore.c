#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Função para encontrar o maior valor na árvore
int findMax(Node* root) {
    if (root == NULL) {
        return INT_MIN; // Retorna o menor valor possível se a árvore estiver vazia
    }
    
    int res = root->key;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    
    return res;
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
    root->right->right->left = newNode(18);
    
    // Encontrando o maior valor na árvore
    int max_val = findMax(root);
    
    printf("O maior valor na árvore é: %d\n", max_val);
    
    return 0;
}

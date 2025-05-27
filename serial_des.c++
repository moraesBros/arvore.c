// Binary Tree
// Source: https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MARKER -1 
  
/* A binary tree Node has key, pointer to left and right children */
typedef struct Node Node;
struct Node { 
    int key; 
    struct Node* left, *right; 
}; 
  
/* Helper function that allocates a new Node with the 
   given key and NULL left and right pointers. */
Node* newNode(int key) {
    Node* temp;
    temp = (Node *)malloc(sizeof(Node)); 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 
  
// This function stores a tree in a file pointed by fp 
void serialize(Node *root, FILE *fp) {
    // If current node is NULL, store marker 
    if (root == NULL) {
        fprintf(fp, "%d ", MARKER); 
        return; 
    } 
    // Else, store current node and recur for its children 
    fprintf(fp, "%d ", root->key); 
    serialize(root->left, fp); 
    serialize(root->right, fp); 
} 
  
// This function constructs a tree from a file pointed by 'fp' 
Node *deSerialize(Node *root, FILE *fp) { 
    // Read next item from file. If theere are no more items or next 
    // item is marker, then return 
    int val; 
    if ( !fscanf(fp, "%d ", &val) || val == MARKER) 
       return NULL; 
    // Else create node with this item and recur for children
    root = newNode(val);
    root->left = deSerialize(root->left, fp);
    root->right = deSerialize(root->right, fp);
    return root;
}
 
// A simple inorder traversal used for testing the constructed tree
// Um percurso simples, em ordem, para testar a �rvore reconstru�da
void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* Driver program to test above functions*/
int main(int argc, char *argv[])
{ /*
Example file: 20 8 4 -1 -1 12 10 -1 -1 14 -1 -1 22 -1 -1
       20
   8         22
4    12
   10  14
*/
 
    // Let us deserialize the stored tree into root
    FILE *fp;
    Node *root = NULL;
    //struct NosFolhas nfM;

    setlocale( LC_ALL, "Portuguese");
    printf("Desserializando arquivo %s\n", argv[1]);
    fp = fopen(argv[1], "r");
    if(!fp) {
        printf("Erro na abertura do arquivo\n");
    }
    root = deSerialize(root, fp);
    fclose( fp);
 
    printf("Percorrendo a �rvore do arquivo em ordem:\n");
    inorder(root);
    return 0;
}

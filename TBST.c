#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int key) {
    if (node == NULL) return createNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d,", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    char input[1024];
    char* numberString;
    const char* delim = ",\n";

    if (fgets(input, sizeof(input), stdin) != NULL) {
        numberString = strtok(input, delim);
        while (numberString != NULL) {
            int key = atoi(numberString);
            root = insert(root, key);
            numberString = strtok(NULL, delim);
        }
    }

    preorderTraversal(root);
    return 0;
}

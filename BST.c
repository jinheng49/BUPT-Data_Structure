#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

void fillTree(int *arr, int size, struct Node** root) {
    *root = NULL;
    for (int i = 0; i < size; i++) {
        *root = insert(*root, arr[i]);
    }
}

void printGivenLevel(struct Node* root, int level, int *nodes, int *index) {
    if (root == NULL)
        return;
    if (level == 1) {
        nodes[(*index)++] = root->key;
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1, nodes, index);
        printGivenLevel(root->right, level - 1, nodes, index);
    }
}

int main() {
    int n, level;
    scanf("%d", &n);

    int arr[n];
    char comma;
    for (int i = 0; i < n; i++) {
        scanf("%d%c", &arr[i], &comma);
    }

    scanf("%d", &level);

    struct Node* root;
    fillTree(arr, n, &root);

    int nodes[20];
    int index = 0;
    printGivenLevel(root, level, nodes, &index);

    if (index == 0) {
        printf("-1\n");
    } else {
        for (int i = 0; i < index; i++) {
            printf("%d%s", nodes[i],",");
        }
    }

    return 0;
}

#include <stdlib.h>
#include "bst.h"

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == NULL || root->key == key) return root;

    if (key < root->key) return searchNode(root->left, key);
    else return searchNode(root->right, key);
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
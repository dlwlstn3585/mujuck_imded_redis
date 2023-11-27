#ifndef BST_H
#define BST_H

typedef struct Node {
    int key;
    struct Node* left, * right;
} Node;

Node* createNode(int key);
Node* insertNode(Node* root, int key);
Node* searchNode(Node* root, int key);
void freeTree(Node* root);

#endif
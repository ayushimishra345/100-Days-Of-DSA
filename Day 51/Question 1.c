
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    return root; // split point
}

int main() {
    int N;
    scanf("%d", &N);

    struct Node* root = NULL;

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}

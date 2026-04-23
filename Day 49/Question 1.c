
/*BST Insert*/

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

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    inorder(root);

    return 0;
}

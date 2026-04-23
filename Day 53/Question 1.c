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

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n && front < rear) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Node* queue[1000];
    int hd[1000];  // store horizontal distances

    int front = 0, rear = 0;

    queue[rear] = root;
    hd[rear++] = 0;

    // Store results
    int map[2000][100]; // simplistic storage
    int count[2000] = {0};
    int minHD = 1000, maxHD = -1000;

    while (front < rear) {
        struct Node* curr = queue[front];
        int h = hd[front];
        front++;

        int index = h + 1000; // shift index to avoid negative
        map[index][count[index]++] = curr->data;

        if (h < minHD) minHD = h;
        if (h > maxHD) maxHD = h;

        if (curr->left) {
            queue[rear] = curr->left;
            hd[rear++] = h - 1;
        }

        if (curr->right) {
            queue[rear] = curr->right;
            hd[rear++] = h + 1;
        }
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + 1000;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    verticalOrder(root);

    return 0;
}

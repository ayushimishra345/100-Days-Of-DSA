#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to build a circular linked list
Node* buildCircularList(int arr[], int n) {
    if (n == 0) return NULL;

    Node* head = createNode(arr[0]);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        tail->next = createNode(arr[i]);
        tail = tail->next;
    }

    // Make it circular
    tail->next = head;

    return head;
}

// Function to traverse circular linked list
void traverseCircularList(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* head = buildCircularList(arr, n);
    traverseCircularList(head);

    return 0;
}

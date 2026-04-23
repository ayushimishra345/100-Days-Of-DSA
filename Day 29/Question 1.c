
#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Build linked list from array
Node* buildList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = createNode(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = createNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

// Rotate list right by k places
Node* rotateRight(Node* head, int k, int n) {
    if (!head || k == 0 || n == 0) return head;

    // Make list circular
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = head;

    // Effective rotations
    k = k % n;
    int stepsToNewHead = n - k;

    // Find new head
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
}

// Traverse and print list
void traverseList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);

    Node* head = buildList(arr, n);
    head = rotateRight(head, k, n);
    traverseList(head);

    return 0;
}

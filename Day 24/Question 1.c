/*
Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
  */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFirstOccurrence(struct Node** head, int key) {
 
    if (*head == NULL) {
        return;
    }
    
    if ((*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    struct Node* current = *head;
    struct Node* prev = NULL;
    
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return;
    }
    
    prev->next = current->next;
    free(current);
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, key;
    
    scanf("%d", &n);
    
    struct Node* head = NULL;
    
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insertAtEnd(&head, x);
    }
    
    scanf("%d", &key);
    
    deleteFirstOccurrence(&head, key);
    
    printList(head);
    
    freeList(head);
    
    return 0;
}

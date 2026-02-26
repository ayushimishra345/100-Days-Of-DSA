/*
Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
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

struct Node* mergeTwoLists(struct Node* l1, struct Node* l2) {
    
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    if (l1 != NULL) {
        tail->next = l1;
    }
    if (l2 != NULL) {
        tail->next = l2;
    }
    
    return dummy.next;
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
    int n, m;
    
    scanf("%d", &n);
    struct Node* list1 = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insertAtEnd(&list1, x);
    }
    
    scanf("%d", &m);
    struct Node* list2 = NULL;
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        insertAtEnd(&list2, x);
    }
    
    struct Node* merged = mergeTwoLists(list1, list2);
    
    printList(merged);
    
    freeList(merged);
    
    return 0;
}

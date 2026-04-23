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

// Function to build a linked list from array
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

// Function to calculate length of linked list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection point
Node* getIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Advance longer list
    Node* p1 = head1;
    Node* p2 = head2;
    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) p1 = p1->next;
    } else {
        for (int i = 0; i < diff; i++) p2 = p2->next;
    }

    // Traverse both simultaneously
    while (p1 && p2) {
        if (p1->data == p2->data) {
            return p1; // Intersection found
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL; // No intersection
}

int main() {
    int n, m;
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr1[i]);

    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++) scanf("%d", &arr2[i]);

    Node* head1 = buildList(arr1, n);
    Node* head2 = buildList(arr2, m);

    Node* intersection = getIntersection(head1, head2);
    if (intersection) {
        printf("%d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }

    return 0;
}

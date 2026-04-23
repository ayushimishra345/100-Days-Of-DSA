
#include <stdio.h>
#include <stdlib.h>

// Circular Queue definition
typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

// Create queue
CircularQueue* createQueue(int capacity) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->capacity = capacity;
    q->arr = (int*)malloc(capacity * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

// Enqueue operation
void enqueue(CircularQueue* q, int val) {
    if (q->size == q->capacity) {
        // Queue full
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

// Dequeue operation
int dequeue(CircularQueue* q) {
    if (q->size == 0) {
        // Queue empty
        return -1;
    }
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

// Display queue elements
void displayQueue(CircularQueue* q) {
    if (q->size == 0) {
        printf("\n");
        return;
    }
    int count = q->size;
    int i = q->front;
    while (count--) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    CircularQueue* q = createQueue(n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(q, val);
    }

    int m;
    scanf("%d", &m);

    // Perform m dequeues
    for (int i = 0; i < m; i++) {
        int val = dequeue(q);
        if (val != -1) {
            enqueue(q, val);  // reinsert at rear (circular rotation)
        }
    }

    // Display queue
    displayQueue(q);

    free(q->arr);
    free(q);
    return 0;
}

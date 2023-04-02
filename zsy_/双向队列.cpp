#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
typedef struct {
    int data[MAX_SIZE];//数组实现的 
    int front;
    int rear;
} Deque;

void initDeque(Deque *dq) {
    dq->front = dq->rear = MAX_SIZE / 2;//初始化 
}
//判满判空条件 
int isFull(Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1);
}

int isEmpty(Deque *dq) {
    return dq->front == MAX_SIZE / 2;
}

void addFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    dq->front--;
    dq->data[dq->front] = value;
}

void addRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    dq->rear++;
    dq->data[dq->rear] = value;
}

int removeFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = dq->data[dq->front];
    dq->front++;
    return value;
}

int removeRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = dq->data[dq->rear];
    dq->rear--;
    return value;
}

void printDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    for (int i = dq->front; i <= dq->rear; i++) {
        printf("%d ", dq->data[i]);
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    addFront(&dq, 1);
    addFront(&dq, 2);
    addRear(&dq, 3);
    addRear(&dq, 4);

    printDeque(&dq);

    removeFront(&dq);
    removeRear(&dq);

    printDeque(&dq);

    return 0;
}


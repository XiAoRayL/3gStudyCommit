#include<stdio.h>
#include<stdlib.h>

struct qnode {
    int data;
    struct qnode* next;
    struct qnode* prev;
};

struct queue {
    struct qnode* front;
    struct qnode* rear;
};

void init(struct queue* q) {
    q->front = q->rear = NULL;
}

void inqueue_front(struct queue* q, int data) {
    struct qnode* node = (struct qnode*)malloc(sizeof(struct qnode));
    node->data = data;
    node->next = q->front;
    node->prev = NULL;
    if(q->front == NULL) {
        q->front = q->rear = node;
    } else {
        q->front->prev = node;
        q->front = node;
    }
}

void inqueue_rear(struct queue* q, int data) {
    struct qnode* node = (struct qnode*)malloc(sizeof(struct qnode));
    node->data = data;
    node->next = NULL;
    node->prev = q->rear;
    if(q->rear == NULL) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

int outqueue_front(struct queue* q) {
    if(q->front == NULL) return 0;
    int a = q->front->data;
    struct qnode* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL) q->rear = NULL;
    else q->front->prev = NULL;
    free(temp);
    return a;
}

int outqueue_rear(struct queue* q) {
    if(q->rear == NULL) return 0;
    int a = q->rear->data;
    struct qnode* temp = q->rear;
    q->rear = q->rear->prev;
    if(q->rear == NULL) q->front = NULL;
    else q->rear->next = NULL;
    free(temp);
    return a;
}

int getfront(struct queue* q) {
    if(q->front == NULL) {
        printf("NULL");
        return -1;
    }

    return q->front->data;
}

int getrear(struct queue* q) {
    if(q->rear == NULL) {
        printf("NULL");
        return -1;
    }

    return q->rear->data;
}

void pt(struct queue* q) {
    struct qnode* p = q->front;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct queue queue1;
    init(&queue1);
    inqueue_front(&queue1, 1);
    inqueue_front(&queue1, 2);
    inqueue_rear(&queue1, 3);
    inqueue_rear(&queue1, 4);
    pt(&queue1);
    outqueue_front(&queue1);
    outqueue_rear(&queue1);
    pt(&queue1);
    printf("%d ", getrear(&queue1));

    return 0;
}

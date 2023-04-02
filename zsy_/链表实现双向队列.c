#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} Node;

typedef struct deque {
    int size;
    Node* front;
    Node* rear;
} Deque;
//��ʼ��
void initDeque(Deque* deque) {
    deque->size = 0;
    deque->front = NULL;
    deque->rear = NULL;
}
//���
void pushFront(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;
    if (deque->front != NULL) {
        deque->front->prev = newNode;
    } else {
        deque->rear = newNode;
    }
    deque->front = newNode;
    deque->size++;
}

void pushBack(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = deque->rear;
    newNode->next = NULL;
    if (deque->rear != NULL) {
        deque->rear->next = newNode;
    } else {
        deque->front = newNode;
    }
    deque->rear = newNode;
    deque->size++;
}
//���� 
 int popFront(Deque* deque) {
    if (deque->front == NULL) {
        return -1; // ����Ϊ��
    }
    int data = deque->front->data;
    Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }
    free(temp);
    deque->size--;
    return data;
}

int popBack(Deque* deque) {
    if (deque->rear == NULL) {
        return -1; // ����Ϊ��
    }
    int data = deque->rear->data;
    Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }
    free(temp);
    deque->size--;
    return data;
}

int size(Deque* deque) {
    return deque->size;
}
//�п� 
int isEmpty(Deque* deque) {
    return deque->size == 0;
}
//���� 
void destroyDeque(Deque* deque) {
    while (deque->front != NULL) {
        Node* temp = deque->front;
        deque->front = deque->front->next;
        free(temp);
    }
    deque->rear = NULL;
    deque->size = 0;
}
void pri(Deque* a){
	Node *p;
	p=a->front; 
	while(p){
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n"); 
}
int main(){
	Deque a;
	initDeque(&a);
	int n;
	printf("����Ԫ�ظ�����");
	scanf("%d",&n);
	while(n--){
		int x,data;
		printf("��������뷽������0�Ӷ�β���룩\n\n"); 
		scanf("%d",&x);
		printf("���������ݣ�\n\n");
		scanf("%d",&data);
		if(!x){
			pushFront(&a, data);
		}else{
			pushBack(&a, data);
		}	
	}
	printf("��ǰ����Ԫ�أ�"); 
	pri(&a); 
	popFront(&a);
	printf("��ͷɾ����");
	pri(&a);
	popBack(&a);
	printf("��βɾ����");
	pri(&a);
	if(isEmpty(&a)){
		printf("�յ�\n");
		 
	}else{
		printf("����\n");
	};
	printf("����~~~\n");
	return 0;
} 

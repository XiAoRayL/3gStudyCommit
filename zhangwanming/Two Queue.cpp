#include<stdio.h>
#include<stdlib.h>
int count=0; 
typedef struct node{
	int data;
	struct node* next;
}Node; 
typedef struct queue{
	Node* front;
	Node* tail;
}Queue;
Queue* IntQueue();//��ʼ������ 
Node* Createnode(int data);//�����½ڵ� 
Queue* frontadd(Queue*Q,int data);//ͷ������ 
Queue* tailadd(Queue*Q,int data);//β������ 
void traverse(Queue*Q);//��ӡ���� 
int frontdel(Queue*Q);//ͷ��ɾ�� 
int taildel(Queue*Q);//β��ɾ��
int empty(Queue*Q);//�ж϶����Ƿ�Ϊ�� 
int main()
{
	Queue*Q=IntQueue();
	frontadd(Q,0);
	frontadd(Q,7);
	frontadd(Q,9);
	frontadd(Q,5);
	tailadd(Q,8);
	tailadd(Q,1);
	tailadd(Q,2);
	traverse(Q);
	//frontdel(Q);
	//traverse(Q);
	int x=frontdel(Q);
	printf("@@@%d@@@\n",x); 
	traverse(Q);
	int y=taildel(Q);
	printf("@@@%d@@@\n",y); 
	traverse(Q);
}
Queue* IntQueue()
{
	Queue*Q=(Queue*)malloc(sizeof(Queue)); 
	Q->front=NULL;
	Q->tail=NULL;
	return Q;
}
Node* Createnode(int data)
{
	Node*newnode=(Node*)malloc(sizeof(Node));
	if(!newnode){
		exit(0);
	}
	count++;
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
Queue* frontadd(Queue*Q,int data)
{
	Node*newnode=Createnode(data);
	if(Q->tail==NULL){
		Q->tail=newnode;
		Q->front=newnode;
	}else{
		newnode->next=Q->front;
		Q->front=newnode;
	}
}
Queue* tailadd(Queue*Q,int data)
{
	Node*newnode=Createnode(data);
	if(Q->tail==NULL){
		Q->tail=newnode;
		Q->front=newnode;
	}else{
		Q->tail->next=newnode;
		Q->tail=newnode;
	}
}
void traverse(Queue*Q)
{
	Queue*move=IntQueue();
	if(!empty){
		printf("����Ϊ��\n");
		exit(0);
	}
	move->front=Q->front;
	while(move->front){
		printf("%d\n",move->front->data);
		move->front=move->front->next;
	}
}
int frontdel(Queue*Q)
{
	if(empty==0){
		return 0;
	}
	int x;
	if(Q->front->next==NULL){
		x=Q->front->data;
		free(Q->front);
		Q->front=Q->tail=NULL;
	}else{
		Node*move=Q->front->next;
		x=Q->front->data;
		free(Q->front);
		Q->front=move;
	}
	return x;
}
int taildel(Queue*Q)
{
	if(empty==0){
		return 0;
	} 
	Node*move=Q->front;
	while(move->next!=Q->tail){
		move=move->next;
	}
	int x=Q->tail->data;
	free(Q->tail);
	move->next=NULL;
	Q->tail=move;
	return x;
}
int empty(Queue*Q)
{
	if(Q->front==NULL||Q->tail==NULL){
		printf("�ö���Ϊ��\n"); 
		return 0;
	}
	return 1;
}

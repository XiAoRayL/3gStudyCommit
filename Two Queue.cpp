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
Queue* IntQueue();//初始化队列 
Node* Createnode(int data);//创建新节点 
Queue* frontadd(Queue*Q,int data);//头部增加 
Queue* tailadd(Queue*Q,int data);//尾部增加 
void traverse(Queue*Q);//打印队列 
int frontdel(Queue*Q);//头部删除 
int taildel(Queue*Q);//尾部删除
int empty(Queue*Q);//判断队列是否为空 
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
		printf("队列为空\n");
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
		printf("该队列为空\n"); 
		return 0;
	}
	return 1;
}

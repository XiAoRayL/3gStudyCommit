#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<assert.h> 
typedef struct QNode{
	int date;
	struct QNode *next;
}QNode;
typedef struct {
	QNode* front;
	QNode* rear;
}LinkQueue;	
LinkQueue* IntQ();//队列的初始化 
int QueueDelete(LinkQueue *Q);//队列的销毁 
int EnQueue(LinkQueue *Q,int e);//插入元素 
int PopQueue(LinkQueue *Q);//出队 
int GetElem(LinkQueue *Q);//获取队头元素 
int empQ(LinkQueue *Q) ;//判空 
void _printf_Q(LinkQueue *Q);//打印队的元素 
int main()
{
	LinkQueue *Q=IntQ();
	assert(Q);
	EnQueue(Q,5);
	EnQueue(Q,6);
	EnQueue(Q,1);
	EnQueue(Q,5);
	EnQueue(Q,8);
	_printf_Q(Q);
	if(empQ(Q)){
		printf("该队不为空\n"); 
	}
	else{
		printf("该队为空\n");
	}
	int a = GetElem(Q);
	
	PopQueue(Q);
	printf("获得的队元素为%d\n",a);
}
LinkQueue* IntQ()
{
	LinkQueue *Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	assert(Q);
	Q->front=Q->rear=NULL;
	return Q;
}
int EnQueue(LinkQueue *Q,int e)
{
	assert(Q);
	QNode* s=(QNode*)malloc(sizeof(QNode));
	if(NULL==s){
		return 0;
	}
	s->date=e;
	s->next=NULL;
	if(Q->rear == NULL){
		assert(Q->front ==NULL);
		Q->front =s;
		Q->rear = s;
	}
	else{
		Q->rear->next=s;
		Q->rear=s;
	}
	return 0;
}
int QueueDelete(LinkQueue *Q)//队列的销毁
{
	assert(Q);
	QNode*temp=Q->front;
	while(temp){
		QNode* next=temp->next;
		free(temp);
		temp=next; 
	}
	Q->front=Q->rear=NULL;
}
int PopQueue(LinkQueue *Q)//出队 
{
	assert(Q);
	assert(Q->front&&Q->rear);
	if(Q->front->next==NULL){
		free(Q->front);
		Q->front=Q->rear=NULL;
	}
	else{
		QNode *temp=Q->front->next;
		free(Q->front);
		Q->front=temp;
	}
}
int GetElem(LinkQueue *Q)//获取队头元素 
{
	assert(Q);
	assert(Q->front&&Q->rear);
	int a=Q->front->date;
	return a;
}
int empQ(LinkQueue *Q)
{
	if(Q->front==NULL) {
		return 0;
	}
	else{
		return 1;
	}
}
void _printf_Q(LinkQueue *Q)
{
	LinkQueue *temp=IntQ();
	if(!empQ(Q)){
		printf("队列为空\n");
		exit(0);
	}
	temp->front=Q->front;
	while(temp->front){
		printf("%d\n",temp->front->date);
		temp->front=temp->front->next;
	}
}
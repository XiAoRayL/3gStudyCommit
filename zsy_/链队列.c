#include<stdio.h>
#include<stdlib.h> 
//#include <iostream>
//using namespace std;
 
typedef struct QNode{//链式队列的结点结构
	int data; //队列的数据元素类型 int
	struct QNode *next;//指向后继结点的指针
}QNode,*QueuePtr;
 
typedef struct{//链式队列
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;
 
int InitQueue(LinkQueue *Q){//构造一个空队列Q
	Q->front =Q->rear =(QueuePtr)malloc(sizeof(QNode));//产生一个头结点
	if(!Q->front )
	exit(0);//存储分配失败
	Q->front ->next=NULL; 
	return 0;
}
 
 
//队尾插入↓
int EnQueue(LinkQueue *Q,int e){
	QueuePtr p; 
	p=(QueuePtr)malloc(sizeof(QNode));//为新结点申请空间
	if(!p)
		exit(0);	
	 
	p->data=e;//将元素e存到新空间中
	p->next=NULL;  // 将新结点插到队尾
	Q->rear ->next=p; 
	Q->rear =p; 
	return 1; 
}
 
 
//队头删除↓
int DeQueue(LinkQueue *Q) { 
	QueuePtr p; 
	int e;
	if(Q->front ==Q->rear )return 0; 
	p=Q->front ->next; 
	e=p->data; 
	Q->front ->next=p->next; 
	if(Q->rear ==p)
		Q->rear =Q->front ; 
 
	free(p); 
	return e; 
}
 
 
//输入元素↓
int PrintQueue(LinkQueue Q) 
{ 
	QueuePtr p; 
	printf("链式队列中的元素"); 
	if(Q.front->next!=NULL) { 
		p=Q.front->next; 
		do { 
			printf("%5d",p->data); 
			p=p->next; 
		}while(p!=NULL); 
	}else 
		printf("队列为空\n"); 
		printf("\n"); 
	return 0; 
	}//遍历链式队列
 
//销毁队列 
void clear(LinkQueue *Q){
	QueuePtr t;
	t=Q->front;
	Q->front->next=NULL;
	free(t);
	t=Q->rear;
	Q->rear->next=NULL;
	free(t);
	Q->front=Q->rear=NULL;
} 

//判断队空 
int IsEmpty(LinkQueue Q){
	int m;
	if(Q.front==Q.rear){
		m=1;
	}else{
		m=0;//是空为假 
	}
	return m; 
} 



void main() 
{ 
	int n,e,i;
	LinkQueue Q; 
	InitQueue(&Q); 
	printf("\n");
	printf("初始化队列成功！");
	printf("\n");
	printf("请输入要进队的元素个数：\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("请输入要进队的元素：\n");
	    scanf("%d",&e);
		if(EnQueue(&Q,e))
		    printf("元素 %d 进队成功\n",e);
		else
			printf("进队失败\n");
	}
	printf("\n");
	PrintQueue(Q);
	printf("\n");
	printf("\n");
	e=DeQueue(&Q);
	printf("%d被删除！\n\n",e); 
	printf("删除队头元素后\n\n");
	PrintQueue(Q);
	printf("\n销毁~~~\n\n");
	clear(&Q);
	if(!IsEmpty(Q)){
		printf("队列不为空！\n\n");
	}else{
		printf("队列为空！\n\n");
	}
	printf("\n");
	
}

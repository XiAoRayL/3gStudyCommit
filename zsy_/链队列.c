#include<stdio.h>
#include<stdlib.h> 
//#include <iostream>
//using namespace std;
 
typedef struct QNode{//��ʽ���еĽ��ṹ
	int data; //���е�����Ԫ������ int
	struct QNode *next;//ָ���̽���ָ��
}QNode,*QueuePtr;
 
typedef struct{//��ʽ����
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;
 
int InitQueue(LinkQueue *Q){//����һ���ն���Q
	Q->front =Q->rear =(QueuePtr)malloc(sizeof(QNode));//����һ��ͷ���
	if(!Q->front )
	exit(0);//�洢����ʧ��
	Q->front ->next=NULL; 
	return 0;
}
 
 
//��β�����
int EnQueue(LinkQueue *Q,int e){
	QueuePtr p; 
	p=(QueuePtr)malloc(sizeof(QNode));//Ϊ�½������ռ�
	if(!p)
		exit(0);	
	 
	p->data=e;//��Ԫ��e�浽�¿ռ���
	p->next=NULL;  // ���½��嵽��β
	Q->rear ->next=p; 
	Q->rear =p; 
	return 1; 
}
 
 
//��ͷɾ����
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
 
 
//����Ԫ�ء�
int PrintQueue(LinkQueue Q) 
{ 
	QueuePtr p; 
	printf("��ʽ�����е�Ԫ��"); 
	if(Q.front->next!=NULL) { 
		p=Q.front->next; 
		do { 
			printf("%5d",p->data); 
			p=p->next; 
		}while(p!=NULL); 
	}else 
		printf("����Ϊ��\n"); 
		printf("\n"); 
	return 0; 
	}//������ʽ����
 
//���ٶ��� 
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

//�ж϶ӿ� 
int IsEmpty(LinkQueue Q){
	int m;
	if(Q.front==Q.rear){
		m=1;
	}else{
		m=0;//�ǿ�Ϊ�� 
	}
	return m; 
} 



void main() 
{ 
	int n,e,i;
	LinkQueue Q; 
	InitQueue(&Q); 
	printf("\n");
	printf("��ʼ�����гɹ���");
	printf("\n");
	printf("������Ҫ���ӵ�Ԫ�ظ�����\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("������Ҫ���ӵ�Ԫ�أ�\n");
	    scanf("%d",&e);
		if(EnQueue(&Q,e))
		    printf("Ԫ�� %d ���ӳɹ�\n",e);
		else
			printf("����ʧ��\n");
	}
	printf("\n");
	PrintQueue(Q);
	printf("\n");
	printf("\n");
	e=DeQueue(&Q);
	printf("%d��ɾ����\n\n",e); 
	printf("ɾ����ͷԪ�غ�\n\n");
	PrintQueue(Q);
	printf("\n����~~~\n\n");
	clear(&Q);
	if(!IsEmpty(Q)){
		printf("���в�Ϊ�գ�\n\n");
	}else{
		printf("����Ϊ�գ�\n\n");
	}
	printf("\n");
	
}

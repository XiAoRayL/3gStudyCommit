#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}ST;//��ջ�Ĵ洢���� 
ST *top;
//��ʼ��
ST *Init();
//�п�
bool Empty(ST *top);
//��ջ
void Push(ST *top,int x); 
//��ջ
int Pop(ST *top);//Ϊʲô����*����&���� 
//��ջ��Ԫ��
int GetTop(ST *top);
//����ջ
void PrintStack(ST *top);//�ܷ�ʵ�� 
//����ջ 
void destroy(ST *top); 
int main(){
	 ST *top;
	 top=Init();
	 int n;
	 while(1){
	 	printf("��������ջԪ�أ�(-1�˳�)"); 
	 	scanf("%d",&n); 
	 	if(n==-1){
	 		break;
		 } 
	 	Push(top,n);
	 }
	 printf("ջ��Ԫ�أ�"); 
     PrintStack(top);
	 int x;
	 x = Pop(top);
	 printf("\n%d��ջ\n",x); 
	 printf("��ջ��");
	 PrintStack(top); 
	 int t=GetTop(top);
	 printf("ջ��Ԫ����%d\n",t);
	 //PrintStack(top);
	 if(!Empty(top)){
	 	printf("ջ��Ϊ��\n"); 
	 }else{
	 	printf("ջΪ��\n");
	 }
	 printf("����~~~~~\n"); 
	 destroy(top); 
	// PrintStack(top);
	  if(!Empty(top)){
	 	printf("ջ��Ϊ��\n"); 
	 }else{
	 	printf("ջΪ��\n");
	 }
} 
ST *Init(){
	ST *top = (ST *)malloc(sizeof(ST));
	if(top != NULL){//����ɹ� 
		top->next = NULL;//ջ��ָ��Ϊ�� 
	}
	return top; 
}
bool Empty(ST *top){
	if(top->next == NULL){
		return true;
	} else{
		return false;
	}
} 
void Push(ST *top,int x){
	ST *node;
	node = (ST *)malloc(sizeof(ST));
	assert(node);//����ɹ� 
	node->data = x;
	node->next = top->next ;
	top->next = node; 
} 
int Pop(ST *top){
	assert(top->next);//ջ��Ϊ��
	int x = top->next->data ;
	ST *p = top->next ;
	top->next = top->next->next ; 
	p->next = NULL;
	free(p);
	return x;	
	
} 
int GetTop(ST *top){
	assert(top->next);//ջ��Ϊ��
	return top->next->data ; 
}
void PrintStack(ST *top){
	ST *p;
	assert(top->next); 
	p = top->next ;
	while(p){
		printf("%d ",p->data);
		p = p->next ;
	}
} 
void destroy(ST *top){
	top->next = NULL;
}

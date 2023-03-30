#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}ST;//链栈的存储类型 
ST *top;
//初始化
ST *Init();
//判空
bool Empty(ST *top);
//进栈
void Push(ST *top,int x); 
//出栈
int Pop(ST *top);//为什么他用*，用&试试 
//读栈顶元素
int GetTop(ST *top);
//遍历栈
void PrintStack(ST *top);//能否实现 
//销毁栈 
void destroy(ST *top); 
int main(){
	 ST *top;
	 top=Init();
	 int n;
	 while(1){
	 	printf("请输入入栈元素：(-1退出)"); 
	 	scanf("%d",&n); 
	 	if(n==-1){
	 		break;
		 } 
	 	Push(top,n);
	 }
	 printf("栈的元素："); 
     PrintStack(top);
	 int x;
	 x = Pop(top);
	 printf("\n%d出栈\n",x); 
	 printf("出栈后：");
	 PrintStack(top); 
	 int t=GetTop(top);
	 printf("栈顶元素是%d\n",t);
	 //PrintStack(top);
	 if(!Empty(top)){
	 	printf("栈不为空\n"); 
	 }else{
	 	printf("栈为空\n");
	 }
	 printf("销毁~~~~~\n"); 
	 destroy(top); 
	// PrintStack(top);
	  if(!Empty(top)){
	 	printf("栈不为空\n"); 
	 }else{
	 	printf("栈为空\n");
	 }
} 
ST *Init(){
	ST *top = (ST *)malloc(sizeof(ST));
	if(top != NULL){//申请成功 
		top->next = NULL;//栈顶指针为空 
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
	assert(node);//申请成功 
	node->data = x;
	node->next = top->next ;
	top->next = node; 
} 
int Pop(ST *top){
	assert(top->next);//栈不为空
	int x = top->next->data ;
	ST *p = top->next ;
	top->next = top->next->next ; 
	p->next = NULL;
	free(p);
	return x;	
	
} 
int GetTop(ST *top){
	assert(top->next);//栈不为空
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

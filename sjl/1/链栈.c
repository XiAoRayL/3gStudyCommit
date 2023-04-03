#include<stdio.h>
#include<stdlib.h>
struct stacknode{
	int data;
	struct stacknode* next;
};
struct stack{
	struct stacknode* top;
};
struct stack* creatStack(){
	struct stack* s = (struct stack*)malloc(sizeof(struct stack));
	s->top = NULL;
	return s;
}
int empty(struct stack* s){
	if(s->top == NULL) return 1;
	else return 0;
}
void push(struct stack* s,int data){
	struct stacknode* node = (struct stacknode*)malloc(sizeof(struct stacknode));
	node->data = data;
	node->next = s->top;
	s->top = node;
}
int pop(struct stack* s){
	if(empty(s)) return 0;
	int a = s->top->data;
	struct stacknode* temp = s->top;
	s->top = s->top->next;
	free(temp);
	return a;
}
int gettop(struct stack* s){
	if(s->top!=NULL) return s->top->data;
	else return 0;
}
void pt(struct stack* s){
	struct stacknode* temp = s->top;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void destory(struct stack* s){
	struct stacknode* temp;
	while(s->top != NULL){
		temp = s->top;
		s->top = s->top->next;
		free(temp);
	}
}
int main(){
	struct stack* stack1  = creatStack();
	push(stack1,1);
	push(stack1,2);
	push(stack1,3);
	push(stack1,4);
	pt(stack1);
	pop(stack1);
	pt(stack1);
}

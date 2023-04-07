#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree {
    int data;
    struct BiTree* lchild;
    struct BiTree* rchild;
} Tree;
typedef struct queue{
	Tree* data[100];
	int front;
	int rear;
}queue; 
queue* createqueue(){
queue* q = (queue*)malloc(sizeof(queue));
q->front = -1;
q->rear = -1;
return q;
}
void enqueue(queue*q,Tree* node){
	if(q->front == -1){
		q->front = 0;
	}
	q->rear++;
	q->data[q->rear] = node;
}
Tree* dequeue(queue* q){
	Tree* node = q->data[q->front];
	if(q->rear == q->front){
	q->rear = -1;
	q->front = -1;		
	}
	else{
		q->front++;
	}
	return node;
}
Tree* createNode(int data) {
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}
void cengxv(Tree* root){
	if(root == NULL) return;
	queue* q = createqueue();
	enqueue(q,root);
	while(q->front != -1){
		Tree* node = dequeue(q);
		printf("%d ",node->data);
		if(node->lchild != NULL) enqueue(q,node->lchild);
		if(node->rchild != NULL) enqueue(q,node->rchild);
	}
}
void insert(Tree** root, int data) {
	if (*root == NULL){
		*root = createNode(data);
		return;
	}
	if(data<(*root)->data){
		insert(&((*root)->lchild),data);
	}
	else{
		insert(&((*root)->rchild),data);
	}
}
void xianxv(Tree* root){
	if(root != NULL){
		printf("%d ",root->data);
		xianxv(root->lchild);
		xianxv(root->rchild);
	}
	
}
void zhongxv(Tree* root){
	if(root != NULL){
		zhongxv(root->lchild);
		printf("%d ",root->data);
		zhongxv(root->rchild);
	}
	
}
void houxv(Tree* root){
	if(root != NULL){
		houxv(root->lchild);
		houxv(root->rchild);
		printf("%d ",root->data);
	}
	
}
int main(){
	Tree* root = NULL;
	insert(&root,4);
	insert(&root,2);
	insert(&root,6);
	insert(&root,1);
	insert(&root,3);
	insert(&root,5);
	insert(&root,7);
	cengxv(root);
	printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct node{
	int data;
	struct node *l_child;
	struct node *r_child;
}Tree;
void Middle(Tree* tree);//中序遍历 
void Nremiddle(Tree* tree);//非递归 非递归中序遍历 
void first(Tree* tree);//先序遍历 
void Nrefirst(Tree* tree);//非递归 前序遍历 
void last(Tree* tree);//后序遍历 
void Nrelast(Tree* tree);//非递归 后序遍历 
void Nrelasteasy(Tree* tree);//非递归 后序遍历（easy) 
void levertraversal(Tree* tree);//层次遍历 
Tree *Create_Tree();//创建二叉树 
int treedepth(Tree *tree);//树的深度 
int Nretreedepth(Tree *tree);//非递归 树的深度 
int main()
{
	Tree*tree;
	tree=Create_Tree();
	printf("中序遍历\n");
	Middle(tree);
	printf("先序遍历\n");
	first(tree);
	printf("后序遍历\n");
	last(tree);
	printf("非递归中序遍历\n");
	Nremiddle(tree);
	printf("非递归先序遍历\n");
	Nrefirst(tree);
	printf("非递归后序遍历\n");
	Nrelast(tree);
	printf("非递归后序遍历,简单版本\n");
	Nrelasteasy(tree);
	printf("层次遍历\n");
	levertraversal(tree);
	printf("递归计算树的深度%d\n",treedepth(tree));
	printf("非递归计算树的深度%d\n",Nretreedepth(tree));
}

void Middle(Tree* tree)
{
	if(tree==NULL){
		return ;
	} 
	Middle(tree->l_child);
	printf("%d\n",tree->data);
	Middle(tree->r_child);
	
}
void first(Tree* tree)
{
	if(tree==NULL){
		return ;
	}
	printf("%d\n",tree->data);
	first(tree->l_child);
	first(tree->r_child);
	
}
void last(Tree* tree)
{
	if(tree==NULL){
		return;
	} 
	last(tree->l_child);
	last(tree->r_child);
	printf("%d\n",tree->data);
	
}
Tree *Create_Tree()
{
	Tree *root=NULL;
	int data;
	scanf("%d", &data);//通过输入的ch是否为特殊符号来判断该节点是否有孩子节点
	if(data == -1){	//不存在孩子节点
		root=NULL;
	}else{
		root = (Tree *)malloc(sizeof(Tree));
		if(NULL == root){
			printf("创建失败\n");
			return NULL;
		}	
		root->data = data;
		root->l_child = Create_Tree();//存在左孩子节点，递归调用本函数，使得左孩子节点先被赋值
		root->r_child = Create_Tree();		
	}
	return root;
}
void Nremiddle(Tree* tree)
{
	Tree *stack[MAX],*node;
	int top=0;
	if(tree==NULL){
		printf("这个树为空\n");
		return;
	}
	node=tree;
	while(node!=NULL||top>0){
		while(node!=NULL){
			top++;
			stack[top]=node;
			node=node->l_child;
		}
		node=stack[top];
		top--;
		printf("%d\n",node->data);
		node=node->r_child;
	}
}
void Nrefirst(Tree* tree)
{
	Tree *stack[MAX],*node;
	int top=0;
	if(tree==NULL){
		printf("这个树为空\n");
		return ;
	}else{
		top++;
		stack[top]=tree;
		while(top>0){
			node=stack[top];
			top--;
			printf("%d\n",node->data);
			if(node->r_child!=NULL){
				top++;
				stack[top]=node->r_child;
			}
			if(node->l_child!=NULL){
				top++;
				stack[top]=node->l_child;
			}
		}
	}
}
void Nrelast(Tree* tree)
{
	Tree *stack[MAX],*node=tree,*r=NULL;
	int top=0;
	if(tree==NULL){
		printf("这个树为空\n");
		return;
	}
	while(node||top>0){
		while(node){
			stack[top]=node;
			top++;
			node=node->l_child; 
		}
		node=stack[top-1];
		if(NULL==node->r_child||node->r_child==r){
			printf("%d\n",node->data);
			top--;
			r=node;
			node=NULL;
		}else{
			node=node->r_child;
		}
	}
}
void Nrelasteasy(Tree* tree)//非递归 后序遍历（easy) 
{
	Tree* stack[MAX],*node;
	int top=0,count=0,i;
	int array[MAX]={0};
	if(tree==NULL){
		printf("该树为空\n");
	}else{
		top++;
		stack[top]=tree;
		while(top>0){
			node=stack[top];
			top--;
			array[count++]=node->data;
			if(node->l_child!=NULL){
				top++;
				stack[top]=node->l_child;
			}
			if(node->r_child!=NULL){
				top++;
				stack[top]=node->r_child;
			}
		}
		for(i=count-1;i>=0;i--){
			printf("%d\n",array[i]);
		}
	}
}
void levertraversal(Tree* tree)
{
	if(tree==NULL){
		printf("该树为空\n");
		return;
	} 
	Tree *queue[MAX],*node;
	int front=0,rear=0;
	queue[rear++]=tree;
	while(front!=rear){
		node=queue[front++];
		printf("%d\n",node->data);
		if(node->l_child != NULL){
			queue[rear++] = node->l_child;
		}
		if(node->r_child != NULL){
			queue[rear++] = node->r_child;
		}
	}
}
int treedepth(Tree *tree)//树的深度 
{
	 int depth1 = 0,depth2 = 0;
	if(tree == NULL){
		return 0;
	}else{
		depth1=treedepth(tree->l_child);
		depth2=treedepth(tree->r_child);
		return depth1>depth2?depth1+1:depth2+1;
	}
}
int Nretreedepth(Tree *tree)//非递归 树的深度 
{
	Tree *queue[MAX],*node;
	node=tree;
	int front = 0,rear = 0,depth = 0,level;
	if(tree != NULL){
		queue[++rear] = node;
	}
	level=rear;
	while(front<rear){
		node=queue[++front];
		if(node->l_child != NULL){
			queue[++rear] = node->l_child;
		}
		if(node->r_child != NULL){
			queue[++rear] = node->r_child;
		}
		if(front == level){
			depth++;
			level = rear;
		}
	}
	return depth;
}

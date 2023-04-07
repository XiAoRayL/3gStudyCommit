#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct node{
	int data;
	struct node *l_child;
	struct node *r_child;
}Tree;
void Middle(Tree* tree);//������� 
void Nremiddle(Tree* tree);//�ǵݹ� �ǵݹ�������� 
void first(Tree* tree);//������� 
void Nrefirst(Tree* tree);//�ǵݹ� ǰ����� 
void last(Tree* tree);//������� 
void Nrelast(Tree* tree);//�ǵݹ� ������� 
void Nrelasteasy(Tree* tree);//�ǵݹ� ���������easy) 
void levertraversal(Tree* tree);//��α��� 
Tree *Create_Tree();//���������� 
int treedepth(Tree *tree);//������� 
int Nretreedepth(Tree *tree);//�ǵݹ� ������� 
int main()
{
	Tree*tree;
	tree=Create_Tree();
	printf("�������\n");
	Middle(tree);
	printf("�������\n");
	first(tree);
	printf("�������\n");
	last(tree);
	printf("�ǵݹ��������\n");
	Nremiddle(tree);
	printf("�ǵݹ��������\n");
	Nrefirst(tree);
	printf("�ǵݹ�������\n");
	Nrelast(tree);
	printf("�ǵݹ�������,�򵥰汾\n");
	Nrelasteasy(tree);
	printf("��α���\n");
	levertraversal(tree);
	printf("�ݹ�����������%d\n",treedepth(tree));
	printf("�ǵݹ�����������%d\n",Nretreedepth(tree));
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
	scanf("%d", &data);//ͨ�������ch�Ƿ�Ϊ����������жϸýڵ��Ƿ��к��ӽڵ�
	if(data == -1){	//�����ں��ӽڵ�
		root=NULL;
	}else{
		root = (Tree *)malloc(sizeof(Tree));
		if(NULL == root){
			printf("����ʧ��\n");
			return NULL;
		}	
		root->data = data;
		root->l_child = Create_Tree();//�������ӽڵ㣬�ݹ���ñ�������ʹ�����ӽڵ��ȱ���ֵ
		root->r_child = Create_Tree();		
	}
	return root;
}
void Nremiddle(Tree* tree)
{
	Tree *stack[MAX],*node;
	int top=0;
	if(tree==NULL){
		printf("�����Ϊ��\n");
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
		printf("�����Ϊ��\n");
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
		printf("�����Ϊ��\n");
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
void Nrelasteasy(Tree* tree)//�ǵݹ� ���������easy) 
{
	Tree* stack[MAX],*node;
	int top=0,count=0,i;
	int array[MAX]={0};
	if(tree==NULL){
		printf("����Ϊ��\n");
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
		printf("����Ϊ��\n");
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
int treedepth(Tree *tree)//������� 
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
int Nretreedepth(Tree *tree)//�ǵݹ� ������� 
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

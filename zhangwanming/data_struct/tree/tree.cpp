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
Tree *Create_Tree();//创建二叉树 
void Nrelasteasy(Tree* tree);//非递归 后序遍历（easy) 
void levertraversal(Tree* tree);//层次遍历 
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
    //如果树为空的话，就返回
	if(tree==NULL){
		return ;
	}
    //打印该节点的数据
	printf("%d\n",tree->data);
    //递归调用，打印左孩子的
	first(tree->l_child);
     //递归调用，打印右孩子的
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
    //先申明一个空指针
	Tree *root=NULL;
	int data;
	scanf("%d", &data);//通过输入的ch是否为特殊符号来判断该节点是否有孩子节点
    //这里可以用任何的特殊字符，根据自己来定义
	if(data == -1){	//不存在孩子节点
		root=NULL;
	}else{
        //当这个数据需要存储的时候要，我们就需要离开开辟空间
		root = (Tree *)malloc(sizeof(Tree));
        //如果开辟失败，就返回
		if(NULL == root){
			printf("创建失败\n");
			return NULL;
		}	
        //将数据存储到根节点里面
		root->data = data;
		root->l_child = Create_Tree();//存在左孩子节点，递归调用本函数，使得左孩子节点先被赋值
		root->r_child = Create_Tree();//存在右孩子节点，递归调用本函数，使得右孩子节点后被赋值
	}
    //最后将该节点返回
	return root;
}
void Nremiddle(Tree* tree)
{
    //先申明一个栈类型的指针，为了后面的操作
	Tree *stack[MAX],*node;
    //初始化栈为空
	int top=0;
    //如果树为空的话，就返回
	if(tree==NULL){
		printf("这个树为空\n");
		return;
	}
    //用另外的指针来存树
	node=tree;
    //树为空，或者栈为空的时候，我们就返回
	while(node!=NULL||top>0){
        //将树的所有节点都先存到栈里面
		while(node!=NULL){
			top++;//我们栈的第一个空间不存储数据
			stack[top]=node;//将数据存储到栈里面
			node=node->l_child;//一直换到左孩子指针为空
		}
        //取出栈顶元素
		node=stack[top];
		top--;//对索引进行操作
		printf("%d\n",node->data);//打印该数据
		node=node->r_child;//对有孩子进行存储
	}
}
void Nrefirst(Tree* tree)
{
     //先申明一个栈类型的指针，为了后面的操作
	Tree *stack[MAX],*node;
	int top=0;//初始化栈
    //如果树为空的话，就返回
	if(tree==NULL){
		printf("这个树为空\n");
		return ;
	}else{
		top++;//对索引进行操作，栈第一个位置不存储数据
		stack[top]=tree;//将树存到栈里面
        //如果栈为空，就退出循环
		while(top>0){
            //取出栈顶元素
			node=stack[top];
			top--;//对索引进行操作
			printf("%d\n",node->data);//打印该节点的数据
            //将该节点的右孩子先存到栈里面，再把左孩子存到里面，因为栈是先进后出的
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
    //初始化栈，定义一个虚拟指针r，利用node把树存进去
	Tree *stack[MAX],*node=tree,*r=NULL;
	int top=0;//初始化栈为空
     //如果树为空的话，就返回
	if(tree==NULL){
		printf("这个树为空\n");
		return;
	}
    //树为空，或者栈为空的时候，我们就退出循环
	while(node||top>0){
        //先把左边的节点全部存到栈里面
		while(node){
			stack[top]=node;
			top++;//对索引操作
			node=node->l_child; 
		}
        //因为之前的加一，所以这里我们需要减1
		node=stack[top-1];
        //此节点没有右孩子或者右孩子已经访问过
		if(NULL==node->r_child||node->r_child==r){
			printf("%d\n",node->data);
			top--;
			r=node;//记录最近访问过的节点
			node=NULL;//节点访问过的节点
		}else{
			node=node->r_child;//右孩子存在则指向右孩子，重复上面操作
		}
	}
}
void Nrelasteasy(Tree* tree)//非递归 后序遍历（easy) 
{
    //定义栈，为了操作树的存储
	Tree* stack[MAX],*node;
    //定义数组，方便后续进行的输出
    int array[MAX]={0};
    //初始化对列，count用来记录一共有多少个数
	int top=0,count=0,i;
	//判断仅从遍历的树是否为空，如果为空的话，就返回
	if(tree==NULL){
		printf("该树为空\n");
        return;
	}else{
        //为了方便，在栈的第一位不存数据
		top++;
        //将树的根节点赋值给栈的第一位
		stack[top]=tree;
        //如果栈为为空，我们就退出整个循环
		while(top>0){
            //取出栈顶元素
			node=stack[top];
            //对栈的指针进行操作
			top--;
            //将该节点的数据存到数组里面，同时我们要把数组的索引进行操作
			array[count++]=node->data;
            //因为栈是先进后出的，所以我们先把该节点的左孩子入栈，再把该节点的右孩子入栈
			if(node->l_child!=NULL){
				top++;
				stack[top]=node->l_child;
			}
			if(node->r_child!=NULL){
				top++;
				stack[top]=node->r_child;
			}
		}
        //最后就是要反着把所有的数组数据输出
		for(i=count-1;i>=0;i--){
			printf("%d\n",array[i]);
		}
	}
}
void levertraversal(Tree* tree)
{
    //如果数组为空，那么我们就返回
	if(tree==NULL){
		printf("该树为空\n");
		return;
	} 
    //定义队列，为了存储树的数据
	Tree *queue[MAX],*node;
    //初始化队列的指针
	int front=0,rear=0;
    //将树的根节点赋值给队列，同时将尾指针向后移动
	queue[rear++]=tree;
    //如果队列为空，我们就退出整个循环
	while(front!=rear){
        //取出队头元素
		node=queue[front++];
        //输出该节点的数据
		printf("%d\n",node->data);
        //如果该节点的左右有孩子，就将孩子入队，先将左孩子入队，再将右孩子入队，因为队列是先进先出的数据结构
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
    //定义两个数据，用来记录树的深度
	int depth1 = 0,depth2 = 0;
    //如果树为空，那么我们返回的数值就为0
	if(tree == NULL){
		return 0;
	}else{
        //对左右孩子进行继续的遍历
		depth1=treedepth(tree->l_child);
		depth2=treedepth(tree->r_child);
        //判断出左右孩子那个最大，然后要反回他的深度+1，如果没有的话会返回0，他的深度也不会增加
		return depth1>depth2?depth1+1:depth2+1;
	}
}
int Nretreedepth(Tree *tree)//非递归 树的深度 
{
    //定义队列
	Tree *queue[MAX],*node;
    //为了方便操作，用node来操作
	node=tree;
    //初始化队列，depth用来记录他的深度，我们用level指向队列的队尾元素
	int front = 0,rear = 0,depth = 0,level;
    //如果树不为空，我们就把树的根节点赋值给队列的尾
	if(tree != NULL){
		queue[++rear] = node;
	}
    //让level指向队尾指针
	level=rear;
    //如果队为空的话，我们就退出整个循环
	while(front<rear){
        //取出队头元素，同时将队头指针向后移动
		node=queue[++front];
        //将该节点的左右孩子先入队，因为队列是先进先出，所以先将左孩子入队，再将右孩子入队
		if(node->l_child != NULL){
			queue[++rear] = node->l_child;
		}
		if(node->r_child != NULL){
			queue[++rear] = node->r_child;
		}
        //如果头指针等于之前标记的尾节点，那么说明这个层已经全部被遍历，所以这个深度需要加加
		if(front == level){
			depth++;
            //接着需要把这个让level指向当前的尾节点，方便后面的查找
			level = rear;
		}
	}
    //返回这个深度
	return depth;
}

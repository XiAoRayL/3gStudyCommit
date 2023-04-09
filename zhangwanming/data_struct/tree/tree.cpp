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
Tree *Create_Tree();//���������� 
void Nrelasteasy(Tree* tree);//�ǵݹ� ���������easy) 
void levertraversal(Tree* tree);//��α��� 
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
    //�����Ϊ�յĻ����ͷ���
	if(tree==NULL){
		return ;
	}
    //��ӡ�ýڵ������
	printf("%d\n",tree->data);
    //�ݹ���ã���ӡ���ӵ�
	first(tree->l_child);
     //�ݹ���ã���ӡ�Һ��ӵ�
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
    //������һ����ָ��
	Tree *root=NULL;
	int data;
	scanf("%d", &data);//ͨ�������ch�Ƿ�Ϊ����������жϸýڵ��Ƿ��к��ӽڵ�
    //����������κε������ַ��������Լ�������
	if(data == -1){	//�����ں��ӽڵ�
		root=NULL;
	}else{
        //�����������Ҫ�洢��ʱ��Ҫ�����Ǿ���Ҫ�뿪���ٿռ�
		root = (Tree *)malloc(sizeof(Tree));
        //�������ʧ�ܣ��ͷ���
		if(NULL == root){
			printf("����ʧ��\n");
			return NULL;
		}	
        //�����ݴ洢�����ڵ�����
		root->data = data;
		root->l_child = Create_Tree();//�������ӽڵ㣬�ݹ���ñ�������ʹ�����ӽڵ��ȱ���ֵ
		root->r_child = Create_Tree();//�����Һ��ӽڵ㣬�ݹ���ñ�������ʹ���Һ��ӽڵ�󱻸�ֵ
	}
    //��󽫸ýڵ㷵��
	return root;
}
void Nremiddle(Tree* tree)
{
    //������һ��ջ���͵�ָ�룬Ϊ�˺���Ĳ���
	Tree *stack[MAX],*node;
    //��ʼ��ջΪ��
	int top=0;
    //�����Ϊ�յĻ����ͷ���
	if(tree==NULL){
		printf("�����Ϊ��\n");
		return;
	}
    //�������ָ��������
	node=tree;
    //��Ϊ�գ�����ջΪ�յ�ʱ�����Ǿͷ���
	while(node!=NULL||top>0){
        //���������нڵ㶼�ȴ浽ջ����
		while(node!=NULL){
			top++;//����ջ�ĵ�һ���ռ䲻�洢����
			stack[top]=node;//�����ݴ洢��ջ����
			node=node->l_child;//һֱ��������ָ��Ϊ��
		}
        //ȡ��ջ��Ԫ��
		node=stack[top];
		top--;//���������в���
		printf("%d\n",node->data);//��ӡ������
		node=node->r_child;//���к��ӽ��д洢
	}
}
void Nrefirst(Tree* tree)
{
     //������һ��ջ���͵�ָ�룬Ϊ�˺���Ĳ���
	Tree *stack[MAX],*node;
	int top=0;//��ʼ��ջ
    //�����Ϊ�յĻ����ͷ���
	if(tree==NULL){
		printf("�����Ϊ��\n");
		return ;
	}else{
		top++;//���������в�����ջ��һ��λ�ò��洢����
		stack[top]=tree;//�����浽ջ����
        //���ջΪ�գ����˳�ѭ��
		while(top>0){
            //ȡ��ջ��Ԫ��
			node=stack[top];
			top--;//���������в���
			printf("%d\n",node->data);//��ӡ�ýڵ������
            //���ýڵ���Һ����ȴ浽ջ���棬�ٰ����Ӵ浽���棬��Ϊջ���Ƚ������
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
    //��ʼ��ջ������һ������ָ��r������node�������ȥ
	Tree *stack[MAX],*node=tree,*r=NULL;
	int top=0;//��ʼ��ջΪ��
     //�����Ϊ�յĻ����ͷ���
	if(tree==NULL){
		printf("�����Ϊ��\n");
		return;
	}
    //��Ϊ�գ�����ջΪ�յ�ʱ�����Ǿ��˳�ѭ��
	while(node||top>0){
        //�Ȱ���ߵĽڵ�ȫ���浽ջ����
		while(node){
			stack[top]=node;
			top++;//����������
			node=node->l_child; 
		}
        //��Ϊ֮ǰ�ļ�һ����������������Ҫ��1
		node=stack[top-1];
        //�˽ڵ�û���Һ��ӻ����Һ����Ѿ����ʹ�
		if(NULL==node->r_child||node->r_child==r){
			printf("%d\n",node->data);
			top--;
			r=node;//��¼������ʹ��Ľڵ�
			node=NULL;//�ڵ���ʹ��Ľڵ�
		}else{
			node=node->r_child;//�Һ��Ӵ�����ָ���Һ��ӣ��ظ��������
		}
	}
}
void Nrelasteasy(Tree* tree)//�ǵݹ� ���������easy) 
{
    //����ջ��Ϊ�˲������Ĵ洢
	Tree* stack[MAX],*node;
    //�������飬����������е����
    int array[MAX]={0};
    //��ʼ�����У�count������¼һ���ж��ٸ���
	int top=0,count=0,i;
	//�жϽ��ӱ��������Ƿ�Ϊ�գ����Ϊ�յĻ����ͷ���
	if(tree==NULL){
		printf("����Ϊ��\n");
        return;
	}else{
        //Ϊ�˷��㣬��ջ�ĵ�һλ��������
		top++;
        //�����ĸ��ڵ㸳ֵ��ջ�ĵ�һλ
		stack[top]=tree;
        //���ջΪΪ�գ����Ǿ��˳�����ѭ��
		while(top>0){
            //ȡ��ջ��Ԫ��
			node=stack[top];
            //��ջ��ָ����в���
			top--;
            //���ýڵ�����ݴ浽�������棬ͬʱ����Ҫ��������������в���
			array[count++]=node->data;
            //��Ϊջ���Ƚ�����ģ����������ȰѸýڵ��������ջ���ٰѸýڵ���Һ�����ջ
			if(node->l_child!=NULL){
				top++;
				stack[top]=node->l_child;
			}
			if(node->r_child!=NULL){
				top++;
				stack[top]=node->r_child;
			}
		}
        //������Ҫ���Ű����е������������
		for(i=count-1;i>=0;i--){
			printf("%d\n",array[i]);
		}
	}
}
void levertraversal(Tree* tree)
{
    //�������Ϊ�գ���ô���Ǿͷ���
	if(tree==NULL){
		printf("����Ϊ��\n");
		return;
	} 
    //������У�Ϊ�˴洢��������
	Tree *queue[MAX],*node;
    //��ʼ�����е�ָ��
	int front=0,rear=0;
    //�����ĸ��ڵ㸳ֵ�����У�ͬʱ��βָ������ƶ�
	queue[rear++]=tree;
    //�������Ϊ�գ����Ǿ��˳�����ѭ��
	while(front!=rear){
        //ȡ����ͷԪ��
		node=queue[front++];
        //����ýڵ������
		printf("%d\n",node->data);
        //����ýڵ�������к��ӣ��ͽ�������ӣ��Ƚ�������ӣ��ٽ��Һ�����ӣ���Ϊ�������Ƚ��ȳ������ݽṹ
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
    //�����������ݣ�������¼�������
	int depth1 = 0,depth2 = 0;
    //�����Ϊ�գ���ô���Ƿ��ص���ֵ��Ϊ0
	if(tree == NULL){
		return 0;
	}else{
        //�����Һ��ӽ��м����ı���
		depth1=treedepth(tree->l_child);
		depth2=treedepth(tree->r_child);
        //�жϳ����Һ����Ǹ����Ȼ��Ҫ�����������+1�����û�еĻ��᷵��0���������Ҳ��������
		return depth1>depth2?depth1+1:depth2+1;
	}
}
int Nretreedepth(Tree *tree)//�ǵݹ� ������� 
{
    //�������
	Tree *queue[MAX],*node;
    //Ϊ�˷����������node������
	node=tree;
    //��ʼ�����У�depth������¼������ȣ�������levelָ����еĶ�βԪ��
	int front = 0,rear = 0,depth = 0,level;
    //�������Ϊ�գ����ǾͰ����ĸ��ڵ㸳ֵ�����е�β
	if(tree != NULL){
		queue[++rear] = node;
	}
    //��levelָ���βָ��
	level=rear;
    //�����Ϊ�յĻ������Ǿ��˳�����ѭ��
	while(front<rear){
        //ȡ����ͷԪ�أ�ͬʱ����ͷָ������ƶ�
		node=queue[++front];
        //���ýڵ�����Һ�������ӣ���Ϊ�������Ƚ��ȳ��������Ƚ�������ӣ��ٽ��Һ������
		if(node->l_child != NULL){
			queue[++rear] = node->l_child;
		}
		if(node->r_child != NULL){
			queue[++rear] = node->r_child;
		}
        //���ͷָ�����֮ǰ��ǵ�β�ڵ㣬��ô˵��������Ѿ�ȫ����������������������Ҫ�Ӽ�
		if(front == level){
			depth++;
            //������Ҫ�������levelָ��ǰ��β�ڵ㣬�������Ĳ���
			level = rear;
		}
	}
    //����������
	return depth;
}

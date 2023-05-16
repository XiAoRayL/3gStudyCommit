#include<stdio.h>
#include<stdlib.h>
//���������Ϊ�˷����Ǹ��ط������ڱ� 
#define INF 65535 
#define MaxVer 10
typedef struct {
	char vers[10];
	int edges[10][10];
	int numVertexs;
	int numEdges;
}Graph;
Graph* InitGraph();//��ʼ���ڽӾ��� 
void CreateGraph(Graph *G);//�����ڽӾ��� 
void PrintfGraph(Graph *G);//��ӡ�ڽӾ��� 
int main()
{
	Graph* G = InitGraph(); 
	CreateGraph(G);
	PrintfGraph(G);
} 
//��ʼ���ڽӾ��� 
Graph* InitGraph()
{
	//����һ��ͼ���͵�ָ�� 
	Graph *G;
	int i, j;
	//Ϊ���ָ�뿪�ٿռ� 
	G = (Graph*)malloc(sizeof(Graph));
	//���г�ʼ�� 
	for (i = 0; i < MaxVer; i++) {
		for (j = 0; j < MaxVer; j++){
			//�������ھ���ĶԽ������棬��ô�͸�ֵΪ�� 
			if (i == j){
				G->edges[i][j] = 0;
			}
			//���������λ�þͽ�������Ϊ����� 
			else {
				G->edges[i][j] = INF;
			}
		}
	}
	//���ߵĸ������ж���ĸ�����ȫ������Ϊ0 
	G->numVertexs = 0;
	G->numEdges = 0;
	printf("�ڽӾ����Ѿ���ʼ��\n");
	//����ʼ�����ͼ���ظ������� 
	return G;
}
void CreateGraph(Graph *G)
{
	//�������ǵ�ͼ������һ���м������㣬������ 
	printf("�����붥������ͱ���:");
	scanf("%d",&G->numVertexs);
	scanf("%d",&G->numEdges);
	int i, j, k, weight; 
	//���ߵ����ݸ�ֵ 
	for (i = 0;i < G->numVertexs; i++){
		printf("������%d����������:", i+1);
		scanf("%d",&G->vers[i]); 
	} 
	//����ÿһ���ߵ����ݼ���Ȩֵ�������Ҫ������Ȩֵ�ģ�����Ҫ��������Ȩֵ��ֻ��Ҫ������ֵΪ1�Ϳ���������� 
	for (k = 0; k < G->numEdges; k++){
		printf("������%d���ߵ������㼫��Ȩֵ����:", k+1);
		scanf("%d%d%d", &i, &j, &weight);
		//����������Ҫ�оٵ�ʹ����ͼ���������ǶԳƵģ����������ͼ�Ļ������ǲ���Ҫ��һ�� 
		G->edges[i-1][j-1] = weight;
		G->edges[j-1][i-1] = weight;
	}
	printf("�ڽӾ����Ѿ���ɴ���\n");
}
void PrintfGraph(Graph *G)
{
	int i, j;
	printf("\t");
	//�ȴ�ӡһ�ж��� 
	for (i = 0; i < G->numVertexs; i++){
		printf("%d\t",G->vers[i]);
	}
	printf("\n");
	for (i = 0; i < G->numVertexs; i++){
		//�ٴ�ӡ���� 
		printf("%d\t",G->vers[i]);
		//������� 
		for (j = 0; j < G->numVertexs; j++){
			//�������������û�бߣ���ô���oo���еĻ����������Ȩֵ 
			if(G->edges[i][j] == INF){
				printf("oo\t");
			}else {
				printf("%d\t",G->edges[i][j]);
			}
		}
		printf("\n");
	}
}

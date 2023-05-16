#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100
typedef struct ArcNode {
	int adjVex;
	struct ArcNode *nextArc;
	int weight;
}ArcNode;
typedef struct Vnode {
	char data;
	ArcNode *first;
}Vnode,AdjList[Max];
typedef struct ALGraph {
	AdjList vertices;
	int vernum;
	int arcnum;
	int kind;
}ALGraph;
void CreatAlGraph(ALGraph *G);//创建图 
int Locatevex(ALGraph G, char u);//搜索 
int PrintALGraph(ALGraph G);//打印 
int main()
{
	ALGraph G;
	CreatAlGraph(&G);
	PrintALGraph(G);
}
void CreatAlGraph(ALGraph *G)
{
	int i, j, k, w,result;
	printf("请输入顶点数和边数\n");
	//getchar();
	scanf("%d %d", &G->vernum, &G->arcnum);
	//G->vertices[i].first = NULL;
	for(i = 0; i < G->vernum; i++) {
		printf("第%d个\n",i+1);
		getchar();
		scanf("%c",&G->vertices[i].data);
		G->vertices[i].first = NULL;
	}
	char va,vb;
	printf("请输入尾和头\n");
	getchar();
	for(k = 0; k < G->arcnum; k++) {
		fflush(stdin);
		scanf("%c %c",&va,&vb);
		i = Locatevex(*G, va);
		j = Locatevex(*G, vb);
		ArcNode *e;
		e = (ArcNode *)malloc(sizeof(ArcNode));
		e->adjVex = j;
		e->nextArc = G->vertices[i].first;
		G->vertices[i].first = e;
	} 
}
int Locatevex(ALGraph G, char u) {
	int i;
	for(i = 0; i < G.vernum; i++){
		if(u == G.vertices[i].data){
			return i;
		}
	}
	return -1;
} 
int PrintALGraph(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("%d个顶点：\n",G.vernum);
	for(i = 0; i < G.vernum; i++){
		printf("%c", G.vertices[i].data);
		//printf("起点%d\n",i);
		//printf("%c->%c",G.vertices[i].data,G.vertices[p->adjVex].data);
		//p = p->nextArc;
	}
	printf("\n%d条弧：\n",G.arcnum);
	for(i = 0; i < G.vernum; i++){
		p = G.vertices[i].first;
		while(p)
		{
			printf("起点%d\n",i);
		printf("%c->%c",G.vertices[i].data,G.vertices[p->adjVex].data);
		p = p->nextArc;
		}
		//printf("%c", G.vertices[i].data);
		printf("\n");
	}
	//printf("\n");
}

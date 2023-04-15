#include<stdio.h>
#include<stdlib.h>
//定义无穷大，为了方便那个地方不存在边 
#define INF 65535 
#define MaxVer 10
typedef struct {
	char vers[10];
	int edges[10][10];
	int numVertexs;
	int numEdges;
}Graph;
Graph* InitGraph();//初始化邻接矩阵 
void CreateGraph(Graph *G);//创建邻接矩阵 
void PrintfGraph(Graph *G);//打印邻接矩阵 
int main()
{
	Graph* G = InitGraph(); 
	CreateGraph(G);
	PrintfGraph(G);
} 
//初始化邻接矩阵 
Graph* InitGraph()
{
	//定义一个图类型的指针 
	Graph *G;
	int i, j;
	//为这个指针开辟空间 
	G = (Graph*)malloc(sizeof(Graph));
	//进行初始化 
	for (i = 0; i < MaxVer; i++) {
		for (j = 0; j < MaxVer; j++){
			//如果这个在矩阵的对角线上面，那么就赋值为零 
			if (i == j){
				G->edges[i][j] = 0;
			}
			//如果在其他位置就将它定义为无穷大 
			else {
				G->edges[i][j] = INF;
			}
		}
	}
	//将边的个数还有顶点的个数，全都定义为0 
	G->numVertexs = 0;
	G->numEdges = 0;
	printf("邻接矩阵已经初始化\n");
	//将初始化后的图返回给主函数 
	return G;
}
void CreateGraph(Graph *G)
{
	//创建我们的图，定义一共有几个顶点，几个边 
	printf("请输入顶点个数和边数:");
	scanf("%d",&G->numVertexs);
	scanf("%d",&G->numEdges);
	int i, j, k, weight; 
	//将边的数据赋值 
	for (i = 0;i < G->numVertexs; i++){
		printf("请输入%d个顶点数据:", i+1);
		scanf("%d",&G->vers[i]); 
	} 
	//定义每一个边的数据极其权值，如果需要定义无权值的，不需要定义他的权值，只需要将他赋值为1就可以用来标记 
	for (k = 0; k < G->numEdges; k++){
		printf("请输入%d条边的两顶点极其权值数据:", k+1);
		scanf("%d%d%d", &i, &j, &weight);
		//我们这里主要列举的使无向图，所以他是对称的，如果是有向图的话，我们不需要下一句 
		G->edges[i-1][j-1] = weight;
		G->edges[j-1][i-1] = weight;
	}
	printf("邻接矩阵已经完成创建\n");
}
void PrintfGraph(Graph *G)
{
	int i, j;
	printf("\t");
	//先打印一行顶点 
	for (i = 0; i < G->numVertexs; i++){
		printf("%d\t",G->vers[i]);
	}
	printf("\n");
	for (i = 0; i < G->numVertexs; i++){
		//再打印顶点 
		printf("%d\t",G->vers[i]);
		//输出数据 
		for (j = 0; j < G->numVertexs; j++){
			//如果这两个顶点没有边，那么输出oo，有的话就输出数据权值 
			if(G->edges[i][j] == INF){
				printf("oo\t");
			}else {
				printf("%d\t",G->edges[i][j]);
			}
		}
		printf("\n");
	}
}

#include<stdio.h>
int book[305][305]={0};
int a[305][305]={0};
int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
void DFS(int x,int y)
{
	for(int i=0;i<4;i++){
		int tx=x +next[i][0];
		int ty=y+next[i][1];
		if(tx<1||tx>n||ty<1||ty>m){
			continue;
		}
		if(a[tx][ty]==1&&book[tx][ty]==0){
			book[tx][ty]=1;
			DFS(tx,ty);
		}
	}
}
int main()
{
	int sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(book[i][j]==0&&a[i][j]!=0){
				sum++;
				book[i][j]=1;
				DFS(i,j);
			}
		}
	}
	printf("%d",sum);
}
//1 1 1 1 0 
//1 1 0 1 0 
//1 1 0 0 0 
//0 0 0 0 0
//1 1 0 0 0 
//1 1 0 0 0
//0 0 1 0 0 
//0 0 0 1 1 

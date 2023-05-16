#include<stdio.h>
typedef struct node{
	int x;
	int y;
}Queue;
int main()
{
	Queue Q[90008]={0};
	int book[305][305]={0};
	int a[305][305]={0};
	int m,n,head,tail,num=0,tx,ty;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			head=1;
			tail=1;
			if(a[i][j]>0&&book[i][j]==0){
				printf("%d %d\n",i,j);
				num++;
			}else{
				book[i][j]=1;
				continue;
			}
			book[i][j]=1;
			Q[tail].x=i;
	        Q[tail].y=j;
	        tail++;
			while(head<tail){
				for(int i=0;i<4;i++){
					tx=Q[head].x+next[i][0];
					ty=Q[head].y+next[i][1];
					if(tx<1||tx>n||ty<1||ty>m){
						continue;
					}
					if(a[tx][ty]>0&&book[tx][ty]==0){
						book[tx][ty]=1;
						Q[tail].x=tx;
						Q[tail].y=ty;
						tail++;
					}
				}
				head++;
			}
		}
	}
	
	printf("%d",num);
} 

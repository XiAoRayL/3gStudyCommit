#include<stdio.h>
int h[101] = {0}, n;
void creat();//创建堆 
void sitdown(int i);//向下调正函数 
void swap(int x, int y);//交换函数 
void heapsort();//堆排序 
int main()
{
	int num, i;
	scanf("%d", &num);
	for(i = 1; i <= num; i++){
		scanf("%d", &h[i]);
	}
	n = num;
	creat(); 
	heapsort();
	printf("\n");
	for(i = 1; i <= num; i++){
		printf("%d\n",h[i]);
	}
} 
void creat()
{
	int i;
	for(i = n/2; i >= 1; i--){
		sitdown(i);
	}
}
void sitdown(int i)
{
	int t, flag = 0;
	while(i*2 <= n && flag == 0){
		if(h[i] > h[i*2]){
			t = i*2;
		}else{
			t = i;
		}
		if(i*2+1 <= n){
			if(h[t] > h[i*2+1]){
				t = i*2+1;
			}
		}
		if(t != i){
			swap(t, i);
			i = t;
		} else {
			flag = 1;
		}
	}
	return;
}
void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return;  
}
void heapsort()
{
	while(n > 1){
		swap(1, n);
		n--;
		sitdown(1);
	}
	return;
}
/*
对第一个java程序进行总结
1. java程序编写-编译-运行的过程
编写：我们将编写的java代码保存在以".java"结尾的源文件中
编译：使用javac.exe命令编译我们的java源文件。格式：javac 源文件名.java
运行：使用java.exe命令解释运行我们的字节码文件。 格式：java 类名

2.
在一个java源文件中可以声明多个class。但是，只能最多有一个类声明为public的。
而且要求声明为public的类的类名必须与源文件名相同。

3. 程序的入口是main()方法。格式是固定的。

4. 输出语句：
System.out.println():先输出数据，然后换行
System.out.print():只输出数据

5.每一行执行语句都以";"结束。

6.编译的过程：编译以后，会生成一个或多个字节码文件。字节码文件的文件名与java源文件中的类名相同。

*/
public class Hello {
	public static void main(String[] args) {//public static void main(String a[]) {//arguments:参数
		System.out.print("Hello World!");
		System.out.println();//换行
		System.out.println("Hello World!");
		}
}

class Person{

}

class Animal{
	
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} Node;

typedef struct deque {
    int size;
    Node* front;
    Node* rear;
} Deque;
//初始化
void initDeque(Deque* deque) {
    deque->size = 0;
    deque->front = NULL;
    deque->rear = NULL;
}
//入队
void pushFront(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;
    if (deque->front != NULL) {
        deque->front->prev = newNode;
    } else {
        deque->rear = newNode;
    }
    deque->front = newNode;
    deque->size++;
}

void pushBack(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = deque->rear;
    newNode->next = NULL;
    if (deque->rear != NULL) {
        deque->rear->next = newNode;
    } else {
        deque->front = newNode;
    }
    deque->rear = newNode;
    deque->size++;
}
//出队 
 int popFront(Deque* deque) {
    if (deque->front == NULL) {
        return -1; // 队列为空
    }
    int data = deque->front->data;
    Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }
    free(temp);
    deque->size--;
    return data;
}

int popBack(Deque* deque) {
    if (deque->rear == NULL) {
        return -1; // 队列为空
    }
    int data = deque->rear->data;
    Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }
    free(temp);
    deque->size--;
    return data;
}

int size(Deque* deque) {
    return deque->size;
}
//判空 
int isEmpty(Deque* deque) {
    return deque->size == 0;
}
//销毁 
void destroyDeque(Deque* deque) {
    while (deque->front != NULL) {
        Node* temp = deque->front;
        deque->front = deque->front->next;
        free(temp);
    }
    deque->rear = NULL;
    deque->size = 0;
}
void pri(Deque* a){
	Node *p;
	p=a->front; 
	while(p){
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n"); 
}
int main(){
	Deque a;
	initDeque(&a);
	int n;
	printf("队内元素个数：");
	scanf("%d",&n);
	while(n--){
		int x,data;
		printf("请输入插入方向（输入0从队尾插入）\n\n"); 
		scanf("%d",&x);
		printf("请输入数据：\n\n");
		scanf("%d",&data);
		if(!x){
			pushFront(&a, data);
		}else{
			pushBack(&a, data);
		}	
	}
	printf("当前队内元素："); 
	pri(&a); 
	popFront(&a);
	printf("队头删除后：");
	pri(&a);
	popBack(&a);
	printf("队尾删除后：");
	pri(&a);
	if(isEmpty(&a)){
		printf("空的\n");
		 
	}else{
		printf("不空\n");
	};
	printf("销毁~~~\n");
	return 0;
} 

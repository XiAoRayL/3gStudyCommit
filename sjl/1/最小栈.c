#define MAX 800
typedef struct {
int* data;
int top ;
} MinStack;

MinStack* minStackCreate() {
MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
obj->data = (int*)malloc(MAX*sizeof(int));
obj->top = -1;
return obj;
}

void minStackPush(MinStack* obj, int val) {
if(obj->top == MAX - 1) return ;
else{
obj->top++;
obj->data[obj->top] = val;
}
}

void minStackPop(MinStack* obj) {
if(obj->top == -1) return;
else obj->top--;
}

int minStackTop(MinStack* obj) {
if(obj->top == -1) return;
return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
if(obj->top == -1) return;
if(obj->top == 0) return obj->data[obj->top];
int min = obj->data[0];
int i;
for(i = 0;i<=obj->top;i++){
if(obj->data[i] < min) min = obj->data[i];
}
return min;
}

void minStackFree(MinStack* obj) {
free(obj->data);
obj->data = NULL;
free(obj);
obj = NULL;
}


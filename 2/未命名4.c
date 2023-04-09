#include<stdio.h>
#include<stdlib.h>
int isNumber(char* token){
    return strlen(token) > 1 || (token[0] >= '0' && token[0] <= '9');
}
int evalRPN(char ** tokens, int tokensSize){
    int n = tokensSize;
    int stack[n],top = 0;
    int i;
    for(i = 0;i < n;i++){
        char *token = tokens[i];
        if(isNumber(token))
            stack[top++] = atoi(token);
        else{
            int num2 = stack[--top];
            int num1 = stack[--top];
            switch(token[0]){
                case '+':stack[top++] = num1 + num2;break;
                case '-':stack[top++] = num1 - num2;break;
                case '*':stack[top++] = num1 * num2;break;
                case '/':stack[top++] = num1 / num2;break;
            }
        }
    }
    return stack[top - 1];
}
int main() {
    char *tokens[] = {"2", "1", "+", "3", "*"};
    int tokensSize = 5;
    int result = evalRPN(tokens, tokensSize);
    printf("Result: %d\n", result);

    return 0;
}

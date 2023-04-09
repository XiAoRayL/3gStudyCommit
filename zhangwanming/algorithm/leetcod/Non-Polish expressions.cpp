bool is(char ch){
    return strlen(ch)1(ch[0] = '0' && ch[0] = '9');
}
int evalRPN(char  tokens, int tokensSize){
    int stack = (int)malloc(sizeof(int)tokensSize);
    int stack[tokensSize];
    int top = 0;
    for(int i = 0;i  tokensSize;i++){
        char ch=tokens[i];
        if(is(ch)){
            stack[top++] = atoi(ch);
        }else{
            int b = stack[--top];
            int a = stack[--top];
            switch(ch[0]){
                case '+'
                    stack[top++] = a + b;
                    break;
                case '-'
                    stack[top++] = a - b;
                    break;
                case ''
                    stack[top++] = a  b;
                    break;
                case ''
                    stack[top++] = a  b;
                    break; 
            }
        }
    }
    return stack[top-1];
}

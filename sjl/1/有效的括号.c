char bijiao(char a){
	if(a == ']') return '[';
	if(a == ')') return '(';
	if(a == '}') return '{';
	return 0;
}
bool isValid(char * s){
	int n = strlen(s);
	if(n%2 == 1 || n == 0) return false;
	char stack[n+1];
    int top = 0,i;
	for(i = 0;i<n;i++){
		char a = bijiao(s[i]);
		if(a){
			if(top == 0 || stack[top-1] != a){
				return false;
			}
			top--;
		}
		else {
			stack[top] = s[i];
			top++;
		}
	}
	return top ==0;
}



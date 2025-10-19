#include<string.h>
#include<stdio.h>
#include<ctype.h>

char str[10];
int top = -1;
char item, stack[10];

void PUSH(char item) {
	top++;
	stack[top] = item;
}

char POP() {
	return stack[top--];
}
	
int ISP(char c) {
	switch(c)
		{
		case '+': return 2; break;
		case '-': return 2; break;
		case '*': return 4; break;
		case '/': return 4; break;
		case '^': return 5; break;
		case '(': return 0; break;																																																																							
		default: return 8;
		}
}

int ICP(char c) {
	switch(c)
		{
		case '+': return 1; break;
		case '-': return 1; break;
		case '*': return 3; break;
		case '/': return 3; break;
		case '^': return 6; break;
		case '(': return 9; break;
		case ')': return 0; break;
		default: return 7;
		}
	}
	
void main() {
	int i; char x;
    
	printf("Enter the expression: ");
	scanf("%s", str);
    
	PUSH('(');
	
	int n =strlen(str);
	str[n]=')';
	str[n+1]='\0';
		
	i=0;
	while(str[i] != '\0') {
		if (isalnum(str[i])) {
			printf("%c", str[i]);
		}
		else if (str[i] == '(' ) {
			PUSH('(');
		}
		else if (str[i] == ')') {
			while((x = POP()) != '(') {
				printf("%c", x);
			}
		}
		else {
			while (ISP(stack[top]) >= ICP(str[i])) {
				x = POP();
				printf("%c", x);
			}
			PUSH(str[i]);
		}		
		i++;
	}
/*  printf("%d",top);	
    while (top>=0) {
	    x = POP();
	    printf("%c", x);
    }
	*/
}
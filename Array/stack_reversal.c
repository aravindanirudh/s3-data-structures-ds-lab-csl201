#include <stdio.h>
char str[100], stack[100], item;
int top = (-1), i;
void push(char temp) {
	top++;
	stack[top] = temp;
}
void pop() {
	item = stack[top];
	top--;
	printf("%c", item);
}
void main() {
	printf("Enter a string: ");
	scanf("%s", str);
	for (i=0; str[i]!='\0'; i++) {
		push(str[i]);
	}
	while(top!=(-1)) {
		pop();
	}
	printf("\n");
}

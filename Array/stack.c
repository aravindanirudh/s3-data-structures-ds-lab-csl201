#include <stdio.h>
#include <stdlib.h>
int stack[100], maxSize, top = (-1), item;
void push() {
	if (top == (maxSize - 1)) {
		printf("Stack overflow!\n");
	}
	else {
		printf("Enter the element to be inserted: ");
		top++;
		scanf("%d", &stack[top]);
	}
}
void pop() {
	if(top == (-1)) {
		printf("Stack underflow!\n");
	}
	else {
		item = stack[top];
		top--;
		printf("The deleted item is: %d\n", item);
	}
}
void traverse() {
	if (top == (-1)) {
		printf("Stack is empty\n");
	}
	else {
		for (int i = top; i >= 0; i--) {
			printf("%d\t", stack[i]);
		}
		printf("\n");
	}
}
void main() {
	int op;
	printf("Enter the size of the stack: ");
	scanf("%d", &maxSize);
	while(1) {
		printf("Welcome to the stack app!\nEnter 1 for PUSH\nEnter 2 for POP\nEnter 3 for TRAVERSAL\nEnter 4 to EXIT\n");
		scanf("%d", &op);
		switch (op) {
			case 1: push(); break;
			case 2: pop(); break;
			case 3: traverse(); break;
			case 4: exit(0);
			default: printf("Invalid operator!\n");
		}
	}
}

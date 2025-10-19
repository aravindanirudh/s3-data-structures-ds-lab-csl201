#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1, queue[100], maxSize, item;
void enqueue() {
	if(rear == maxSize - 1) {
		printf("Queue is full!\n");
	}
	else {
		printf("Enter the item to be inserted: ");
		scanf("%d", &item);
		rear++;
		queue[rear] = item;
		if (front == -1) {
			front = 0;
		}
	}
}
void dequeue() {
	if (front == -1) {
		printf("Queue is empty!\n");
	}
	else {
		item = queue[front];
		printf("The deleted item is: %d\n", item);
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			front++;
		}
	}
}
void traverse() {
	if (front == -1) {
		printf("Queue is empty!\n");
	}
	else {
		for (int i=front; i<=rear; i++) {
			printf("%d\t", queue[i]);
		}
		printf("\n");
	}
}
void main() {
	int op;
	printf("Enter the queue size: ");
	scanf("%d", &maxSize);
	while(1) {
		printf("Welcome to the queue app!\nEnter 1 for ENQUEUE\nEnter 2 for DEQUEUE\nEnter 3 for TRAVERSAL\nEnter 4 to EXIT\n");
		scanf("%d", &op);
		switch (op) {
			case 1: enqueue(); break;
			case 2: dequeue();	break;
			case 3: traverse(); break;
			case 4: exit(0);
			default: printf("Invalid operator!\n");
		}
	}
}

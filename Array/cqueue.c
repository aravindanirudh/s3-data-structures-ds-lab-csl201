#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1, cqueue[100], maxSize, item;
void encqueue() {
	if (front == (rear+1)%maxSize) {
		printf("Queue is full!\n");
	}
	else {
		printf("Enter the item to be inserted: ");
		scanf("%d", &item);
		rear = (rear+1)%maxSize;
		cqueue[rear] = item;
		if (front == -1) {
			front = 0;
		}
	}
}
void decqueue() {
	if (front == -1) {
		printf("Queue is empty!\n");
	}
	else {
		item = cqueue[front];
		printf("The deleted item is: %d\n", item);
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			front = (front+1)%maxSize;
		}
	}
}
void traverse() {
	if (front == -1) {
		printf("Queue is empty!\n");
	}
	else if (front <= rear) {
		for (int i = front; i<=rear; i++) {
			printf("%d\t", cqueue[i]);
		}
	}
	else {
		for (int i = front; i<maxSize; i++) {
			printf("%d\t", cqueue[i]);
		}
		for (int i = 0; i<=rear; i++) {
			printf("%d\t", cqueue[i]);
		}
		printf("\n");
	}
}
void main() {
	int op;
	printf("Enter the circular queue size: ");
	scanf("%d", &maxSize);
	while(1) {
		printf("Welcome to the circular queue app!\nEnter 1 for ENCQUEUE\nEnter 2 for DECQUEUE\nEnter 3 for TRAVERSAL\nEnter 4 to EXIT\n");
		scanf("%d", &op);
		switch (op) {
			case 1: encqueue(); break;
			case 2: decqueue();	break;
			case 3: traverse(); break;
			case 4: exit(0);
			default: printf("Invalid operator!\n");
		}
	}
}

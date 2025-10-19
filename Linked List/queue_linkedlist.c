#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node * link;
}*ptr, *header, *new_node, *front=NULL, *rear=NULL;
void enqueue();
void dequeue();
void traverse();
void main() {
	int choice;
	header = (struct Node *)malloc(sizeof(struct Node));
	header->data = 0;
	header->link = NULL;
	while(1) {
		printf("Welcome to the queue app (with linked list)!\nEnter 1 for ENQUEUE\nEnter 2 for DEQUEUE\nEnter 3 for TRAVERSAL\nEnter 4 to EXIT\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1: enqueue(); break;
			case 2: dequeue(); break;
			case 3: traverse(); break;
			case 4: exit(0);
			default: printf("Invalid input!\n");
		}
	}
}
void enqueue() {	
	new_node = (struct Node *)malloc(sizeof(struct Node));
	if(new_node==NULL) {
		printf("Memory insufficient! Insertion not possible!\n");
	}
	else {
		printf("Enter the item to be inserted: ");
		scanf("%d", &new_node->data);
		new_node->link = NULL;
		if(front == NULL && rear == NULL) {
			header->link = new_node;
			rear = new_node;
			front = new_node;
		}
		else {
			rear->link = new_node;
			rear = new_node;
		}
	}
}
void dequeue() {
	int item;
	if(front == NULL) {
		printf("Queue underflow!\n");
	}
	else {
		ptr = front->link;
		item = front->data;
		printf("The deleted item is: %d\n", item);
		header->link = ptr;
		front = ptr;
	}
}
void traverse() {
	ptr = header->link;
	if(ptr==NULL) {	
		printf("Queue is empty\n");
		return;
	}
	else {
		printf("Queue status: ");
		while(ptr!=NULL) {
			printf("%d ", ptr->data);
			ptr=ptr->link;
		}
		printf("\n");
	}
}

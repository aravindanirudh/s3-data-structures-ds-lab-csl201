#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node * link;
}*ptr, *header, *new_node, *rear=NULL, *front=NULL, *ptr1;
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void display();
void main() {
	int choice;
	header = (struct Node *)malloc(sizeof(struct Node));
	header->data = 0;
	header->link = NULL;
	while(1) {
		printf("1 - Insert at front\n2 - Insert at end\n3 - Delete from front\n4 - Delete from end\n5 - Display\n6 - Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: insert_front(); break;
			case 2: insert_end(); break;
			case 3: delete_front(); break;
			case 4: delete_end(); break;
			case 5: display(); break;
			case 6: exit(0);
			default: printf("Invalid input!\n");
		}
	}
}
void insert_front() {
	new_node = (struct Node *)malloc(sizeof(struct Node));
	if(new_node == NULL) {
		printf("Memory insufficient! Insertion not possible!\n");
		return;
	}
	printf("Enter the item to be inserted: ");
	scanf("%d", &new_node->data);
	new_node->link = NULL;
	if(front == NULL && rear == NULL) {
		header->link = new_node;
		rear = new_node;
		front = new_node;
		}
	else {
		header->link = new_node;
		new_node->link = front;
		front = new_node;
	}
}
void insert_end() {
	new_node = (struct Node *)malloc(sizeof(struct Node));
	if(new_node == NULL) {
		printf("Memory insufficient! Insertion not possible!\n");
		return;
	}
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
void delete_front() {
	int item;
	if(front == NULL) {
		printf("Queue empty!\n");
	}
	else {
		ptr=front->link;
		item=front->data;
		printf("The deleted item is %d\n", item);
		header->link = ptr;
		front=ptr;
	}
}
void delete_end() {
	if(front == NULL) {
		printf("Queue empty!\n");
	}
	else {
		ptr = header;
		while(ptr->link!=NULL) {
			ptr1 = ptr;
			ptr=ptr->link;
		}
		printf("The deleted item is: %d", rear->data);
		ptr1->link = NULL;
		if(front == rear) {
			front = NULL;
			rear = NULL;
		}
		else {
			rear = ptr1;
		}
	}
}
void display() {
	ptr=header->link;
	if(ptr == NULL) {
		printf("Queue is empty!\n");
		return;
	}
	else {
		while(ptr!=NULL) {
			printf("%d ", ptr->data);
			ptr=ptr->link;
		}
		printf("NULL");
		printf("\n");
	}
}

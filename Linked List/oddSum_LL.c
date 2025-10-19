#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node *link;
}*header, *new, *ptr;
void insert() {
	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = 0;
	new->link = NULL;
	printf("Enter the element: ");
	scanf("%d", &new->data);
	if (header->link == NULL) {
		header->link = new;
	}
	else {
		ptr = header;
		while(ptr->link != NULL) {
			ptr=ptr->link;
		}
		ptr->link = new;
	}
}
void oddSum() {
	int sum = 0, temp;
	ptr = header->link;
	while(ptr != NULL) {
		temp = ptr->data;
		if (temp%2 == 0) {
			ptr=ptr->link;
		}
		else {
			sum = sum + temp;
			ptr=ptr->link;
		}
	}
	printf("The sum of odd numbers in the LL is: %d\n", sum);
}
void main() {
	int choice;
	header = (struct Node *)malloc(sizeof(struct Node));
	printf("Welcome to the odd sum calculator app!\n");
	while(1) {
		printf("Enter 1 to insert element\nEnter 2 to calculate odd sum\nEnter 3 to exit\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1: insert(); break;
			case 2: oddSum(); break;
			case 3: exit(0);
			default: printf("Invalid input!\n");
		}
	}
}
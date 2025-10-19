#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
} *header, *newnode, *ptr;

void main() {
    int choice, temp;
    header = (struct Node *)malloc(sizeof(struct Node));
    header->data = 0;
    header->link = NULL;

    while (1) {
        printf("Welcome to the sum/average calculator!\n");
        printf("Enter 1 to add new item\nEnter 2 to calculate\nEnter 3 to exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                newnode = (struct Node *)malloc(sizeof(struct Node));
                printf("Enter the number: ");
                scanf("%d", &temp);
                newnode->data = temp;
                newnode->link = NULL;

                // Find the end of the list
                ptr = header;
                while (ptr->link != NULL) {
                    ptr = ptr->link;
                }
                // Attach the new node
                ptr->link = newnode;
                break;

            case 2:
                int sum = 0, count = 0;
                ptr = header->link; // Start from the first actual node
                while (ptr != NULL) {
                  sum = sum + ptr->data; // Add the data of the current node
                  ptr = ptr->link; // Move to the next node
                  count++; //Increment count by 1 - it is the number of elements in the linked list
                }
                printf("Sum is: %d\n", sum);
                float avg = ((float)sum/count);
                printf("Average is: %0.2f\n", avg);
                break;
                
            case 3: exit(0);

            default:
                printf("Invalid choice! Please enter 1 or 2!\n");
                break;
        }
    }
}

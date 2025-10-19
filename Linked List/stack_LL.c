#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
} *header, *newnode, *ptr;

void push() {
    int item;
    printf("Enter the element to be inserted: ");
    scanf("%d", &item);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = item; // Set the data first
    newnode->link = NULL; // Initialize the link to NULL

    // If the list is empty (header->link is NULL)
    if (header->link == NULL) {
        header->link = newnode; // Insert the new node
    } else {
        // Traverse to the end of the list
        ptr = header->link;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = newnode; // Insert the new node at the end
    }
}

void pop() {
    if (header->link == NULL) {
        printf("The list is empty, nothing to pop.\n");
        return;
    }

    // If there is only one node in the list
    if (header->link->link == NULL) {
        free(header->link); // Free the only node
        header->link = NULL; // Set header's link to NULL
    } else {
        // Traverse to the second last node
        ptr = header->link;
        while (ptr->link->link != NULL) {
            ptr = ptr->link;
        }
        free(ptr->link); // Free the last node
        ptr->link = NULL; // Set the second last node's link to NULL
    }
}

void traverse() {
    ptr = header->link; // Start from the first actual node
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void main() {
    int choice;
    header = (struct Node *)malloc(sizeof(struct Node));
    header->data = 0; // Placeholder data
    header->link = NULL; // Initialize header's link to NULL
    while (1) {
        printf("Enter 1 to PUSH\nEnter 2 to POP\nEnter 3 to TRAVERSE\nEnter 4 to EXIT\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: traverse(); break;
            case 4: exit(0);
            default: printf("Invalid input!\n");
        }
    }
}

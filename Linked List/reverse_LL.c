#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *link;
} *Header, *revHeader, *ptr, *new;

void main() {
    int n, i, item;

    // Initialize the header for the original linked list
    Header = (struct Node *)malloc(sizeof(struct Node));
    Header->data = 0;
    Header->link = NULL;

    // Input the elements for the original linked list
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    ptr = Header;
    for (i = 0; i < n; i++) {
        scanf("%d", &item);

        new = (struct Node *)malloc(sizeof(struct Node));
        ptr->link = new;
        new->data = item;
        new->link = NULL;
        ptr = ptr->link;
    }

    // Initialize the header for the reversed linked list
    revHeader = (struct Node *)malloc(sizeof(struct Node));
    revHeader->data = 0;
    revHeader->link = NULL;

    // Traverse the original list and insert each element at the beginning of the reversed list
    ptr = Header->link;
    while (ptr != NULL) {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->data = ptr->data;
        new->link = revHeader->link; // Insert new node at the beginning of revHeader
        revHeader->link = new;

        ptr = ptr->link; // Move to the next node in the original list
    }

    // Display the reversed linked list
    printf("Reversed linked list: ");
    ptr = revHeader->link;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

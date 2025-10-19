#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
}*header1, *header2, *new, *ptr, *ptr1;

void main() {
    int i, n, m, item;
    // Input linked list 1
    // Make a header and set it's data to 0 and link to NULL
    header1 = (struct Node *)malloc(sizeof(struct Node));
    header1->data = 0;
    header1->link = NULL;
    
    // Get the delimiter of the loop
    printf("Enter the no. of elements of first LL: ");
    scanf("%d", &n);
    
    // Input elements
    printf("Enter the elements of first LL: ");
    ptr = header1;
    for(i=0; i<n ; i++) {
        scanf("%d", &item);
        new = (struct Node *)malloc(sizeof(struct Node));
        ptr->link = new; // Link new node to previous node
        new->data = item; // Set data as item in new node
        new->link = NULL; // Set link of new node as NULL
        ptr = ptr->link; // Increment ptr to next node
    }

    // Input linked list 2
    // Make a header and set it's data to 0 and link to NULL
    header2 = (struct Node *)malloc(sizeof(struct Node));
    header2->data = 0;
    header2->link = NULL;
    
    // Get the delimiter of the loop
    printf("Enter the no. of elements of second LL: ");
    scanf("%d", &m);
    
    // Input elements
    printf("Enter the elements of second LL: ");
    ptr1 = header2;
    for(i=0; i<m ; i++) {
        scanf("%d", &item);
        new = (struct Node *)malloc(sizeof(struct Node));
        ptr1->link = new; // Link new node to previous node
        new->data = item; // Set data as item in new node
        new->link = NULL; // Set link of new node as NULL
        ptr1 = ptr1->link; // Increment ptr to next node
    }

    // Merge two linked lists
    ptr1 = header2->link;
    ptr->link = ptr1;
    free(header2);

    // Display the merged linked list
    printf("Merged linked list: ");
    ptr = header1->link;  
    // Start from the first element after the header
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    // Delete duplicates in the merged linked list
    ptr = header1->link;
    while (ptr != NULL) {
        ptr1 = ptr;
        while (ptr1->link != NULL) {
            if (ptr1->link->data == ptr->data) {
                // Duplicate found; remove it
                new = ptr1->link;
                ptr1->link = ptr1->link->link;
                free(new);
            } else {
                ptr1 = ptr1->link;
            }
        }
        ptr = ptr->link;
    }

    printf("Merged linked list after removing duplicates: ");
    ptr = header1->link;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
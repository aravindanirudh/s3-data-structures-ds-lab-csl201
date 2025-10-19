#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
}*header, *new, *ptr;

void main() {
    int i, n, item, key, flag = 0, count = 0;
    // Make a header and set it's data to 0 and link to NULL
    header = (struct Node *)malloc(sizeof(struct Node));
    header->data = 0;
    header->link = NULL;
    
    // Get the delimiter of the loop
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    
    // Input elements
    printf("Enter the elements: ");
    ptr = header;
    for(i=0; i<n ; i++) {
        scanf("%d", &item);
        new = (struct Node *)malloc(sizeof(struct Node));
        ptr->link = new; // Link new node to previous node
        new->data = item; // Set data as item in new node
        new->link = NULL; // Set link of new node as NULL
        ptr = ptr->link; // Increment ptr to next node
    }
    
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    // Actual linear search
    ptr = header;
    while(ptr!=NULL) {
        if (ptr->data == key) {
            flag = 1;
            break;
        }
        count++; 
        // Count includes header but in the 'ptr->data == key' iteration, count is not 
        // incremented. So, displaying 'count' directly is correct
        ptr=ptr->link;
    }

    if(flag == 1) {
        printf("The element was found at position %d\n", count);
    }
    else {
        printf("The element was not found!\n");
    }
}
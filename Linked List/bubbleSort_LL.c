#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * link;
}*Header, *ptr, *ptr1, *new;

int main()
{
    int n, i, j, item, temp;
    
    Header = (struct Node *)malloc(sizeof(struct Node));
    Header->data = 0;
    Header->link = NULL;
    
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements:\n");
    ptr = Header;
    for(i=0; i<n ; i++)
    {
        scanf("%d", &item);
        
        new = (struct Node *)malloc(sizeof(struct Node));
        ptr->link = new;
        new->data = item;
        new->link = NULL;
        ptr = ptr->link;
    }
    
    ptr = Header->link;
    for(i=0; i<n; i++)
    {
        ptr = Header->link;
        for(j=0; j<(n-i-1); j++)
        {
            ptr1 = ptr->link;
            if (ptr->data > ptr1->data)
            {
                temp = ptr->data;
                ptr->data = ptr1->data;
                ptr1->data = temp;
            }
            ptr = ptr->link;
        }
    }
    
    printf("Sorted List: [ ");
    ptr = Header->link;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("]\n");
    
    return(0);
}
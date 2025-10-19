#include<stdio.h>
#include<stdlib.h>
struct node {
    int coeff;
    int exp;
    struct node * link;
} *pheader, *qheader, *rheader, *pptr, *qptr, *rptr, *newnode, *ptr;
void addpoly();
void main() {
    int n, m, i = 1, j = 1;

    pheader = (struct node *)malloc(sizeof(struct node));
    pheader->coeff = 0;
    pheader->exp = 0;
    pptr = pheader;
    
    qheader = (struct node *)malloc(sizeof(struct node));
    qheader->coeff = 0;
    qheader->exp = 0;
    qptr = qheader;

    printf("Enter the no. of terms of first polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents: ");
    while (i <= n) {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d %d", &newnode->coeff, &newnode->exp);
        newnode->link = NULL;
        pptr->link = newnode;
        pptr = newnode;
        i++;
    }

    printf("Enter the no. of terms of second polynomial: ");
    scanf("%d", &m);
    printf("Enter the coefficients and exponents: ");
    while (j <= m) {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d %d", &newnode->coeff, &newnode->exp);
        newnode->link = NULL;
        qptr->link = newnode;
        qptr = newnode;
        j++;
    }

    addpoly();

    ptr = rheader->link;
    printf("Resultant polynomial is: ");
    while (ptr != NULL) {
        printf("%dx^%d", ptr->coeff, ptr->exp);
        if (ptr->link != NULL) {
            printf(" + ");
        }
        ptr = ptr->link;
    }
    printf("\n");
}
void addpoly() {
    pptr = pheader->link;
    qptr = qheader->link;

    rheader = (struct node *)malloc(sizeof(struct node));
    rheader->coeff = 0;
    rheader->exp = 0;
    rheader->link = NULL;
    rptr = rheader;

    while (pptr != NULL && qptr != NULL) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->link = NULL;
        rptr->link = newnode;
        rptr = newnode;
        if (pptr->exp == qptr->exp) {
            rptr->coeff = pptr->coeff + qptr->coeff;
            rptr->exp = pptr->exp;
            pptr=pptr->link;
            qptr=qptr->link;
        } else if (pptr->exp > qptr->exp) {
            rptr->coeff = pptr->coeff;
            rptr->exp = pptr->exp;
            pptr = pptr->link;
        } else {
            rptr->coeff = qptr->coeff;
            rptr->exp = qptr->exp;
            qptr = qptr->link;
        }
    }

    while (pptr != NULL) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->link = NULL;
        rptr->link = newnode;
        rptr = newnode;
        rptr->coeff = pptr->coeff;
        rptr->exp = pptr->exp;
        pptr=pptr->link;
    }

    while (qptr != NULL) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->link = NULL;
        rptr->link = newnode;
        rptr = newnode;
        rptr->coeff = qptr->coeff;
        rptr->exp = qptr->exp;
        qptr = qptr->link;
    }
}

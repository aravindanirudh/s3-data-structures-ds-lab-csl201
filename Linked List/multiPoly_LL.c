#include<stdio.h>
#include<stdlib.h>
struct node {
    int coeff;
    int exp;
    struct node * link;
} *pheader, *qheader, *rheader, *pptr, *qptr, *rptr, *newnode, *ptr, *rptr1;
void multiPoly();
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

    multiPoly();

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
void multiPoly() {
    int c, e;
    pptr = pheader;
    qptr = qheader;
    rheader = (struct node *)malloc(sizeof(struct node));
    rheader->link = NULL;
    rheader->coeff = 0;
    rheader->exp = 0;
    if (pptr->link == NULL || qptr->link == NULL) {
        printf("Multiplication not possible!\n");
    }
    else {
        pptr = pptr->link;
        while(pptr!=NULL) {
            qptr=qheader->link;
            while(qptr!=NULL) {
                c = pptr->coeff * qptr->coeff;
                e = pptr->exp + qptr->exp;
                rptr=rheader->link;
                if(rptr == NULL) {
                    newnode = (struct node *)malloc(sizeof(struct node));
                    newnode->exp = e;
                    newnode->coeff = c;
                    newnode->link = NULL;
                    rheader->link = newnode;
                }
                else {
                    while(rptr->link != NULL && rptr->exp > e) {
                        rptr1 = rptr;
                        rptr = rptr->link;
                    }
                    if(rptr->exp == e) {
                        rptr->coeff = rptr->coeff + c;
                    }
                    else if (rptr->exp < e) {
                        newnode = (struct node *)malloc(sizeof(struct node));
                        newnode->exp = e;
                        newnode->coeff = c;
                        rptr1->link = newnode;
                        newnode->link = rptr;
                    }
                    else {
                        newnode = (struct node *)malloc(sizeof(struct node));
                        newnode->exp = e;
                        newnode->coeff = c;
                        rptr->link = newnode;
                        newnode->link = NULL;
                    }
                }
                qptr = qptr->link;
            }
            pptr = pptr->link;
        }
    }
}

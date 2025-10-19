#include<stdio.h>
void swap(int *p, int *q) {
    int temp;
    temp = *q;
    *q = *p;
    *p = temp;
}
int partition(int a[], int low, int high) {
    int pivotindex, bigindex, smallindex;
    pivotindex = low;
    bigindex = low;
    smallindex = high;
    while (smallindex > bigindex) {
        while (a[bigindex]<=a[pivotindex] && bigindex<high) {
            bigindex++;
        }
        while (a[smallindex] > a[pivotindex]) {
            smallindex--;
        }
        if (bigindex < smallindex) {
            swap(&a[smallindex], &a[bigindex]);
        }
    }
    swap(&a[smallindex], &a[pivotindex]);
    return smallindex;
}
void quicksort(int a[], int low, int high) {
    if (low < high) {
        int q = partition(a, low, high);
        quicksort(a, low, q-1);
        quicksort(a, q+1, high);
    }
}
void main() {
    int a[10], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n-1);
    printf("The sorted elements are: ");
    for (i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

#include <stdio.h>
void mergeSort(int a[], int first, int last);
void merge(int a[], int first, int mid, int last);
void main() {
    int a[100], n, i;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n-1);
    printf("The sorted elements are: ");
    for (i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}
void mergeSort(int a[], int first, int last) {
    if (first<last) {
        int mid = (first+last)/2;
        mergeSort(a, first, mid);
        mergeSort(a, mid+1, last);
        merge(a, first, mid, last);
    }
}
void merge(int a[], int first, int mid, int last) {
    int l1, l2, u1, u2, index, tempArray[100];
    l1 = first;
    u1 = mid;
    l2 = mid + 1;
    u2 = last;
    index = first;
    for (; (l1<=u1)&&(l2<=u2); index++) {
        if(a[l1] < a[l2]) {
            tempArray[index] = a[l1];
            l1++;
        }
        else {
            tempArray[index] = a[l2];
            l2++;
        }
    }
    for (; l1<=u1; l1++, index++) {
	tempArray[index] = a[l1];
    }
    for (; l2<=u2; l2++, index++) {
	    tempArray[index] = a[l2];
    }
    for (index = first; index<=last; index++) {
	    a[index] = tempArray[index];
    }
}
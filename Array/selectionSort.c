#include <stdio.h>
int a[100], n;
void swap(int *p, int *q) {
	int temp;
	temp = *q;
	*q = *p;
	*p = temp;
}
void selectionSort() {
	int small, i, j;
	for (i=0; i<n-1; i++) {
		small = i;
		for (j=i+1; j<n; j++) {
			if(a[j] < a[small]) {
				small = j;
			}
		}
		swap(&a[small], &a[i]);
	}
	printf("The sorted array is: ");
	for (i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void main() {
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	printf("Enter the array elements: ");
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	selectionSort(a, n);
}

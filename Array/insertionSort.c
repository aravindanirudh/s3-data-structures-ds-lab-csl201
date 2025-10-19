#include <stdio.h>
void insertionSort(int a[100], int n) {
	int temp, i, j;
	for(i=1; i<n; i++) {
		temp = a[i];
		for(j=i; j>0 && a[j-1]>temp; j--) {
			a[j] = a[j-1];
		}
		a[j] = temp;
	}
	printf("The sorted array is: ");
	for(i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void main() {
	int a[100], n, i;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	printf("Enter the array elements: ");
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	insertionSort(a, n);
}

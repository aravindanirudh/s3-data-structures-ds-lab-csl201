#include <stdio.h>
void bubbleSort(int, int[]);
void main() {
	int n, i, ar[100];
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	printf("Enter the array elements: ");
	for (i=0; i<n; i++) {
		scanf("%d", &ar[i]);	
	}
	bubbleSort(n, ar);
}
void bubbleSort(int n, int ar[100]) {
	int temp;
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-i-1; j++) {
			if (ar[j] > ar[j+1]) {
				temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
			}
		}
	}
	printf("The sorted array is: ");
	for(int i=0; i<n; i++) { 
		printf("%d ", ar[i]);
	}
	printf("\n");
}

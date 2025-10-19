#include <stdio.h>
void linearSearch(int, int[], int);
void main() {
	int ar[100], key, n, i;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	printf("Enter the array elements: ");
	for (i=0; i<n; i++) {
		scanf("%d", &ar[i]);	
	}
	printf("Enter the element to be searched: ");
	scanf("%d", &key);
	linearSearch(n, ar, key);
}
void linearSearch(int n, int ar[100], int key) {	
	int flag = 0;
	for (int i=0; i<n; i++) {
		if (ar[i] == key) {
			printf("The element has been found at position %d\n", i+1);
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		printf("The element has not been found\n");
	}
}

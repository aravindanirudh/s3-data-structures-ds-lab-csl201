#include <stdio.h>
void binarySearch(int a[100], int item, int n) {
	int low = 0, high = (n-1), mid, flag = 0;
	while (low <= high) {
		mid = (low + high)/2;
		if (a[mid] == item) {
			printf("Element has been found at position: %d\n", mid + 1);
			flag = 1; break;
		}
		else if (item < a[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	if (flag == 0) {
		printf("Element has not been found\n");
	}
}
void main() {
	int a[100], i, n, item;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	printf("Enter the elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d", &item);
	binarySearch(a, item, n);
}

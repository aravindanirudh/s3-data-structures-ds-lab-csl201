#include <stdio.h>
void addPoly(int a[10][2], int b[10][2], int m, int n) {
	int i=0, j=0, k=0, c[10][2];
	while (i<m && j<n) {
		if (a[i][1]==b[j][1]) {
			c[k][0]=a[i][0] + b[j][0];
			c[k][1]=a[i][1];
			i++; j++; k++;
		}
		else if (a[i][1]>b[j][1]) {
			c[k][0] = a[i][0];
			c[k][1] = a[i][1];
			i++; k++;
		}
		else {
			c[k][0] = b[j][0];
			c[k][1] = b[j][1];
			j++; k++;
		}
	}
	if (i<m) {
		for ( ; i<m; i++) {
			c[k][0] = a[i][0];
			c[k][1] = a[i][1];
			k++;
		}
	}
	if (j<n) {
		for ( ; j<n; j++) {
			c[k][0] = b[j][0];
			c[k][1] = b[j][1];
			k++;
		}
	}
	printf("The polynomial formed by addition is: \n");
	for (i=0; i<k; i++) {
		printf("%dx^%d", c[i][0], c[i][1]);
		if (i<(k-1)) {	
			printf(" + ");
		}
	}
}
void main() {
	int a[10][2], b[10][2], m, n, i;
	printf("Enter the no. of terms in the first polynomial: ");
	scanf("%d", &m);
	for (i=0; i<m; i++) {
		printf("Enter the coefficient and exponent of term %d: ", i+1);
		scanf("%d %d", &a[i][0], &a[i][1]);
	}
	printf("Enter the no. of terms in the second polynomial: ");
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		printf("Enter the coefficient and exponent of term %d: ", i+1);
		scanf("%d %d", &b[i][0], &b[i][1]);
	}
	addPoly(a, b, m, n);
}

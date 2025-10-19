#include <stdio.h>
void multiPoly(int a[10][2], int b[10][2], int m, int n) {
	int  c[100][2], k=0, exist=0, i, j, t, newco, newex;
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
			newco = a[i][0] * b[j][0];
			newex = a[i][1] + b[j][1];
			for (t=0; t<k; t++) {
				exist=0;
				if(c[t][1]==newex) {
					exist = 1;
					break;
				}
			}
			if(exist) {
				c[t][0] = c[t][0] + newco;
			}
			else {
				c[k][0] = newco;
				c[k][1] = newex;
				k++;
			}
		}
	}
	//Bubble Sort
	int temp;
	for(i=0; i<k; i++) {
		for(j=0; j<k-i-1; j++) {
			if (c[j][1] < c[j+1][1]) {
				temp = c[j][1];
				c[j][1] = c[j+1][1];
				c[j+1][1] = temp;
				temp = c[j][0];
				c[j][0] = c[j+1][0];
				c[j+1][0] = temp;
			}
		}
	}
	//Bubble Sort End
	printf("The product of the polynomials is: \n");
	for (i=0; i<k; i++) {
		printf("%dx^%d", c[i][0], c[i][1]);
		if (i < (k-1)) {
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
	multiPoly(a, b, m, n);
}

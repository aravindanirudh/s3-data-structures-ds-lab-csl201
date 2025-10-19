#include<stdio.h>
void sparseConverter(int a[10][10], int as[50][3], int m, int n) {
    int i, j, k = 0;
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            if(a[i][j]!=0) {
                k++; 
                as[k][0] = i;
                as[k][1] = j;
                as[k][2] = a[i][j];
            }
        }
    }
    as[0][0] = m;
    as[0][1] = n;
    as[0][2] = k;
    printf("One of the sparse matrices is: \n");
    for(i=0; i<=k; i++) {
       for(j=0; j<3; j++) { 
           printf("%d ", as[i][j]);
       }
       printf("\n");
    }
}
void addSparse(int a[50][3], int b[50][3]) {  
    int c[50][3], i=1, j=1, k=1, m, n, p, q, na, nb;
	m=a[0][0];
	n=a[0][1];
	p=b[0][0];
	q=b[0][1];
	na=a[0][2];
	nb=b[0][2];
	if(m!=p || n!=q) {
		printf("Addition not possible!\n");
	}
	else {
		while(i<=na && j<=nb) {
			if(a[i][0]<b[j][0]) {
				c[k][0]=a[i][0];
				c[k][1]=a[i][1];
				c[k][2]=a[i][2];
				i++; k++;
			}
			else if(a[i][0]>b[j][0]) {
				c[k][0]=b[j][0];
				c[k][1]=b[j][1];
				c[k][2]=b[j][2];
				j++; k++;
			}
			else{
				if(a[i][1]<b[j][1]) {
					c[k][0]=a[i][0];
					c[k][1]=a[i][1];
					c[k][2]=a[i][2];
					i++; k++;
				}
				else if(a[i][1]>b[j][1]) {
				    c[k][0]=b[j][0];
					c[k][1]=b[j][1];
					c[k][2]=b[j][2];
					j++; k++;
				}
				else{
					c[k][0]=a[i][0];
					c[k][1]=a[i][1];
					c[k][2]=a[i][2]+b[j][2];
					i++; j++; k++;
				}
			}
		}
		
		while(i<=na) {
			c[k][0]=a[i][0];
			c[k][1]=a[i][1];
			c[k][2]=a[i][2];
			k++; i++;
		}
		while(j<=nb) {
			c[k][0]=b[j][0];
			c[k][1]=b[j][1];
			c[k][2]=b[j][2];
			k++; j++;
		}
		c[0][0]=m;
		c[0][1]=n;
		c[0][2]=k-1;
		printf("The sum is: \n");
		for(i=0;i<k;i++) {
			printf("%d %d %d",c[i][0],c[i][1],c[i][2]);
			printf("\n");
		}
	}
}
void main()
{
    int a[10][10], b[10][10], as[50][3], bs[50][3], m, n, p, q, i, j, k = 0;
    printf("Enter the dimensions of first matrix: ");
    scanf("%d %d", &m, &n);
    printf("Enter the matrix elements: ");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    sparseConverter(a, as, m, n);
    printf("Enter the dimensions of second matrix: ");
    scanf("%d %d", &p, &q);
    printf("Enter the matrix elements: ");
    for(i=0; i<p; i++) {
        for(j=0; j<q; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    sparseConverter(b, bs, p, q);
    addSparse(as, bs);
}

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
void multiSparse(int a[50][3], int b[50][3]) {
    int c[50][3], t, i, j, exist, m, n, k = 0;
    if(a[0][1]!=b[0][0]) {
        printf("Multiplication not possible!\n");
    }
    else {
        c[0][0] = a[0][0];
        c[0][1] = b[0][1];
        m = a[0][2]; n = b[0][2];
        for(i=1; i<=m; i++) {
            for(j=1; j<=n; j++) {
                if(a[i][1]==b[j][0]) {
                    exist = 0;
                    for(t=1; t<=k; t++) {
                        if(c[t][0]==a[i][0] && c[t][1]==b[j][1]) {
                            exist = 1;
                            c[t][2] += a[i][2] * b[j][2];
                            break;
                        }
                    }
                    if(exist==0) {
                        k++;
                        c[k][0] = a[i][0];
                        c[k][1] = b[j][1];
                        c[k][2] = a[i][2] * b[j][2];
                    }
                }
            }
        }
        c[0][2] = k;
        printf("The product is: \n");
        for(i=0;i<=k;i++) {
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
    multiSparse(as, bs);
}

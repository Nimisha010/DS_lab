#include<stdio.h>

void Sparse(int A[10][10], int m, int n, int S[20][3]);
void Transpose(int S[20][3], int T[20][3]);
void AddSparse(int S[20][3], int T[20][3]);

void PrintSparse(int matrix[20][3]) {
    int i, j;

    for (i = 0; i <= matrix[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[10][10], B[10][10], m1, n1, m2, n2, S[20][3], T[20][3],C[20][3],D[20][3];

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &m1, &n1);

    printf("Enter the matrix:\n");
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            scanf("%d", &A[i][j]);

    printf("Matrix 1:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    Sparse(A, m1, n1, C);
    Transpose(C,S);
    printf("Enter the number of rows and columns of the Second matrix: ");
    scanf("%d %d", &m2, &n2);

    printf("Enter the matrix:\n");
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            scanf("%d", &B[i][j]);

    printf("Matrix 2:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    Sparse(B, m2, n2, D);
    Transpose (D,T);
    AddSparse(C, D);

    return 0;
}

void Sparse(int A[10][10], int m, int n, int S[20][3]) {
    int i, j, k = 1;

    S[0][0] = m;
    S[0][1] = n;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                S[k][0] = i;
                S[k][1] = j;
                S[k][2] = A[i][j];
                k++;
            }
        }
    }

    S[0][2] = k - 1;

    printf("\nTuple Form:\n");
    PrintSparse(S);
}

void Transpose(int S[20][3], int T[20][3]) {
    int m, n, k, i, j;

    T[0][0] = S[0][1];
    T[0][1] = S[0][0];
    T[0][2] = S[0][2];

    k = 1;
    n = S[0][2];
    m = S[0][1];

    for (i = 0; i < m; i++) {
        for (j = 1; j <= n; j++) {
            if (S[j][1] == i) {
                T[k][0] = S[j][1];
                T[k][1] = S[j][0];
                T[k][2] = S[j][2];
                k = k + 1;
            }
        }
    }

    printf("\nTranspose:\n");
    PrintSparse(T);
}

void AddSparse(int S[20][3], int T[20][3]) {
    int r1, c1, r2, c2, m, n, i, j, k,nz,A[20][3];

    r1 = S[0][0];
    c1 = S[0][1];
    r2 = T[0][0];
    c2 = T[0][1];

    if (r1 != r2 || c1 != c2)
        printf("\nIncompatible Matrix size\n");
    else {
        A[0][0] = S[0][0];
        A[0][1] = S[0][1];

        m = 1;
        n = 1;
        k = 1;
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                if (S[m][0] == i && S[m][1] == j && T[n][0] == i && T[n][1] == j) {
                    A[k][0] = S[m][0];
                    A[k][1] = S[m][1];
                    A[k][2] = S[m][2] + T[n][2];
                    m++;
                    n++;
                    k++;
                  } else if (T[n][0] == i && T[n][1] == j) {
                    A[k][0] = T[n][0];
                    A[k][1] = T[n][1];
                    A[k][2] = T[n][2];
                    n++;
                    k++;
                } else if (S[m][0] == i && S[m][1] == j) {
                    A[k][0] = S[m][0];
                    A[k][1] = S[m][1];
                    A[k][2] = S[m][2];
                    m++;
                    k++;
                }
            }
        }
        
        A[0][2] = k - 1;

        printf("\nSUM:\n");
        PrintSparse(A);
    }
}

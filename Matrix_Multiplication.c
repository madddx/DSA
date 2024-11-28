#include <stdio.h>

int main() {
    int a[10][10], b[10][10], mul[10][10], r1, c1, r2, c2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if matrices can be multiplied
    if (c1 != r2) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    printf("Enter the values of the first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the values of the second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Initialize the result matrix to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            mul[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("The resultant matrix is:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", mul[i][j]);
        }
        printf("\n");
    }

    return 0;
}

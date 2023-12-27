#include <stdio.h>
#include<stdlib.h>


int searchMatrix(int **matrix, int matrixSize, int matrixColSize, int target) {
    int row = 0, col = matrixColSize - 1;

    while (row < matrixSize && col >= 0) {
        if (matrix[row][col] == target) {
            return 1;  
        } else if (matrix[row][col] < target) {
            row++;  
        } else {
            col--;  
        }
    }

    return 0;  
}

int main() {
    int m, n;
    scanf("%d,%d", &m, &n);

    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d,", &matrix[i][j]);
        }
    }

    int target;
    scanf("%d", &target);

    int result = searchMatrix(matrix, m, n, target);
    printf("%s", result ? "true" : "false");

    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

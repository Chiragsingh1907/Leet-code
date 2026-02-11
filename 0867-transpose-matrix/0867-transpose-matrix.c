#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    // matrixSize is m (rows), matrixColSize[0] is n (cols)
    int m = matrixSize;
    int n = matrixColSize[0];

    // The transposed matrix will have n rows and m columns
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    int** result = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
        result[i] = (int*)malloc(m * sizeof(int));
    }

    // Fill the transposed matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}
#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < matrixColSize[i]; j++) {
            // Compare current element with top-left neighbor
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
}
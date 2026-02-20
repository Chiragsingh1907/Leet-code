#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 1. Sort the array to use two-pointer logic and skip duplicates
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 1000; // Initial guess for result storage
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        // Optimization: If the current number is > 0, no sum can be 0
        if (nums[i] > 0) break;

        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                // Resize if we hit capacity
                if (*returnSize == capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                }

                // Add triplet to results
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnSize)++;

                // Skip duplicate values for left and right
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    // Assign the column sizes (each triplet always has 3 elements)
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}
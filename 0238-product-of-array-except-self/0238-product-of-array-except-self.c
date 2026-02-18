#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    // Step 1: Calculate prefix products
    // res[i] will contain the product of all elements to the left of i
    res[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }

    // Step 2: Calculate suffix products on the fly
    // 'right' stores the product of all elements to the right of i
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        // Multiply the current prefix product by the current suffix product
        res[i] = res[i] * right;
        
        // Update the suffix product for the next element to the left
        right *= nums[i];
    }

    return res;
}
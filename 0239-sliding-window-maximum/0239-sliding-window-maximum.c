#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int)); // Stores indices
    int head = 0, tail = 0;
    int resIdx = 0;

    for (int i = 0; i < numsSize; i++) {
        // 1. Remove indices that are out of the current window bound
        if (head < tail && deque[head] <= i - k) {
            head++;
        }

        // 2. Remove elements from the back that are smaller than the current element
        // They will never be the maximum again
        while (head < tail && nums[deque[tail - 1]] <= nums[i]) {
            tail--;
        }

        // 3. Add current element's index to the back
        deque[tail++] = i;

        // 4. The front of the deque is the largest element for the window
        // Only start adding to result once we've reached at least k elements
        if (i >= k - 1) {
            result[resIdx++] = nums[deque[head]];
        }
    }

    free(deque);
    *returnSize = resIdx;
    return result;
}
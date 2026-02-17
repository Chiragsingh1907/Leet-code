#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int max_so_far = nums[0];
    int current_max = nums[0];

    for (int i = 1; i < numsSize; i++) {
        // Decide: Join the previous subarray or start fresh?
        current_max = (nums[i] > current_max + nums[i]) ? nums[i] : current_max + nums[i];
        
        // Update the global maximum if the current one is better
        if (current_max > max_so_far) {
            max_so_far = current_max;
        }
    }
    return max_so_far;
}
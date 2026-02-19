#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int maxSoFar = 0, minSoFar = 0;
    int maxTotal = nums[0], minTotal = nums[0];

    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];

        // Max Subarray Logic
        maxSoFar = MAX(nums[i], maxSoFar + nums[i]);
        maxTotal = MAX(maxTotal, maxSoFar);

        // Min Subarray Logic
        minSoFar = MIN(nums[i], minSoFar + nums[i]);
        minTotal = MIN(minTotal, minSoFar);
    }

    // If all numbers are negative, the max subarray is just the largest single element
    if (maxTotal < 0) {
        return maxTotal;
    }

    // Return the better of standard Kadane vs Circular (Total - Min)
    return MAX(maxTotal, totalSum - minTotal);
}
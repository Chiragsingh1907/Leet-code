int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the middle element is less than the next element,
        // we are in an ascending slope. The peak is to the right.
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } 
        // Otherwise, we are in a descending slope or at a peak.
        // The peak is either mid or to the left.
        else {
            right = mid;
        }
    }

    // When left == right, we have converged on a peak index.
    return left;
}
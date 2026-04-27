int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    // Binary search loop
    while (left < right) {
        int mid = left + (right - left) / 2;

        // If mid element is greater than the rightmost element, 
        // the minimum must be in the right half.
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } 
        // Otherwise, the minimum is in the left half (including mid).
        else {
            right = mid;
        }
    }

    // After the loop, left == right, pointing to the minimum element.
    return nums[left];
}
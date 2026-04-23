int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found at this index
        } else if (nums[mid] < target) {
            left = mid + 1; // Target must be to the right
        } else {
            right = mid - 1; // Target must be to the left
        }
    }

    // If the loop finishes without finding the target, 
    // 'left' is the index where it should be inserted.
    return left;
}
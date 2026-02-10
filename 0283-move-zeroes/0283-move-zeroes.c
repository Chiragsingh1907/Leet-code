void moveZeroes(int* nums, int numsSize) {
    // Pointer to track where the next non-zero element should go
    int lastNonZero = 0;

    for (int i = 0; i < numsSize; i++) {
        // When we find a non-zero element...
        if (nums[i] != 0) {
            // Swap it with the element at the 'lastNonZero' pointer
            int temp = nums[i];
            nums[i] = nums[lastNonZero];
            nums[lastNonZero] = temp;
            
            // Increment the pointer for the next non-zero position
            lastNonZero++;
        }
    }
}
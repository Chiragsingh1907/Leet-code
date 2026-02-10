#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // 1. Sort both arrays
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    // 2. Prepare result array (max possible size is the smaller of the two)
    int maxResultSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(maxResultSize * sizeof(int));
    
    int i = 0, j = 0, k = 0;

    // 3. Two-pointer comparison
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            // Found a match
            result[k++] = nums1[i];
            i++;
            j++;
        }
    }

    *returnSize = k;
    return result;
}
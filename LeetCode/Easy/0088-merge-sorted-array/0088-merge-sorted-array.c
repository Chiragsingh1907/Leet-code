void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;      // Last element in nums1's initial data
    int j = n - 1;      // Last element in nums2
    int k = m + n - 1;  // Last position in nums1 total capacity

    // While there are elements to compare in both arrays
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If nums2 still has elements left, copy them.
    // (If nums1 has elements left, they are already in the right place!)
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
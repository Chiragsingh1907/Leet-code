int mySqrt(int x) {
    if (x < 2) return x;

    int left = 1, right = x / 2;
    int ans;

    while (left <= right) {
        // Calculate mid using this method to prevent overflow
        int mid = left + (right - left) / 2;
        
        // Use long long to handle mid * mid overflow
        long long num = (long long)mid * mid;

        if (num == x) {
            return mid;
        } else if (num < x) {
            ans = mid;    // mid is a potential candidate
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return ans;
}
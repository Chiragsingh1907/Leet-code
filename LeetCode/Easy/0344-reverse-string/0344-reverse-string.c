void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    
    while (left < right) {
        // Standard swap logic using a temporary variable
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        // Move pointers toward the center
        left++;
        right--;
    }
}
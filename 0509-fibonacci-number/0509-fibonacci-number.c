int fib(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Recursive calculation
    return fib(n - 1) + fib(n - 2);
}
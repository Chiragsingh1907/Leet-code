#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    // Initialize the result array with 0s
    int* answer = (int*)calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;

    // Stack to store indices
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1; // Stack pointer

    for (int i = 0; i < temperaturesSize; i++) {
        // While stack is not empty and current temp is warmer than temp at stack top
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--];
            answer[prevIndex] = i - prevIndex;
        }
        // Push current index onto stack
        stack[++top] = i;
    }

    free(stack);
    return answer;
}
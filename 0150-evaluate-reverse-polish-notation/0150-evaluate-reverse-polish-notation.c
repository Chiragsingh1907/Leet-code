#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    
    int stack[10000];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        
        if (strcmp(tokens[i], "+") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a + b;
        }
        else if (strcmp(tokens[i], "-") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a - b;
        }
        else if (strcmp(tokens[i], "*") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a * b;
        }
        else if (strcmp(tokens[i], "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a / b;
        }
        else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}
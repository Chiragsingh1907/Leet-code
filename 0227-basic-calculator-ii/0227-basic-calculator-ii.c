#include <ctype.h>
#include <string.h>

int calculate(char* s) {
    int stack[300000];
    int top = -1;
    int num = 0;
    char sign = '+';

    for (int i = 0; i <= strlen(s); i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0') {

            if (sign == '+')
                stack[++top] = num;

            else if (sign == '-')
                stack[++top] = -num;

            else if (sign == '*')
                stack[top] = stack[top] * num;

            else if (sign == '/')
                stack[top] = stack[top] / num;

            sign = s[i];
            num = 0;
        }
    }

    int result = 0;
    while (top >= 0) {
        result += stack[top--];
    }

    return result;
}
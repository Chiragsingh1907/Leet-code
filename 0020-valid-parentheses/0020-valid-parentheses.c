bool isValid(char * s) {
    int len = strlen(s);
    
    // An empty string is valid
    if (len == 0) return true;
    
    // If the length is odd, it's impossible to have all pairs matched
    if (len % 2 != 0) return false;

    // Use an array to simulate a stack.
    char stack[10000]; 
    int top = -1; 

    for (int i = 0; i < len; i++) {
        char current_char = s[i];

        // If it's an open bracket, push it onto the stack
        if (current_char == '(' || current_char == '{' || current_char == '[') {
            stack[++top] = current_char;
        } 
        // If it's a closing bracket
        else {
            // If the stack is empty, there is no corresponding open bracket
            if (top == -1) {
                return false;
            }

            char top_char = stack[top];
            
            // Check if the closing bracket matches the top open bracket
            if ((current_char == ')' && top_char == '(') ||
                (current_char == '}' && top_char == '{') ||
                (current_char == ']' && top_char == '[')) {
                top--; // Pop it off the stack
            } else {
                return false;
            }
        }
    }

    return top == -1;
}
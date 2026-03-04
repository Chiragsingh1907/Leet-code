#include <stdlib.h>

typedef struct {
    int *stack;
    int *minStack;
    int top;
    int minTop;
    int size;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    
    obj->size = 30000;
    obj->stack = (int*)malloc(sizeof(int) * obj->size);
    obj->minStack = (int*)malloc(sizeof(int) * obj->size);
    
    obj->top = -1;
    obj->minTop = -1;
    
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->stack[++obj->top] = val;

    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop]) {
        obj->minStack[++obj->minTop] = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->stack[obj->top] == obj->minStack[obj->minTop]) {
        obj->minTop--;
    }
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
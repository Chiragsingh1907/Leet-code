#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int s1[SIZE];
    int s2[SIZE];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void moveStack(MyQueue* obj) {
    while (obj->top1 != -1) {
        obj->s2[++obj->top2] = obj->s1[obj->top1--];
    }
}

void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1)
        moveStack(obj);

    return obj->s2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1)
        moveStack(obj);

    return obj->s2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int head;
    int tail;
    int size;
    int capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->data = (int*)malloc(sizeof(int) * k);
    obj->capacity = k;
    obj->size = 0;
    obj->head = 0;
    obj->tail = k - 1; // Positioned so the first insertLast goes to index 0
    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;
    // Move head counter-clockwise
    obj->head = (obj->head - 1 + obj->capacity) % obj->capacity;
    obj->data[obj->head] = value;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;
    // Move tail clockwise
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->data[obj->tail] = value;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    // Effectively remove by shifting head clockwise
    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    // Effectively remove by shifting tail counter-clockwise
    obj->tail = (obj->tail - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    return (obj->size == 0) ? -1 : obj->data[obj->head];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    return (obj->size == 0) ? -1 : obj->data[obj->tail];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->data);
    free(obj);
}
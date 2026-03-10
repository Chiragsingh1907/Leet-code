#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

// 1. Sift Up
void siftUp(int* heap, int i) {
    int val = heap[i];
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= val) break;
        heap[i] = heap[parent];
        i = parent;
    }
    heap[i] = val;
}

// 2. Sift Down
void siftDown(int* heap, int size, int i) {
    int val = heap[i];
    while (2 * i + 1 < size) {
        int child = 2 * i + 1;
        if (child + 1 < size && heap[child + 1] < heap[child]) {
            child++;
        }
        if (val <= heap[child]) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = val;
}

// 3. Define Add FIRST so Create knows it exists
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size] = val;
        siftUp(obj->heap, obj->size);
        obj->size++;
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        siftDown(obj->heap, obj->size, 0);
    }
    return obj->heap[0];
}

// 4. Now Create can safely call Add
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(k * sizeof(int));
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }
    return obj;
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
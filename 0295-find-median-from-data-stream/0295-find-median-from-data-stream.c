#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *data;
    int size;
    int capacity;
    int isMinHeap; // 1 for Min-Heap, 0 for Max-Heap
} Heap;

Heap* createHeap(int capacity, int isMinHeap) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->data = (int*)malloc(sizeof(int) * (capacity + 1));
    h->size = 0;
    h->capacity = capacity;
    h->isMinHeap = isMinHeap;
    return h;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(int a, int b, int isMinHeap) {
    return isMinHeap ? (a < b) : (a > b);
}

void push(Heap* h, int val) {
    h->data[++(h->size)] = val;
    int i = h->size;
    while (i > 1 && compare(h->data[i], h->data[i/2], h->isMinHeap)) {
        swap(&h->data[i], &h->data[i/2]);
        i /= 2;
    }
}

int pop(Heap* h) {
    int top = h->data[1];
    h->data[1] = h->data[(h->size)--];
    int i = 1;
    while (i * 2 <= h->size) {
        int child = i * 2;
        if (child + 1 <= h->size && compare(h->data[child+1], h->data[child], h->isMinHeap))
            child++;
        if (compare(h->data[child], h->data[i], h->isMinHeap)) {
            swap(&h->data[i], &h->data[child]);
            i = child;
        } else break;
    }
    return top;
}

typedef struct {
    Heap* maxHeap; // Smaller half
    Heap* minHeap; // Larger half
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxHeap = createHeap(50001, 0);
    obj->minHeap = createHeap(50001, 1);
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    // Always push to maxHeap first, then balance
    push(obj->maxHeap, num);
    push(obj->minHeap, pop(obj->maxHeap));
    
    // Keep maxHeap size >= minHeap size
    if (obj->minHeap->size > obj->maxHeap->size) {
        push(obj->maxHeap, pop(obj->minHeap));
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxHeap->size > obj->minHeap->size) {
        return (double)obj->maxHeap->data[1];
    }
    return (obj->maxHeap->data[1] + obj->minHeap->data[1]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap->data);
    free(obj->maxHeap);
    free(obj->minHeap->data);
    free(obj->minHeap);
    free(obj);
}
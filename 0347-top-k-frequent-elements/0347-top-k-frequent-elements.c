#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int val;
    int freq;
} Element;

// Min-Heap property: Parent freq <= Child freq
void heapifyDown(Element* heap, int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left].freq < heap[smallest].freq)
        smallest = left;
    if (right < size && heap[right].freq < heap[smallest].freq)
        smallest = right;

    if (smallest != idx) {
        Element temp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = temp;
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(Element* heap, int idx) {
    while (idx > 0 && heap[(idx - 1) / 2].freq > heap[idx].freq) {
        Element temp = heap[idx];
        heap[idx] = heap[(idx - 1) / 2];
        heap[(idx - 1) / 2] = temp;
        idx = (idx - 1) / 2;
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // 1. Count frequencies using an offset for negative numbers
    // Range is -10000 to 10000, so 20001 slots
    int offset = 10000;
    int* counts = (int*)calloc(20001, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i] + offset]++;
    }

    // 2. Build a Min-Heap of size K
    Element* heap = (Element*)malloc(k * sizeof(Element));
    int heapSize = 0;

    for (int i = 0; i < 20001; i++) {
        if (counts[i] > 0) {
            Element current = {i - offset, counts[i]};
            
            if (heapSize < k) {
                heap[heapSize] = current;
                heapifyUp(heap, heapSize);
                heapSize++;
            } else if (current.freq > heap[0].freq) {
                heap[0] = current;
                heapifyDown(heap, k, 0);
            }
        }
    }

    // 3. Prepare result
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = heap[i].val;
    }

    free(counts);
    free(heap);
    *returnSize = k;
    return result;
}
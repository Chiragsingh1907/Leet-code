#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};
    int maxFreq = 0;
    int maxFreqCount = 0;

    // 1. Count frequencies of each task
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    // 2. Find the maximum frequency
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    // 3. Count how many tasks have that maximum frequency
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            maxFreqCount++;
        }
    }

    // 4. Calculate total intervals using the greedy formula
    // (maxFreq - 1) creates the "chunks" of time
    // (n + 1) is the size of each chunk including the idle time
    // maxFreqCount adds the tasks that occupy the very last cycle
    int result = (maxFreq - 1) * (n + 1) + maxFreqCount;

    // 5. If the result is smaller than the task count, 
    // it means no idles are needed.
    return MAX(result, tasksSize);
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

#include <stdbool.h>

bool hasCycle(struct ListNode *head) {
    // 1. Handle empty list or single node with no cycle
    if (head == NULL || head->next == NULL) {
        return false;
    }

    // 2. Initialize two pointers (Tortoise and Hare)
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // 3. Traverse the list
    // fast moves twice as fast as slow
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps

        // 4. If they meet, a cycle exists
        if (slow == fast) {
            return true;
        }
    }

    // 5. If fast reaches the end, no cycle exists
    return false;
}
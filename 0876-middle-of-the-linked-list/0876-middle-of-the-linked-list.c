/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    // Initialize both pointers at the start of the list
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Traverse the list:
    // 'fast' moves two steps for every one step 'slow' moves.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps
    }

    // When fast reaches the end, slow is positioned at the middle.
    // In even-length lists, this logic naturally lands on the second middle node.
    return slow;
}
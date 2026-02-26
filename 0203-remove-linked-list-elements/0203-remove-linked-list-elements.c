/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node to handle head deletion easily
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        if (curr->val == val) {
            // Unlink the node
            prev->next = curr->next;
            // In LeetCode/competitive programming, 
            // freeing memory is often optional but good practice:
            struct ListNode* temp = curr;
            curr = curr->next;
            free(temp); 
        } else {
            // Move pointers forward only if no deletion happened
            prev = curr;
            curr = curr->next;
        }
    }
    
    return dummy.next;
}
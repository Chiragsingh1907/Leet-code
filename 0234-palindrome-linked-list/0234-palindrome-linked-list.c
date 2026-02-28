/**
 * Definition for singly-linked list is already provided by the driver.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

// Helper to reverse the list in-place
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *nxt = NULL;
    while (curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    // Base case: empty list or single node is a palindrome
    if (!head || !head->next) return true;

    // 1. Find the middle of the linked list
    // 
    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse the second half
    struct ListNode* secondHalf = reverse(slow->next);

    // 3. Compare the first half and reversed second half
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalf;
    bool result = true;

    while (p2) {
        if (p1->val != p2->val) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 4. Restore the original list structure
    slow->next = reverse(secondHalf);

    return result;
}
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr != NULL) {
        next = curr->next;  // Save the rest of the list
        curr->next = prev;  // Reverse the link
        prev = curr;        // Move prev forward
        curr = next;        // Move curr forward
    }
    return prev; // New head of the reversed list
}

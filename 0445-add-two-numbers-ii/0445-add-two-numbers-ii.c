/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int s1[101], s2[101];
    int top1 = -1, top2 = -1;

    // 1. Fill Stacks (Simulates going to the end of the list)
    while (l1) {
        s1[++top1] = l1->val;
        l1 = l1->next;
    }
    while (l2) {
        s2[++top2] = l2->val;
        l2 = l2->next;
    }

    struct ListNode* res = NULL;
    int carry = 0;

    // 2. Pop and Add (LSD to MSD)
    while (top1 >= 0 || top2 >= 0 || carry) {
        int sum = carry;
        if (top1 >= 0) sum += s1[top1--];
        if (top2 >= 0) sum += s2[top2--];

        carry = sum / 10;
        
        // 3. Create node and PREPEND to the result list
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = res; // Point to the previous "head"
        res = newNode;       // Update "head" to the new node
    }

    return res;
}
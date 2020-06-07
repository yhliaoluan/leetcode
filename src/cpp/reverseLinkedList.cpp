/*
Reverse a singly linked list.
*/
#include "header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return recursive(head);
    }

    ListNode *iterative(ListNode *head) {
        ListNode *cur = NULL;
        while (head) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = cur;
            cur = tmp;
        }
        return cur;
    }

    ListNode *recursive(ListNode *node) {
        if (!node) return nullptr;
        ListNode *next = node->next;
        if (!next) return node;
        ListNode *head = recursive(next);
        next->next = node;
        node->next = nullptr;
        return head;
    }
};

int main(int argc, char **argv) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    for (int i = 1; i < argc; i++) {
        cur->next = new ListNode(atoi(argv[i]));
        cur = cur->next;
    }
    print_list(Solution().reverseList(dummy.next));
    return 0;
}

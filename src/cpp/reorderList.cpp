/*
 *Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
 * */
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
    void reorderList(ListNode* head) {
        if (!head) { return; }
        ListNode *p1 = head, *p2 = head;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode *head2 = p1->next;
        p1->next = NULL;
        p1 = NULL;
        while (head2) {
            p2 = head2->next;
            head2->next = p1;
            p1 = head2;
            head2 = p2;
        }

        while (p1) {
            p2 = head->next;
            head->next = p1;
            p1 = p1->next;
            head->next->next = p2;
            head = p2;
        }
    }
};

int main(int argc, char **argv) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    for (int i = 1; i < argc; i++) {
        cur->next = new ListNode(atoi(argv[i]));
        cur = cur->next;
    }
    print_list(dummy.next);
    Solution s;
    s.reorderList(dummy.next);
    print_list(dummy.next);
    return 0;
}

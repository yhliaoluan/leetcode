/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
#include "header.h"

/**
 * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool remove_if_equals(ListNode **node, int val) {
    if ((*node)->val == val) {
        (*node) = (*node)->next;
        return true;
    }
    return false;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) { return NULL; }
        ListNode *cur = head;
        while (cur->next) {
            if (!remove_if_equals(&cur->next, cur->val)) {
                cur = cur->next;
            }
        }
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
    Solution s;
    ListNode *result = s.deleteDuplicates(dummy.next);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
/*
 *
 Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main(int argc, char **argv) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    for (int i = 1; i < argc - 1; i++) {
        cur->next = new ListNode(atoi(argv[i]));
        cur = cur->next;
    }
    int val = atoi(argv[argc - 1]);
    cur = dummy.next;
    while (cur->val != val)
        cur = cur->next;
    Solution().deleteNode(cur);
    cur = dummy.next;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    cur = dummy.next;
    while (cur) {
        ListNode *tmp = cur->next;
        delete cur;
        cur = tmp;
    }
    return 0;
}

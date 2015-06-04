/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

#include "header.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *left = &dummy;
        while (left->next && left->next->val < x) {
            left = left->next;
        }
        ListNode *right = left;
        while (right->next) {
            while (right->next && right->next->val >= x) {
                right = right->next;
            }
            if (right->next) {
                ListNode *tmp = right->next;
                right->next = tmp->next;
                tmp->next = left->next;
                left->next = tmp;
                left = left->next;
            }
        }
        return dummy.next;
    }
};

int main(int argc, char **argv) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    for (int i = 1; i < argc - 1; i++) {
        cur->next = new ListNode(atoi(argv[i]));
        cur = cur->next;
    }
    Solution s;
    ListNode *result = s.partition(dummy.next, atoi(argv[argc - 1]));
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
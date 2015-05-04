/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode *right = head;
        ListNode *left = &dummy;
        while (right) {
            int count = 0;
            while (right->next && (right->next->val == right->val)) {
                right = right->next;
                count++;
            }
            if (count == 0) {
                left->next = right;
                left = left->next;
            }
            right = right->next;
        }
        left->next = NULL;
        return dummy.next;
    }
};

int main(int argc, char **argv) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    for (int i = 1; i < argc; i++) {
        cur->next = new ListNode(atoi(argv[i]));
        cur = cur->next;
    }
    cur = dummy.next;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    Solution s;
    ListNode *r = s.deleteDuplicates(dummy.next);
    while (r) {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;
}
/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *left = &dummy;
        for (; m-- > 1; n--) {
            left = left->next;
        }
        ListNode *right = left->next;
        while (n-- > 1) {
            ListNode *tmp = right->next;
            right->next = tmp->next;
            ListNode *tmp2 = left->next;
            left->next = tmp;
            tmp->next = tmp2;
        }
        return dummy.next;
    }
};
int main(int argc, char **argv) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    for (int i = 1; i < argc - 2; i++) {
        cur->next = new ListNode(atoi(argv[i]));
        cur = cur->next;
    }
    Solution s;
    ListNode *head = s.reverseBetween(dummy.next, atoi(argv[argc - 2]), atoi(argv[argc - 1]));
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}

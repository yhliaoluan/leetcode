/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || (head && !head->next)) {
            return head;
        }
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (head && head->next) {
            cur->next = head->next;
            head->next = head->next->next;
            cur->next->next = head;
            cur = head;
            head = head->next;
        }
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
    Solution s;
    ListNode *head = s.swapPairs(dummy.next);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
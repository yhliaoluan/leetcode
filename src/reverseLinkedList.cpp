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
        ListNode *cur = NULL;
        while (head) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = cur;
            cur = tmp;
        }
        return cur;
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
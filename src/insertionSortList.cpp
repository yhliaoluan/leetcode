/*
 *Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN);
        ListNode *cur = head;
        while (cur) {
            ListNode *tar = &dummy;
            while (tar->next && tar->next->val < cur->val) {
                tar = tar->next;
            }
            ListNode *tmp = cur;
            cur = cur->next;
            tmp->next = tar->next;
            tar->next = tmp;
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
    ListNode *sorted = s.insertionSortList(dummy.next);
    print_list(sorted);
    return 0;
}

/*
 *Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode* sortList(ListNode* head) {
        int size = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            size++;
        }
        int block = 1;
        ListNode dummy(0);
        dummy.next = head;
        while (block < size) {
            ListNode *par = &dummy;
            ListNode *head1 = dummy.next;
            ListNode *head2 = head1;
            while (head1) {
                int count = 0;
                while (count++ < block && head2) {
                    head2 = head2->next;
                }

                int block1 = block, block2 = block;
                while (head1 && head2 && block1 > 0 && block2 > 0) {
                    if (head1->val < head2->val) {
                        par->next = head1;
                        par = par->next;
                        head1 = head1->next;
                        block1--;
                    } else {
                        par->next = head2;
                        par = par->next;
                        head2 = head2->next;
                        block2--;
                    }
                }

                while (head1 && block1-- > 0) {
                    par->next = head1;
                    par = par->next;
                    head1 = head1->next;
                }
                while (head2 && block2-- > 0) {
                    par->next = head2;
                    par = par->next;
                    head2 = head2->next;
                }

                head1 = head2;
                par->next = head1;
            }
            block <<= 1;
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
    print_list(s.sortList(dummy.next));
    return 0;
}

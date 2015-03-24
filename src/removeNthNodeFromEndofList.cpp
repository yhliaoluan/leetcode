/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *cur = head;
        int count = 0;
        while (cur != NULL) {
            count++;
            cur = cur->next;
        }
        ListNode **pp = &head;
        n = count - n;
        while (n-- > 0) {
            pp = &((*pp)->next);
        }
        *pp = (*pp)->next;
        return head;
    }
};

static Solution s;

int main(int argc, char **argv) {
    ListNode n5(5, NULL);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);

    ListNode *head = s.removeNthFromEnd(&n1, 2);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
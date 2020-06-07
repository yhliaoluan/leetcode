/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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

  typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  } ListNode;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }

        ListNode *root = NULL;
        ListNode **current = &root;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int val = l1->val + l2->val + carry;
            carry = val / 10;
            val %= 10;
            *current = new ListNode(val);
            current = &((*current)->next);
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            int val = l1->val + carry;
            carry = val / 10;
            val %= 10;
            *current = new ListNode(val);
            current = &((*current)->next);
            l1 = l1->next;
        }

        while (l2 != NULL) {
            int val = l2->val + carry;
            carry = val / 10;
            val %= 10;
            *current = new ListNode(val);
            current = &((*current)->next);
            l2 = l2->next;
        }

        if (carry > 0) {
            *current = new ListNode(carry);
        }

        return root;
    }
};

int main(int argc, char **argv) {
    ListNode *l1, *l2;
    l1 = l2 = NULL;
    ListNode **cur = &l1;
    int num;

    while (scanf("%d", &num)) {
        if (num < 0) {
            cur = &l2;
            continue;
        }
        *cur = new ListNode(num);
        cur = &((*cur)->next);
    }

    Solution s;
    ListNode *result = s.addTwoNumbers(l1, l2);
    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");
    return 0;
}

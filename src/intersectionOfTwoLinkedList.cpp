/*
 *Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        ListNode *cur = headA;
        while (cur) {
            cur = cur->next;
            countA++;
        }
        int countB = 0;
        cur = headB;
        while (cur) {
            cur = cur->next;
            countB++;
        }
        if (countA > countB) {
            countA -= countB;
            while (countA-- > 0) {
                headA = headA->next;
            }
        } else {
            countB -= countA;
            while (countB-- > 0) {
                headB = headB->next;
            }
        }
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

int main(int argc, char **argv) {
    ListNode *c1 = new ListNode(4);
    ListNode *c2 = new ListNode(5);
    ListNode *c3 = new ListNode(6);
    c1->next = c2;
    c2->next = c3;

    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    a1->next = a2;

    ListNode *b1 = new ListNode(1);
    ListNode *b2 = new ListNode(2);
    ListNode *b3 = new ListNode(3);
    b1->next = b2;
    b2->next = b3;

    Solution s;
    ListNode *node = s.getIntersectionNode(a1, b1);
    if (node) { cout << "ERROR!" << endl; }

    a2->next = c1;
    b3->next = c1;
    node = s.getIntersectionNode(a1, b1);
    cout << node->val << endl;
    return 0;
}

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        dummy.next = NULL;
        ListNode *head = &dummy;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                head->next = l2;
                break;
            }
            if (l2 == NULL) {
                head->next = l1;
                break;
            }
            if (l1->val < l2->val) {
                head->next = l1;
                head = head->next;
                l1 = l1->next;
            } else {
                head->next = l2;
                head = head->next;
                l2 = l2->next;
            }
        }

        return dummy.next;
    }
};

int main(int argc, char **argv) {
    ListNode l13(1), l12(1), l11(1);
    l11.next = &l12;
    l12.next = &l13;

    ListNode l23(6), l22(4), l21(2);
    l21.next = &l22;
    l22.next = &l23;

    Solution s;
    ListNode *merged = s.mergeTwoLists(&l11, &l21);
    while (merged != NULL) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    return 0;
}
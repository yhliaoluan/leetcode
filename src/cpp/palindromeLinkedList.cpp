/*
 *Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            count++;
        }
        if (count <= 1) return true;
        ListNode *left = NULL;
        ListNode *right = head;
        for (int i = 0; i < count / 2; i++) {
            ListNode *tmp = right->next;
            right->next = left;
            left = right;
            right = tmp;
        }
        if (count % 2 == 1) right = right->next;
        while (left) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    for (int i = 1; i < argc; i++) {
        cur->next = new ListNode(atoi(argv[i]));
        cur = cur->next;
    }
    cout << Solution().isPalindrome(dummy.next) << endl;
    return 0;
}

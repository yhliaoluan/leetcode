/*
 *Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        ListNode *l1 = head, *l2 = head;
        while (l1 != NULL && l2 != NULL) {
            l1 = l1->next;
            if (l1 == NULL) { return false; }
            if (l1 == l2) { return true; }
            l1 = l1->next;
            l2 = l2->next;
            if (l1 == l2) { return true; }
        }
        return false;
    }
};

int main(int argc, char **argv) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    unordered_map<int, ListNode *> map;
    for (int i = 1; i < argc; i++) {
        if (map.find(atoi(argv[i])) != map.end()) {
            cur->next = map[atoi(argv[i])];
            break;
        } else {
            cur->next = new ListNode(atoi(argv[i]));
            cur = cur->next;
            map.insert(make_pair(cur->val, cur));
        }
    }
    Solution s;
    cout << s.hasCycle(dummy.next) << endl;
    return 0;
}

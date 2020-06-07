/*
 *Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *tor = head;
        ListNode *hare = head;
        bool cycle = false;
        while (hare && hare->next) {
            hare = hare->next->next;
            tor = tor->next;
            if (tor == hare) { cycle = true; break; }
        }
        if (!cycle) { return NULL; }
        tor = head;
        while (tor != hare) {
            tor = tor->next;
            hare = hare->next;
        }
        return tor;
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
    ListNode *node = s.detectCycle(dummy.next);
    if (node) {
        cout << node->val << endl;
    } else {
        cout << "NULL" << endl;
    }
    return 0;
}

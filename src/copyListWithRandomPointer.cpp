/*
 *A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
 * */

#include "header.h"
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<RandomListNode *, RandomListNode *> map;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) { return NULL; }
        if (map.find(head) == map.end()) {
            RandomListNode *node = new RandomListNode(head->label);
            map.insert(make_pair(head, node));
            node->next = copyRandomList(head->next);
            node->random = copyRandomList(head->random);
        }
        return map[head];
    }
};

int main(int argc, char **argv) {
    RandomListNode n1(1);
    RandomListNode n2(2);
    RandomListNode n3(3);
    n1.next = &n2;
    n2.next = &n3;
    n1.random = &n3;

    Solution s;
    RandomListNode *copy = s.copyRandomList(&n1);
    cout << copy->label << endl;
    cout << copy->next->label << endl;
    cout << copy->next->next->label << endl;
    cout << copy->random->label << endl;
    return 0;
}

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Comp {
    bool operator() (const ListNode *left, const ListNode *right) {
        return left->val > right->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        priority_queue<ListNode*, vector<ListNode *>, Comp> q;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        while (!q.empty()) {
            ListNode *n = q.top();
            q.pop();
            cur->next = n;
            cur = cur->next;
            if (n->next) {
                q.push(n->next);
            }
        }

        return dummy.next;
    }
};

int main(int argc, char **argv) {
    vector<ListNode *> lists;
    string line;
    while (std::getline(std::cin, line)) {
        stringstream ss(line);
        string item;
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (std::getline(ss, item, ',')) {
            if (!item.empty()) {
                cur->next = new ListNode(std::stoi(item));
                cur = cur->next;
            }
        }
        if (dummy.next != NULL) {
            lists.push_back(dummy.next);
        }
    }
    Solution s;
    ListNode *result = s.mergeKLists(lists);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
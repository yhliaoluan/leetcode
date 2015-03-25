/*
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

 You may not alter the values in the nodes, only nodes itself may be changed.

 Only constant memory is allowed.

 For example,
 Given this linked list: 1->2->3->4->5

 For k = 2, you should return: 2->1->4->3->5

 For k = 3, you should return: 3->2->1->4->5 
 * */
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

static void print(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

static ListNode *reverse(ListNode *head, int *n) {
    ListNode *new_head = NULL;
    ListNode *tail = head;
    int tmp = *n;
    int count = 0;
    while (head && tmp--) {
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
        count++;
    }
    tail->next = head;
    *n = count;
    return new_head;
}
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2) {
            return head;
        }
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (head) {
            int count = k;
            ListNode *result = reverse(head, &count);
            if (count < k) {
                result = reverse(result, &count);
            }
            cur->next = result;
            cur = head;
            head = head->next;
        }
        return dummy.next;
    }
};

int main(int argc, char **argv) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    for (int i = 1; i < argc - 1; i++) {
        cur->next = new ListNode(atoi(argv[i]));
        cur = cur->next;
    }
    Solution s;
    cur = s.reverseKGroup(dummy.next, atoi(argv[argc - 1]));
    print(cur);
    return 0;
}

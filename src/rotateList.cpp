#include "header.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        ListNode *rotate = head;
        ListNode *charge = head;
        int count = 0;
        while (charge != NULL) {
            charge = charge->next;
            count++;
        }
        k %= count;
        charge = head;
        while (k > 0 && charge->next != NULL) {
            charge = charge->next;
            k--;
        }
        while (charge->next != NULL) {
            charge = charge->next;
            rotate = rotate->next;
        }
        charge->next = head;
        head = rotate->next;
        rotate->next = NULL;
        return head;
    }
};

static void print_seq(ListNode *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char **argv) {
    ListNode *nodes = new ListNode[argc - 2];
    memset(nodes, 0, sizeof(ListNode) * (argc - 2));
    for (int i = 1; i < argc - 1; i++) {
        nodes[i - 1].val = atoi(argv[i]);
        if (i < argc - 2) {
            nodes[i - 1].next = &nodes[i];
        }
    }
    print_seq(&nodes[0]);
    Solution s;
    ListNode *head = s.rotateRight(&nodes[0], atoi(argv[argc - 1]));
    print_seq(head);
    delete[] nodes;
    return 0;
}
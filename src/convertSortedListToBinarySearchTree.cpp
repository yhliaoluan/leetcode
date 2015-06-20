/*
 *Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums.data(), nums.size());
    }
    TreeNode *build(int *nums, int len) {
        if (len == 0) { return 0; }
        TreeNode *root = new TreeNode(nums[len / 2]);
        root->left = build(nums, len / 2);
        root->right = build(nums + len / 2 + 1, len - len / 2 - 1);
        return root;
    }
};

int main(int argc, char **argv) {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    for (int i = 1; i < argc; i++) {
        cur->next = new ListNode(atoi(argv[i]));
        cur = cur->next;
    }
    Solution s;
    level_order(s.sortedListToBST(dummy.next));
    return 0;
}

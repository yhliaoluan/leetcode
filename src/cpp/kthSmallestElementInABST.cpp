/*
 *Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 * */
#include "header.h"

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
    int kthSmallest(TreeNode* root, int k) {
        int cur = 0;
        return kth(root, cur, k);
    }

    int kth(TreeNode *node, int &cur, int k) {
        if (!node) return 0;
        int val = kth(node->left, cur, k);
        if (cur == k) return val;
        cur++;
        if (cur == k) return node->val;
        return kth(node->right, cur, k);
    }
};

int main(int argc, char **argv) {
    cout << Solution().kthSmallest(read_tree(argc - 2, argv + 1),
        atoi(argv[argc - 1])) << endl;
    return 0;
}

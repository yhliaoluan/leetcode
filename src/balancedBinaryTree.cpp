/*
 *Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

    int height(TreeNode *node) {
        if (node == NULL) { return 0; }
        int left = height(node->left);
        int right = height(node->right);
        if (left != -1 && right != -1 && abs(left - right) < 2) {
            return max(left, right) + 1;
        } else {
            return -1;
        }
    }
};

int main(int argc, char **argv) {
    TreeNode *root = read_tree(argc - 1, argv + 1);
    Solution s;
    cout << s.isBalanced(root) << endl;
    return 0;
}

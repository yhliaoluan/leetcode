/*
 *Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode* root) {
        if (!root) { return 0; }
        int sum, factor;
        sumDown(root, &sum, &factor);
        return sum;
    }

    void sumDown(TreeNode *node, int *sum, int *factor) {
        if (!node->left && !node->right) {
            *sum = node->val;
            *factor = 10;
            return;
        }
        int sl, fl, sr, fr;
        sl = fl = sr = fr = 0;
        if (node->left) {
            sumDown(node->left, &sl, &fl);
        }
        if (node->right) {
            sumDown(node->right, &sr, &fr);
        }
        *sum = sl + sr + node->val * (fl + fr);
        *factor = 10 * (fl + fr);
    }
};

int main(int argc, char **argv) {
    TreeNode *tree = read_tree(argc - 1, argv + 1);
    Solution s;
    cout << s.sumNumbers(tree) << endl;
    return 0;
}

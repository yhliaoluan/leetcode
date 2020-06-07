/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/
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
    int maxPathSum(TreeNode* root) {
        int ms, m;
        int maxVal = INT_MIN;
        pathSum(root, &ms, &m, &maxVal);
        return maxVal < 0 ? maxVal : m;
    }

    void pathSum(TreeNode *node, int *maxSingle, int *maxAll, int *maxVal) {
        if (node == NULL) {
            *maxSingle = *maxAll = 0;
        } else {
            int ls, l, rs, r;
            *maxVal = max(*maxVal, node->val);
            pathSum(node->left, &ls, &l, maxVal);
            pathSum(node->right, &rs, &r, maxVal);
            *maxSingle = max(0, max(ls + node->val, rs + node->val));
            *maxAll = max(0, max(node->val + ls + rs, max(l, r)));
        }
    }
};

int main(int argc, char **argv) {
    TreeNode *root = read_tree(argc - 1, argv + 1);
    Solution s;
    cout << s.maxPathSum(root) << endl;
    return 0;
}
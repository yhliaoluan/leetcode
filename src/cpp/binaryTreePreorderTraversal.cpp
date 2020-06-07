/*
 *Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> result;
        if (root) { s.push(root); }
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            result.push_back(node->val);
            if (node->right) { s.push(node->right); }
            if (node->left) { s.push(node->left); }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    TreeNode *tree = read_tree(argc - 1, argv + 1);
    Solution s;
    vector<int> result = s.preorderTraversal(tree);
    print_vector(result);
    return 0;
}

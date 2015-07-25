/*
 *Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> res;
        if (root) { s.push(root); }
        while (!s.empty()) {
            TreeNode *top = s.top();
            s.pop();
            if (top->left) s.push(top->left);
            if (top->right) s.push(top->right);
            res.push_back(top->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char **argv) {
    TreeNode *root = read_tree(argc - 1, argv + 1);
    Solution s;
    print_vector(s.postorderTraversal(root));
    return 0;
}

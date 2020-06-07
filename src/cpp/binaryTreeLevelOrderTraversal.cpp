/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        queue<TreeNode *> q;
        if (root != NULL) {
            q.push(root);
        }
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            while (size-- > 0) {
                TreeNode *node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
            result.push_back(v);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(15);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);

    Solution s;
    print_grid(s.levelOrder(root));
    return 0;
}
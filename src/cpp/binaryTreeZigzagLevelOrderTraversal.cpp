/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int zig = 1;
        stack<TreeNode *> s;
        if (root) { s.push(root); }
        vector<vector<int> > result;
        while (!s.empty()) {
            int size = s.size();
            vector<int> v;
            stack<TreeNode *> tmp;
            while (size-- > 0) {
                TreeNode *node = s.top();
                s.pop();
                v.push_back(node->val);
                if (zig) {
                    if (node->left) { tmp.push(node->left); }
                    if (node->right) { tmp.push(node->right); }
                } else {
                    if (node->right) { tmp.push(node->right); }
                    if (node->left) { tmp.push(node->left); }
                }
            }
            swap(s, tmp);
            zig ^= 1;
            result.push_back(v);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    TreeNode *tree = read_tree(argc - 1, argv + 1);
    Solution s;
    print_grid(s.zigzagLevelOrder(tree));
    return 0;
}

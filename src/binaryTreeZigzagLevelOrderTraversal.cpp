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
        int zig = 0;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            int size = s.size();
            vector<int> v;
            while (size-- > 0) {
                TreeNode *node = s.front();
                s.pop();
                v.push(node->val);
                if (zig) {
                    if (node->left) { s.push(node->left); }
                    if (node->right) { s.push(node->right); }
                }
            }
            zig ~= zig;
        }
    }
};

int main(int argc, char **argv) {
    return 0;
}
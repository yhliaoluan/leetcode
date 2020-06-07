/*
 *Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, inorder, 0, inorder.size());
    }

    TreeNode *build(vector<int> &preorder, int i, vector<int> &inorder, int j, int len) {
        if (i >= preorder.size() || len <= 0) { return NULL; }
        TreeNode *root = new TreeNode(preorder[i]);
        int index = 0;
        while (inorder[j + index] != root->val)
            index++;
        root->left = build(preorder, i + 1, inorder, j, index);
        root->right = build(preorder, i + 1 + index, inorder, j + 1 + index, len - 1 - index);
        return root;
    }
};

int main(int argc, char **argv) {
    vector<vector<int> > grid = read_grid<int>();
    Solution s;
    level_order(s.buildTree(grid[0], grid[1]));
    return 0;
}

/*
 *Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder.data(), postorder.data(), inorder.size());
    }

    TreeNode *build(int *inorder, int *postorder, int len) {
        if (len <= 0) { return NULL; }
        TreeNode *root = new TreeNode(postorder[len - 1]);
        int i = 0;
        while (inorder[i] != root->val) i++;
        root->left = build(inorder, postorder, i);
        root->right = build(inorder + i + 1, postorder + i, len - i - 1);
        return root;
    }
};

int main(int argc, char **argv) {
    vector<vector<int> > grid = read_grid<int>();
    Solution s;
    level_order(s.buildTree(grid[0], grid[1]));
    return 0;
}

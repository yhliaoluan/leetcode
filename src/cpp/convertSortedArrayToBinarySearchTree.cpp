/*
 *Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums.data(), nums.size());
    }
    TreeNode *build(int *nums, int len) {
        if (len == 0) { return 0; }
        TreeNode *root = new TreeNode(nums[len / 2]);
        root->left = build(nums, len / 2);
        root->right = build(nums + len / 2 + 1, len - len / 2 - 1);
        return root;
    }
};

int main(int argc, char **argv) {
    vector<vector<int> > grid = read_grid<int>();
    Solution s;
    level_order(s.sortedArrayToBST(grid[0]));
    return 0;
}

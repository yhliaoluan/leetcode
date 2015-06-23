/*
 *Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        if (root) {
            sumDown(root, vector<int>(), result, 0, sum);
        }
        return result;
    }

    void sumDown(TreeNode *node, vector<int> v, vector<vector<int> > &r, int sum, int target) {
        sum += node->val;
        v.push_back(node->val);
        if (node->left) {
            sumDown(node->left, v, r, sum, target);
        }
        if (node->right) {
            sumDown(node->right, v, r, sum, target);
        }
        if (!node->left && !node->right) {
            if (sum == target) {
                r.push_back(v);
            }
        }
    }
};

int main(int argc, char **argv) {
    TreeNode *tree = read_tree(argc - 2, argv + 1);
    Solution s;
    print_grid(s.pathSum(tree, atoi(argv[argc - 1])));
    return 0;
}

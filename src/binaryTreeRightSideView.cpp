/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        if (root) { q.push(root); }
        vector<int> res;
        while (!q.empty()) {
            int size = q.size();
            TreeNode *node = q.front();
            res.push_back(node->val);
            while (size-- > 0) {
                node = q.front();
                if (node->right) { q.push(node->right); }
                if (node->left) { q.push(node->left); }
                q.pop();
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    print_vector(Solution().rightSideView(read_tree(argc - 1, argv + 1)));
    return 0;
}
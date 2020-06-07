/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    void flatten(TreeNode* root) {
        flattenNode(root);
    }

    TreeNode *flattenNode(TreeNode *node) {
        if (!node) { return NULL; }
        TreeNode *left = flattenNode(node->left);
        TreeNode *right = flattenNode(node->right);
        TreeNode *leaf = node;
        if (left) {
            node->right = left;
            leaf = node->right;
            while (leaf->right) {
                leaf = leaf->right;
            }
        }
        node->left = NULL;
        leaf->right = right;
        return node;
    }
};

int main(int argc, char **argv) {
    TreeNode *tree = read_tree(argc - 1, argv + 1);
    Solution s;
    s.flatten(tree);
    level_order(tree);
    return 0;
}







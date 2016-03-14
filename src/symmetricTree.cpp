/*
 *Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;

        return isSymmetric(left->left, right->right) &&
            isSymmetric(left->right, right->left);
    }
};

int main(int argc, char **argv) {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(2);

    n1.left = &n2;
    n1.right = &n3;
    Solution s;
    printf("%d\n", s.isSymmetric(&n1));
    return 0;
}


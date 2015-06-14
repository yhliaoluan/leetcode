/*
 *Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode* root) {
        return root == NULL ||
            (isLessThan(root->left, root->val) &&
            isGreaterThan(root->right, root->val));
    }

    bool isLessThan(TreeNode *node, int val) {
        return node == NULL ||
            (node->val < val && isLessThan(node->left, node->val) &&
             isLessThan(node->right, val) &&
             isGreaterThan(node->right, node->val));
    }

    bool isGreaterThan(TreeNode *node, int val) {
        return node == NULL ||
            (node->val > val && isGreaterThan(node->right, node->val) &&
             isGreaterThan(node->left, val) &&
             isLessThan(node->left, node->val));
    }
};

int main(int argc, char **argv) {
    queue<TreeNode *> q;
    TreeNode *node = new TreeNode(atoi(argv[1]));
    q.push(node);
    int i = 2;
    cout << "param count " << argc << endl;
    while (i < argc) {
        TreeNode *cur = q.front();
        q.pop();
        if (argv[i][0] != '#') {
            cur->left = new TreeNode(atoi(argv[i]));
            q.push(cur->left);
        }
        i++;
        if (argv[i][0] != '#') {
            cur->right = new TreeNode(atoi(argv[i]));
            q.push(cur->right);
        }
        i++;
    }
    Solution s;
    cout << s.isValidBST(node) << endl;
    return 0;
}

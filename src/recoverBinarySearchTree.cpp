/*
 *Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode *> q;
        TreeNode *cur = root;
        TreeNode *min = NULL;
        TreeNode *f = NULL;
        TreeNode *pre = NULL;
        while (cur || !q.empty()) {
            while (cur) {
                q.push(cur);
                cur = cur->left;
            }
            cur = q.top();
            q.pop();
            if (!f && pre && cur->val < pre->val) { f = pre; }
            if (f && (!min || cur->val < min->val)) { min = cur; }
            if (f && cur->val > f->val) { break; }
            pre = cur;
            cur = cur->right;
        }
        if (f && min) {
            swap(f->val, min->val);
        }
    }
};
int main(int argc, char **argv) {
    TreeNode *root = read_tree(argc - 1, argv + 1);
    level_order(root);
    Solution s;
    s.recoverTree(root);
    level_order(root);
    return 0;
}

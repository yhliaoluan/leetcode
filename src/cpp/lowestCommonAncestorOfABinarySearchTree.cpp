/*
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min = std::min(p->val, q->val);
        int max = std::max(p->val, q->val);
        while (root) {
            if (root->val >= min && root->val <= max) break;
            if (root->val > min) root = root->left;
            else root = root->right;
        }
        return root;
    }
};

int main(int argc, char **argv) {
    TreeNode *root = read_tree(argc - 3, argv + 1);
    TreeNode p(atoi(argv[argc - 2]));
    TreeNode q(atoi(argv[argc - 1]));
    cout << Solution().lowestCommonAncestor(root, &p, &q)->val << endl;
    return 0;
}

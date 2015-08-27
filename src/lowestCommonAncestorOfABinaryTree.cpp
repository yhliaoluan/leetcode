/*
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
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
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return left ? right ? root : left : right;
    }
};

static void add_to_map(unordered_map<int, TreeNode *> &map, TreeNode *node) {
    if (!node) return;
    map[node->val] = node;
    add_to_map(map, node->left);
    add_to_map(map, node->right);
}

int main(int argc, char **argv) {
    unordered_map<int, TreeNode *> map;
    TreeNode *root = read_tree(argc - 3, argv + 1);
    add_to_map(map, root);
    cout << Solution().lowestCommonAncestor(root,
        map[atoi(argv[argc - 2])], map[atoi(argv[argc - 1])])->val << endl;
    return 0;
}

/*
 *Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int hl = 0, hr = 0;
        TreeNode *l = root, *r = root;
        while (l) { hl++; l = l->left; }
        while (r) { hr++; r = r->right; }
        if (hl == hr) return pow(2, hl) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

static int count_nodes_naive(TreeNode *node) {
    if (!node) return 0;
    return 1 + count_nodes_naive(node->left) + count_nodes_naive(node->right);
}

static void free_tree(TreeNode *node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    delete node;
}

int main(int argc, char **argv) {
    TreeNode dummy(0);
    TreeNode *cur = &dummy;
    int count = atoi(argv[1]);
    queue<TreeNode *> q;
    if (count > 0) {
        cur->left = new TreeNode(0);
        q.push(cur->left);
    }
    for (int i = 1; i < count;) {
        TreeNode *top = q.front();
        top->left = new TreeNode(i++);
        q.push(top->left);
        if (i < count) {
            top->right = new TreeNode(i++);
            q.push(top->right);
        }
        q.pop();
    }
    cout << count_nodes_naive(dummy.left) << endl;
    cout << Solution().countNodes(dummy.left) << endl;
    free_tree(dummy.left);
    return 0;
}

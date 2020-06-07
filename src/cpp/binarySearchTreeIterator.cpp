/*
 *Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
 * */
#include "header.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur != NULL || !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }
        TreeNode *node = s.top();
        s.pop();
        cur = node->right;
        return node->val;
    }
private:
    TreeNode *cur;
    stack<TreeNode *> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char **argv) {
    BSTIterator i(read_tree(argc - 1, argv + 1));
    while (i.hasNext()) {
        cout << i.next() << " ";
    }
    cout << endl;
    return 0;
}

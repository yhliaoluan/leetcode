/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (cur != NULL || !s.empty()) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    return 0;
}
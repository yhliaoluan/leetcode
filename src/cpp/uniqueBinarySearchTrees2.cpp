/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
static void inorder(TreeNode *node) {
    if (node == NULL) { cout << "NULL "; return; }
    cout << node->val << " ";
    inorder(node->left);
    inorder(node->right);
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }

    vector<TreeNode *> generate(int from, int to) {
        vector<TreeNode *> result;
        if (from == to) {
            result.push_back(new TreeNode(from));
        } else if (from < to) {
            for (int i = from; i <= to; i++) {
                vector<TreeNode *> left = generate(from, i - 1);
                vector<TreeNode *> right = generate(i + 1, to);
                for (int m = 0; m < left.size(); m++) {
                    for (int n = 0; n < right.size(); n++) {
                        TreeNode *root = new TreeNode(i);
                        root->left = left[m];
                        root->right = right[n];
                        result.push_back(root);
                    }
                }
            }
        } else {
            result.push_back(NULL);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<TreeNode *> trees = s.generateTrees(atoi(argv[1]));
    for (int i = 0; i < trees.size(); i++) {
        inorder(trees[i]);
        cout << endl;
    }
    return 0;
}

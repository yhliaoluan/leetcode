/*
 *Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        string path;
        btp(root, path, res);
        return res;
    }

    void btp(TreeNode *node, string &path, vector<string> &res) {
        path += std::to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(path);
        } else {
            path += "->";
            if (node->left) {
                if (node->right) {
                    string copy = path;
                    btp(node->right, copy, res);
                }
                btp(node->left, path, res);
            } else if (node->right) {
                btp(node->right, path, res);
            }
        }
    }
};

int main(int argc, char **argv) {
    TreeNode *root = read_tree(argc - 1, argv + 1);
    print_vector(Solution().binaryTreePaths(root));
    return 0;
}

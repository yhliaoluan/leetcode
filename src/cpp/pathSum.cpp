/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 For example:
 Given the below binary tree and sum = 22,
 
               5
              / \
             4   8
            /   / \
           11  13  4
          /  \      \
         7    2      1
 
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

#include <stdio.h>

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return match(root, 0, sum);
    }
private:
    bool match(TreeNode *node, int cur, int sum) {
        if (node == NULL) {
            return false;
        }
        cur = cur + node->val;
        if (cur == sum && isLeaf(node)) {
            return true;
        } else {
            return match(node->left, cur, sum) ||
                match(node->right, cur, sum);
        }
    }

    bool isLeaf(TreeNode *node) {
        return node->left == NULL && node->right == NULL;
    }
};

int main() {
    return 0;
}

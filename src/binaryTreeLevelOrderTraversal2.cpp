/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

/**
 * Definition for binary tree
 */

#include <stdio.h>
#include <queue>
#include <vector>
 typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 } TreeNode;


using namespace std;
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > v;
        queue<TreeNode *> q;
        if (root != NULL) {
            q.push(root);
        }

        while (!q.empty()) {
            vector<int> values;
            queue<TreeNode *> levelQ;

            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                values.insert(values.begin(), node->val);
                if (node->right != NULL) {
                    levelQ.push(node->right);
                }
                if (node->left != NULL) {
                    levelQ.push(node->left);
                }
            }

            q = levelQ;
            v.insert(v.begin(), values);
        }

        return v;
    }
};

void print_v(vector<vector<int> > &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

void test1(void) {
    TreeNode n1(3);
    TreeNode n2(9);
    TreeNode n3(20);
    n1.left = &n2;
    n1.right = &n3;

    TreeNode n4(15);
    TreeNode n5(7);
    n3.left = &n4;
    n3.right = &n5;

    Solution s;
    vector<vector<int> > v = s.levelOrderBottom(&n1);
    print_v(v);
}

void test2(void) {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    n1.left = &n2;
    n1.right = &n3;
    TreeNode n4(4);
    n2.left = &n4;
    TreeNode n5(5);
    n3.right = &n5;

    Solution s;
    vector<vector<int> > v = s.levelOrderBottom(&n1);
    print_v(v);
}

int main(int argc, char **argv) {
    test1();
    test2();
    return 0;
}

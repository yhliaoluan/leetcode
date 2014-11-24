#include <stdio.h>
#include <queue>

using namespace std;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    bool isEqual(TreeNode *n1, TreeNode *n2) {
        if (n1 == NULL) {
            return (n2 == NULL);
        }
        if (n2 == NULL) {
            return false;
        }
        return n1->val == n2->val;
    }

    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        queue<TreeNode *> q1, q2;
        q1.push(root);
        q2.push(root);

        for (;;) {
            int size1 = q1.size();
            int size2 = q2.size();
            if (size1 != size2) {
                return false;
            }
            if (size1 == 0) {
                break;
            }

            TreeNode *node1 = q1.front();
            TreeNode *node2 = q2.front();
            q1.pop();
            q2.pop();
            if (!isEqual(node1, node2)) {
                return false;
            }
            if (!node1) {
                continue;
            }
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->right);
            q2.push(node2->left);
        }
        return true;
    }
};

int main(int argc, char **argv) {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);

    n1.left = &n2;
    n1.right = &n3;
    Solution s;
    printf("%d\n", s.isSymmetric(&n1));
    return 0;
}


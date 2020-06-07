/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

#include "header.h"
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        recurse(root);
    }

    void queue(TreeLinkNode *root) {
        std::queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            TreeLinkNode *right = NULL;
            while (size-- > 0) {
                TreeLinkNode *front = q.front();
                q.pop();
                front->next = right;
                right = front;
                if (front->right) { q.push(front->right); }
                if (front->left) { q.push(front->left); }
            }
        }
    }

    void recurse(TreeLinkNode *node) {
        if (!node->left) return;
        node->left->next = node->right;
        node->right->next = node->next ? node->next->left : nullptr;
        recurse(node->left);
        recurse(node->right);
    }
};

template <class T>
static void assert(T t1, T t2) {
    if (t1 != t2) {
        cout << "FAILED!!!" << endl;
    }
}

int main(int argc, char **argv) {
    TreeLinkNode one(1);
    TreeLinkNode two(2);
    TreeLinkNode three(3);
    TreeLinkNode four(4);
    TreeLinkNode five(5);
    TreeLinkNode six(6);
    TreeLinkNode seven(7);
    one.left = &two;
    one.right = &three;
    two.left = &four;
    two.right = &five;
    three.left = &six;
    three.right = &seven;

    Solution s;
    s.connect(&one);
    assert(one.next, (TreeLinkNode *)NULL);
    assert(two.next, &three);
    assert(three.next, (TreeLinkNode *)NULL);
    assert(four.next, &five);
    assert(five.next, &six);
    assert(six.next, &seven);
    assert(seven.next, (TreeLinkNode *)NULL);

    return 0;
}

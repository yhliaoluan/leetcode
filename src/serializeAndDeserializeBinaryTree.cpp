/*
 *Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != nullptr) q.push(root);
        stringstream ss;
        ss << "[";
        const char *sep = "";
        while (!q.empty()) {
            ss << sep;
            sep = ",";
            TreeNode *front = q.front();
            q.pop();
            if (front == nullptr) {
                ss << "null";
            } else {
                ss << front->val;
                q.push(front->left);
                q.push(front->right);
            }
        }
        ss << "]";
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> elems;
        split(data.substr(1, data.size() - 2), ',', elems);
        if (elems.size() == 0) return nullptr;
        int i = 0;
        TreeNode *root = new TreeNode(stoi(elems[i++]));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (elems[i].compare("null") != 0) {
                cur->left = new TreeNode(stoi(elems[i]));
                q.push(cur->left);
            }
            i++;
            if (elems[i].compare("null") != 0) {
                cur->right = new TreeNode(stoi(elems[i]));
                q.push(cur->right);
            }
            i++;
        }
        return root;
    }
private:
    void split(string str, char delim, vector<string>& result) {
        stringstream ss(str);
        string item;
        while (getline(ss, item, delim)) {
            result.push_back(item);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, char **argv) {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;

    Codec codec;
    string serialized = codec.serialize(&n1);
    cout << serialized << endl;
    TreeNode *root = codec.deserialize(serialized);
    string serialized2 = codec.serialize(root);
    cout << serialized2 << endl;
    return 0;
}

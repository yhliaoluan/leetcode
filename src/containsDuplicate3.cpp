/*
 *Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k. 
 * */
#include "header.h"

class Node {
public:
    Node* left;
    Node* right;
    int val;
    int index;
    Node(int v, int i) : val(v), index(i), left(NULL), right(NULL) { }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2) { return false; }
        root = new Node(nums[0], 0);
        for (int i = 1; i < nums.size(); i++) {
            if (search(root, nums[i], i, k, t)) {
                return true;
            }
            add(root, nums[i], i);
        }
        return false;
    }
    ~Solution() {
        stack<Node*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            Node* node = q.top();
            q.pop();
            if (node->left) { q.push(node->left); }
            if (node->right) { q.push(node->right); }
            delete node;
        }
    }
private:
    bool search(Node* node, int v, int i, int k, int t) {
        if (!node) { return false; }
        if (abs((long long)node->val - v) <= t && i - node->index <= k) {
            return true;
        }
        if (v - (long long)node->val < t && search(node->left, v, i, k, t)) {
            return true;
        }
        if ((long long)node->val - v < t && search(node->right, v, i, k, t)) {
            return true;
        }
        return false;
    }
    void add(Node* node, int v, int i) {
        if (node->val == v) {
            node->index = i;
        } else if (node->val > v) {
            if (node->left == NULL) {
                node->left = new Node(v, i);
            } else {
                add(node->left, v, i);
            }
        } else {
            if (node->right == NULL) {
                node->right = new Node(v, i);
            } else {
                add(node->right, v, i);
            }
        }
    }
    Node* root;
};

int main(int argc, char** argv) {
    vector<int> nums;
    for (int i = 1; i < argc - 2; i++) {
        nums.push_back(atoi(argv[i]));
    }
    cout << Solution().containsNearbyAlmostDuplicate(nums, atoi(argv[argc - 2]),
        atoi(argv[argc - 1])) << endl;
    return 0;
}

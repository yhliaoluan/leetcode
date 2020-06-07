/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
#include "header.h"

class Solution {
public:
    bool canJump(int A[], int n) {
        int edge = 0;
        int range = 0;
        for (int i = 0; i < n; i++) {
            if (edge < i) {
                return false;
            } else if (edge == i) {
                edge = max(range, A[i] + i);
            }
            range = max(range, A[i] + i);
        }
        return true;
    }
};

int main(int argc, char **argv) {
    vector<int> v;
    for (int i = 1; i < argc; i++)
        v.push_back(atoi(argv[i]));
    Solution s;
    cout << s.canJump(&v[0], v.size()) << endl;
    return 0;
}
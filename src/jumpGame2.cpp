/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
#include "header.h"

class Solution {
public:
    int jump(int A[], int n) {
        stack<int> s;
        for (int i = n - 2; i >= 0; i--) {
            int capacity = A[i];
            int move = 1;
            while (!s.empty() && capacity > s.top()) {
                move += s.top();
                capacity -= s.top();
                s.pop();
            }
            s.push(move);
        }
        return s.size();
    }
};

int main(int argc, char **argv) {
    vector<int> v;
    for (int i = 1; i < argc; i++) {
        v.push_back(atoi(argv[1]));
    }
    Solution s;
    cout << s.jump(&v[0], v.size()) << endl;
    return 0;
}
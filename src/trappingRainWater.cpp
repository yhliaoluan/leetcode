/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
 * */
#include "header.h"
class Solution {
public:
    int trap(int A[], int n) {
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int sum = 0;
        while (left < right) {
            if (A[left] <= A[right]) {
                if (A[left] > leftMax) {
                    leftMax = A[left];
                } else {
                    sum += leftMax - A[left];
                }
                left++;
            } else {
                if (A[right] > rightMax) {
                    rightMax = A[right];
                } else {
                    sum += rightMax - A[right];
                }
                right--;
            }
        }
        return sum;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> v;
    for (int i = 1; i < argc; i++) {
        v.push_back(atoi(argv[i]));
    }
    cout << s.trap(&v[0], v.size()) << endl;
    return 0;
}

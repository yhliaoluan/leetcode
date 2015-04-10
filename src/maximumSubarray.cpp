/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/
#include "header.h"

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum, sum;
        maxSum = sum = A[0];
        for (int i = 1; i < n; i++) {
            if (sum < 0 || sum + A[i] <= 0) sum = A[i];
            else sum += A[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

int main(int argc, char **argv) {
    vector<int> v;
    for (int i = 1; i < argc; i++)
        v.push_back(atoi(argv[i]));
    Solution s;
    cout << s.maxSubArray(&v[0], v.size()) << endl;
    return 0;
}
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
*/
#include "header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        if (nums.size() == 1) { return nums[0]; }
        vector<int> f(nums.size(), 0);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            f[i] = max(nums[i] + f[i - 2], f[i - 1]);
        }
        return f[nums.size() - 1];
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
    cout << Solution().rob(nums) << endl;
    return 0;
}
/*
 *Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
 * */

#include "header.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        if (nums.size() == 1) { return nums[0]; }
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size() - 1));
    }

    int rob(vector<int>& nums, int from, int len) {
        if (len == 1) { return nums[from]; }
        vector<int> f(len, 0);
        f[0] = nums[from];
        f[1] = max(nums[from], nums[from + 1]);
        for (int i = 2; i < len; i++) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i + from]);
        }
        return f[len - 1];
    }
};

int main(int argc, char** argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
    cout << Solution().rob(nums) << endl;
    return 0;
}

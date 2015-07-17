/*
 *Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * */

#include "header.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = nums[0];
        for (int i = 1; i < nums.size(); i++)
            val ^= nums[i];
        return val;
    }
}; 

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.singleNumber(nums) << endl;
    return 0;
}

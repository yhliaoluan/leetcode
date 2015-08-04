/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

#include "header.h"

static bool sort_func(int x, int y) {
    string xy = std::to_string(x) + std::to_string(y);
    string yx = std::to_string(y) + std::to_string(x);
    return xy.compare(yx) > 0;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), sort_func);
        if (nums[0] == 0) { return "0"; }
        stringstream ss;
        for (int num : nums) ss << num;
        return ss.str();
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
    cout << Solution().largestNumber(nums) << endl;
    return 0;
}
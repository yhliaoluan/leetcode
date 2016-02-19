/*
 *Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
 * */
#include "header.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        while (l < nums.size() && nums[l] != 0)
            l++;
        int r = l + 1;
        while (r < nums.size()) {
            if (nums[r] != 0) {
                std::swap(nums[l++], nums[r]);
            }
            r++;
        }
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++)
        nums.push_back(atoi(argv[i]));
    Solution().moveZeroes(nums);
    print_vector(nums);
    return 0;
}

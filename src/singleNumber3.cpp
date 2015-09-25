/*
 *Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 * */
#include "header.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for (int num : nums) {
            xr ^= num;
        }
        xr &= -xr;
        vector<int> res(2, 0);
        for (int num : nums) {
            if (num & xr) {
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++)
        nums.push_back(atoi(argv[i]));
    print_vector(Solution().singleNumber(nums));
    return 0;
}

/*
 *Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = (nums.size() + 1) * nums.size() / 2;
        for (int num : nums) {
            sum -= num;
        }
        return (int) sum;
    }
};

int main(int argc, char **argv) {
    return 0;
}

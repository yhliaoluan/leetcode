/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

#include "header.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[index] != nums[i]) {
                swap(nums[i], nums[index + 1]);
                index += 2;
            }
        }
        return nums[index];
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
    cout << Solution().majorityElement(nums) << endl;
    return 0;
}
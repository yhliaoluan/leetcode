/*
 *Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 * */
#include "header.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pro(nums.size(), 1);
        int product = 1;
        for (int i = 1; i < nums.size(); i++) {
            product *= nums[i - 1];
            pro[i] = product;
        }
        product = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            product *= nums[i + 1];
            pro[i] *= product;
        }
        return pro;
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++)
        nums.push_back(atoi(argv[i]));
    print_vector(Solution().productExceptSelf(nums));
    return 0;
}

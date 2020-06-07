/*
 *Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
 * */
#include "header.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxes(nums.size(), nums[0]);
        vector<int> mins(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                maxes[i] = std::max(nums[i] * maxes[i - 1], nums[i]);
                mins[i] = std::min(nums[i] * mins[i - 1], nums[i]);
            } else {
                maxes[i] = std::max(nums[i] * mins[i - 1], nums[i]);
                mins[i] = std::min(nums[i] * maxes[i - 1], nums[i]);
            }
        }
        int max = INT_MIN;
        for (int m : maxes) {
            max = std::max(max, m);
        }
        return max;
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.maxProduct(nums) << endl;
    return 0;
}

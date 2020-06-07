/*
 *Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
 * */
#include "header.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int left = 0, right = 0;
        int count = nums.size();
        while (right < nums.size()) {
            sum += nums[right++];
            while (sum - nums[left] >= s) {
                sum -= nums[left++];
            }
            if (sum >= s) {
                count = min(count, right - left);
            }
        }
        return sum >= s ? count : 0;
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc - 1; i++) {
        nums.push_back(atoi(argv[i]));
    }
    cout << Solution().minSubArrayLen(atoi(argv[argc - 1]), nums) << endl;
    return 0;
}

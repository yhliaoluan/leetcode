/*
 *A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -¡Þ.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

Credits:
Special thanks to @ts for adding this problem and creating all tesclass Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
    }
};t cases.
 * */
#include "header.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int mid2 = mid + 1;
            if (nums[mid] > nums[mid2]) {
                high = mid;
            } else {
                low = mid2;
            }
        }
        return low;
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.findPeakElement(nums) << endl;
    return 0;
}

/*
 *Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
 * */
#include "header.h"

int find_pivot(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return i;
        }
    }
    return -1;
}

bool bin_srch(vector<int> &nums, int low, int up, int x) {
    if (low == up) { return nums[low] == x; }
    int i = (low + up) / 2;
    if (nums[i] == x) { return true; }
    else if (nums[i] > x) {
        return bin_srch(nums, low, i, x);
    } else {
        return bin_srch(nums, i + 1, up, x);
    }
}

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) { return false; }
        int pivot = find_pivot(nums);
        if (pivot == -1) {
            return bin_srch(nums, 0, nums.size() - 1, target);
        } else {
            return bin_srch(nums, 0, pivot, target) ||
                bin_srch(nums, pivot + 1, nums.size() - 1, target);
        }
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc - 1; i++)
        nums.push_back(atoi(argv[i]));
    Solution s;
    cout << s.search(nums, atoi(argv[argc - 1])) << endl;
    return 0;
}

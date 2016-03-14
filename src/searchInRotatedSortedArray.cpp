/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
#include "header.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }

    int binary_search(vector<int>&nums, int i, int j, int target) {
        if (i > j) return -1;
        int mid = (i + j) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] >= nums[i]) {
            if (nums[mid] > target && target >= nums[i])
                return binary_search(nums, i, mid - 1, target);
            else
                return binary_search(nums, mid + 1, j, target);
        } else {
            if (nums[mid] < target && target < nums[i])
                return binary_search(nums, mid + 1, j, target);
            else
                return binary_search(nums, i, mid - 1, target);
        }
    }
};

int main(int argc, char **argv) {
    vector<int> v;
    for (int i = 1; i < argc - 1; i++) {
        v.push_back(atoi(argv[i]));
    }
    cout << Solution().search(v, atoi(argv[argc - 1])) << endl;
    return 0;
}

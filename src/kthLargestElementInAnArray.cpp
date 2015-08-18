/*
 *Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, 0, nums.size() - 1, k - 1);
    }

    int find(vector<int>& nums, int from, int to, int k) {
        if (from >= to) { return nums[from]; }
        int left = from + 1;
        for (int i = from + 1; i <= to; i++) {
            if (nums[i] > nums[from]) {
                swap(nums[i], nums[left++]);
            }
        }
        left--;
        swap(nums[from], nums[left]);
        if (left > k) {
            return find(nums, from, left - 1, k);
        } else if (left < k) {
            return find(nums, left + 1, to, k);
        } else {
            return nums[k];
        }
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc - 1; i++) {
        nums.push_back(atoi(argv[i]));
    }
    cout << Solution().findKthLargest(nums, atoi(argv[argc - 1])) << endl;
    return 0;
}

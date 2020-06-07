/*
 *Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
 * */
#include "header.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = INT_MIN;
        for (int num : nums) {
            min = std::min(num, min);
        }
        return min;
    }
};

int main(int argc, char **argv) {
    return 0;
}

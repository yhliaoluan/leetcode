/*
 *Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) { return 0; }
        int min = INT_MAX, max = INT_MIN;
        for (int num : nums) {
            min = std::min(num, min);
            max = std::max(num, max);
        }
        if (max == min) { return 0; }
        int bucket_cap = (max - min - 1) / (nums.size() - 1) + 1;
        int bucket_count = (max - min) / bucket_cap + 1;
        vector<int> bucket_mins(bucket_count, INT_MAX);
        vector<int> bucket_maxes(bucket_count, INT_MIN);
        for (int num : nums) {
            int index = (num - min) / bucket_cap;
            bucket_mins[index] = std::min(bucket_mins[index], num);
            bucket_maxes[index] = std::max(bucket_maxes[index], num);
        }
        int diff = std::max(0, bucket_maxes[0] - bucket_mins[0]);
        int last_max = bucket_maxes[0];
        for (int i = 1; i < bucket_count; i++) {
            if (bucket_maxes[i] >= bucket_mins[i]) {
                diff = std::max(diff, std::max(bucket_mins[i] - last_max,
                        bucket_maxes[i] - bucket_mins[i]));
                last_max = bucket_maxes[i];
            }
        }
        return diff;
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++)
        nums.push_back(atoi(argv[i]));
    cout << Solution().maximumGap(nums) << endl;
    return 0;
}

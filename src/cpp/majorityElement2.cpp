/*
 *Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 * */
#include "header.h"

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int can1, can2;
        for (int num : nums) {
            if (c1 == 0) {
                c1 = 1;
                can1 = num;
            } else if (num == can1) {
                c1++;
            } else if (c2 == 0) {
                c2 = 1;
                can2 = num;
            } else if (num == can2) {
                c2++;
            } else {
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        for (int num : nums) {
            if (num == can1) c1++;
            else if (num == can2) c2++;
        }
        vector<int> res;
        if (c1 > nums.size() / 3) res.push_back(can1);
        if (c2 > nums.size() / 3) res.push_back(can2);
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++)
        nums.push_back(atoi(argv[i]));
    print_vector(Solution().majorityElement(nums));
    return 0;
}

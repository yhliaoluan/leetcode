/*
 *Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
 * */
#include "header.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int r = 0;
        for (int i : nums) {
            if (m[i]) { continue; }
            r = max(r, (m[i] = m[i - m[i - 1]] = m[i + m[i + 1]] = (m[i-m[i-1]]+m[i+m[i+1]]+1)));
        }
        return r;
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}

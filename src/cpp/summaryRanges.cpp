/*
 *Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int from = nums[0], to = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != to + 1) {
                string s;
                s += to_string(from);
                if (from != to) {
                    s += "->";
                    s += to_string(to);
                }
                res.push_back(s);
                from = to = nums[i];
            } else {
                to = nums[i];
            }
        }
        string s;
        s += to_string(from);
        if (from != to) {
            s += "->";
            s += to_string(to);
        }
        res.push_back(s);
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++)
        nums.push_back(atoi(argv[i]));
    print_vector(Solution().summaryRanges(nums));
    return 0;
}

/*
 *Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 * */
#include "header.h"

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> v;
        result.push_back(v);
        add(result, nums, v, 0);
        return result;
    }

    void add(vector<vector<int> > &r, vector<int> &nums, 
        vector<int> &v, int i) {
        if (i >= nums.size()) {
            return;
        }
        v.push_back(nums[i]);
        r.push_back(v);
        add(r, nums, v, i + 1);
        v.pop_back();
        while (++i < nums.size() && nums[i] == nums[i - 1])
            ;
        add(r, nums, v, i);
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc; i++)
        nums.push_back(atoi(argv[i]));
    Solution s;
    vector<vector<int> > grid = s.subsetsWithDup(nums);
    print_grid(grid);
    return 0;
}

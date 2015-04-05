/*
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3] 
 * */
#include "header.h"
void find_next(vector<int> &candidates, int index, vector<int> arr,
    vector<vector<int> > &result, int left) {
    if (left == 0) {
        result.push_back(arr);
    }
    if (index >= candidates.size() || candidates[index] > left) {
        return;
    }
    while (left >= 0) {
        find_next(candidates, index + 1, arr, result, left);
        arr.push_back(candidates[index]);
        left -= candidates[index];
    }
}

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        find_next(candidates, 0, vector<int>(), result, target);
        return result;
    }
};

int main(int argc, char **argv) {
    vector<int> candidates;
    for (int i = 1; i < argc - 1; i++) {
        candidates.push_back(atoi(argv[i]));
    }
    Solution s;
    vector<vector<int> > result = s.combinationSum(candidates, atoi(argv[argc - 1]));
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}


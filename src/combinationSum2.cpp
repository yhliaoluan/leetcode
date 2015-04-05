/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 
 * */
#include "header.h"
void find_next(vector<int> &num, int index, vector<int> arr, vector<vector<int> > &result, int left, int last) {
    if (left == 0) {
        result.push_back(arr);
        return;
    }
    if (index >= num.size() || num[index] > left) {
        return;
    }
    find_next(num, index + 1, arr, result, left, 0);
    if (!last && num[index - 1] == num[index]) {
        return;
    }
    arr.push_back(num[index]);
    find_next(num, index + 1, arr, result, left - num[index], 1);
}

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        find_next(num, 0, vector<int>(), result, target, 1);
        return result;
    }
};
int main(int argc, char **argv) {
    vector<int> candidates;
    for (int i = 1; i < argc - 1; i++) {
        candidates.push_back(atoi(argv[i]));
    }
    Solution s;
    vector<vector<int> > result = s.combinationSum2(candidates, atoi(argv[argc - 1]));
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}

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

vector<vector<int> > recurse(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > result;
    find_next(candidates, 0, vector<int>(), result, target);
    return result;
}

typedef unordered_map<int, vector<vector<int> > > um;

vector<vector<int> > dp_recurse(vector<int> &num, int i, int remain, um m[]) {
    if (m[i].find(remain) != m[i].end()) {
        return m[i][remain];
    }
    vector<vector<int> > all;
    if (i == 0) {
        if (remain > 0 && remain % num[i] == 0) {
            vector<int> tmp(remain / num[i], num[i]);
            all.push_back(tmp);
        }
    } else {
        int k = 1;
        while (remain - k * num[i] >= 0) {
            if (remain - k * num[i] == 0) {
                vector<int> v;
                for (int j = 0; j < k; j++) {
                    v.push_back(num[i]);
                }
                all.push_back(v);
            } else {
                for (int n = 1; i - n >= 0; n++) {
                    vector<vector<int> > last = dp_recurse(num, i - n, remain - k * num[i], m);
                    for (int p = 0; p < last.size(); p++) {
                        vector<int> v = last[p];
                        for (int j = 0; j < k; j++) {
                            v.push_back(num[i]);
                        }
                        all.push_back(v);
                    }
                }
            }
            k++;
        }
    }
    m[i][remain] = all;
    return all;
}

vector<vector<int> > dp(vector<int> &num, int target) {
    vector<vector<int> > all;
    um *m = new um[num.size()];
    for (int i = 0; i < num.size(); i++) {
        vector<vector<int> > single = dp_recurse(num, i, target, m);
        all.insert(all.end(), single.begin(), single.end());
    }
    delete[] m;
    return all;
}

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return dp(candidates, target);
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
        cout << "\b" << "]" << endl;
    }
    return 0;
}


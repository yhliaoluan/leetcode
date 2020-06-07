/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
#include "header.h"

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int size = num.size();
        int times = 1;
        while (size > 1) {
            times *= size;
            size--;
        }
        vector<vector<int> > result;
        result.push_back(num);
        while (times-- > 1) {
            nextPermutation(num);
            result.push_back(num);
        }
        return result;
    }

    void nextPermutation(vector<int> &num) {
        for (int i = (int)num.size() - 1; i > 0; i--) {
            if (num[i] > num[i - 1]) {
                for (int j = num.size() - 1; ; j--) {
                    if (num[j] > num[i - 1]) {
                        std::swap(num[i - 1], num[j]);
                        std::reverse(num.begin() + i, num.end());
                        return;
                    }
                }
            }
        }
        std::reverse(num.begin(), num.end());
    }
};

int main(int argc, char **argv) {
    vector<int> num;
    for (int i = 1; i < argc; i++) {
        num.push_back(atoi(argv[i]));
    }
    Solution s;
    vector<vector<int> > result = s.permute(num);
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << ",";
        }
        cout << "\b" << "]" << endl;
    }
    return 0;
}
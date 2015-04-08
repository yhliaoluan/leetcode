/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
#include "header.h"

static int c(int m, int n) {
    n = min(n, m - n);
    int t = n;
    int r = 1;
    while (t--) {
        r *= (m--);
    }
    while (n) {
        r /= (n--);
    }
    return r;
}

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        int size = num.size();
        sort(num.begin(), num.end());
        int last = 0;
        int remain = num.size();
        int times = 1;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] != num[i - 1]) {
                times *= c(remain, i - last);
                remain -= (i - last);
                last = i;
            }
        }
        times *= c(remain, num.size() - last);
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
    vector<vector<int> > result = s.permuteUnique(num);
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << ",";
        }
        cout << "\b" << "]" << endl;
    }
    return 0;
}
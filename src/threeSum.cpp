/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> >v;
        if (num.size() == 0) {
            return v;
        }
        sort(num.begin(), num.end());
        int sum;
        for (int i = 0; i < num.size() - 2; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            sum = num[i];
            if (sum > 0) {
                break;
            }
            for (int j = i + 1; j < num.size() - 1; j++) {
                if (j > i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                sum = num[j] + num[i];
                if (sum > 0) {
                    break;
                }
                for (int n = j + 1; n < num.size(); n++) {
                    if (n > j + 1 && num[n] == num[n - 1]) {
                        continue;
                    }
                    sum = num[i] + num[j] + num[n];
                    if (sum > 0) {
                        break;
                    } else if (sum == 0) {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[n]);
                        v.push_back(tmp);
                    }
                }
            }
        }

        return v;
    }
};

int main(int argc, char **argv) {
    int num, code;
    vector<int> vec;
    while (scanf("%d", &num)) {
        vec.push_back(num);
    }
    Solution s;
    vector<vector<int> > v = s.threeSum(vec);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    return 0;
}




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
        vector<vector<int> > result;
        if (num.size() < 3) {
            return result;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            int low = i + 1;
            int high = num.size() - 1;
            while (low < high) {
                int target = 0 - num[i];
                if (num[low] + num[high] == target) {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[low]);
                    tmp.push_back(num[high]);
                    result.push_back(tmp);
                    while (++low < high && num[low] == num[low - 1]) ;
                    while (--high > low && num[high] == num[high + 1]) ;
                } else if (num[low] + num[high] < target) {
                    while (++low < high && num[low] == num[low - 1]) ;
                } else {
                    while (--high > low && num[high] == num[high + 1]) ;
                }
            }
        }
        return result;
    }
};

static Solution s;

int main(int argc, char **argv) {
    vector<int> num;
    for (int i = 1; i < argc; i++) {
        num.push_back(atoi(argv[i]));
    }
    vector<vector<int> > result = s.threeSum(num);
    for (int i = 0; i < result.size(); i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }
    return 0;
}




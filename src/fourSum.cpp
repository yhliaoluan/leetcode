/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a �� b �� c �� d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
 */
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if (num.size() < 4) {
            return result;
        }
        sort(num.begin(), num.end());
        unordered_map<int, vector<pair<int, int> > > map;
        for (int i = 0; i < num.size() - 1; i++) {
            for (int j = i + 1; j < num.size(); j++) {
                map[num[i] + num[j]].push_back(make_pair(i, j));
            }
        }

        for (int i = 0; i < num.size() - 1; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < num.size(); j++) {
                if (j > i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                int target2 = target - num[i] - num[j];
                bool assigned = false;
                int x, y;
                for (int k = 0; k < map[target2].size(); k++) {
                    if (map[target2][k].first > j) {
                        if (assigned && num[x] == num[map[target2][k].first]) {
                            continue;
                        }
                        assigned = true;
                        x = map[target2][k].first;
                        y = map[target2][k].second;
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[x]);
                        tmp.push_back(num[y]);
                        result.push_back(std::move(tmp));
                    }
                }
            }
        }
        return result;
    }
};

static Solution s;

static void TEST(vector<int> &num, int target) {
    vector<vector<int> > result = s.fourSum(num, target);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    vector<int> num;
    for (int i = 1; i < argc - 1; i++) {
        num.push_back(atoi(argv[i]));
    }
    TEST(num, atoi(argv[argc - 1]));
}

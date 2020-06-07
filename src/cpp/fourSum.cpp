/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
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
        while (map.size() > 0) {
            auto bg = map.begin();
            auto mp = map.find(target - bg->first);
            if (mp != map.end()) {
                for (int i = 0; i < bg->second.size(); i++) {
                    for (int j = 0; j < mp->second.size(); j++) {
                        if (bg->second[i].first != mp->second[j].first &&
                            bg->second[i].second != mp->second[j].second &&
                            bg->second[i].first != mp->second[j].second &&
                            bg->second[i].second != mp->second[j].first) {

                                vector<int> tmp;
                                tmp.push_back(num[bg->second[i].first]);
                                tmp.push_back(num[bg->second[i].second]);
                                tmp.push_back(num[mp->second[j].first]);
                                tmp.push_back(num[mp->second[j].second]);
                                sort(tmp.begin(), tmp.end());
                                if (find(result.begin(), result.end(), tmp) == result.end()) {
                                    result.push_back(tmp);
                                }
                        }
                    }
                }
                if (bg != mp) {
                    map.erase(bg);
                }
                map.erase(mp);
            } else {
                map.erase(bg);
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

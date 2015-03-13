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

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if (num.size() < 4) {
            return result;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 3; i++) {
            if (num[i] >= 0 && num[i] > target) {
                break;
            }
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < num.size() - 2; j++) {
                if (num[j] >= 0 && num[i] + num[j] > target) {
                    break;
                }
                if (j > i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                for (int k = j + 1; k < num.size() - 1; k++) {
                    if (num[k] >= 0 && num[i] + num[j] + num[k] > target) {
                        break;
                    }
                    if (k > j + 1 && num[k] == num[k - 1]) {
                        continue;
                    }
                    int index = exists(num, k + 1, num.size() - 1, target - num[i] - num[j] - num[k]);
                    if (index > -1) {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[k]);
                        tmp.push_back(num[index]);
                        result.push_back(tmp);
                    }
                }
            }
        }
        return result;
    }

private:
    int exists(vector<int> &num, int from, int to, int i) {
        if (from == to) {
            return num[from] == i ? from : -1;
        }

        int index = (from + to) / 2;
        if (num[index] > i) {
            return exists(num, from, index, i);
        } else if (num[index] < i) {
            return exists(num, index + 1, to, i);
        } else {
            return index;
        }
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

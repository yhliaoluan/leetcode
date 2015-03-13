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

typedef struct _st_Entry {
    int key;
    int v1;
    int v2;
} Entry;

bool sort_func(Entry left, Entry right) {
    if (left.key == right.key) {
        return left.v1 < right.v1;
    } else {
        return left.key < right.key;
    }
}

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if (num.size() < 4) {
            return result;
        }
        sort(num.begin(), num.end());
        vector<Entry> entries;
        for (int i = 0; i < num.size() - 1; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < num.size(); j++) {
                if (j > i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                Entry entry = { num[i] + num[j], i, j };
                entries.push_back(entry);
            }
        }
        sort(entries.begin(), entries.end(), sort_func);
        for (int i = 0; i < entries.size() - 1; i++) {
            for (int j = i + 1; j < entries.size(); j++) {
                if (entries[i].key + entries[j].key == target &&
                    entries[i].v1 != entries[j].v1 &&
                    entries[i].v2 != entries[j].v2) {
                    vector<int> tmp;
                    tmp.push_back(num[entries[i].v1]);
                    tmp.push_back(num[entries[i].v2]);
                    tmp.push_back(num[entries[j].v1]);
                    tmp.push_back(num[entries[j].v2]);
                    sort(tmp.begin(), tmp.end());
                    result.push_back(tmp);
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

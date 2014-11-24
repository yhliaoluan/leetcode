/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &s) {
        sort(s.begin(), s.end());
        vector<vector<int> >v;
        vector<int> zero_array;
        v.push_back(zero_array);

        for (int i = 0; i < s.size(); i++) {
            vector<int> array;
            push(s, array, v, 0, i);
        }

        return v;
    }

private: 
    void push(vector<int> &s, vector<int> &added,
        vector<vector<int> > &added_to, int index, int remain) {
        for (int i = index; i < s.size() - remain; i++) {
            vector<int> copied = added;
            copied.push_back(s[i]);
            if (remain == 0) {
                added_to.push_back(copied);
            } else {
                push(s, copied, added_to, i + 1, remain - 1);
            }
        }
    }
};

int main(int argc, char **argv) {
    int value;
    vector<int> array;
    while (scanf("%d", &value)) {
        array.push_back(value);
    }

    printf("input ");
    for (int i = 0; i < array.size(); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    Solution s;
    vector<vector<int> > v = s.subsets(array);
    printf("get size %d\n", v.size());
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

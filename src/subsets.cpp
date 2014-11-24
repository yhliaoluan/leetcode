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

        for (int i = 0; i <= s.size(); i++) {
            vector<int> index;
            int index = 0;
            for (int j = 0; j < i; j++) {
                index.push_back(index++);
            }
            for (;;) {
                vector<int> tmp;
                for (int j = 0; j < i; j++) {
                    tmp.push_back(s[j]);
                }
                v.push_back(tmp);

                if (index.size() == 0) {
                    break;
                }
            }
        }

        return v;
    }

private: 
    void push(vector<int> &s, vector<int> &to, int index) {
    }
};

int main(int argc, char **argv) {
    int value;
    vector<int> array;
    while (scanf("%d", &value)) {
        array.push_back(value);
    }

    Solution s;
    vector<vector<int> > v = s.subsets(array);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

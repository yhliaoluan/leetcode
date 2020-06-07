/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > v;

        vector<int> vec;
        push(v, n, 0, 1, k, vec);

        return v;
    }
private:
    void push(vector<vector<int> > &v, int n, int x, int i, int k, vector<int> &vec) {
        for (int a = x + 1; a <= n - k + i; a++) {
            vector<int> copy = vec;
            copy.push_back(a);
            if (i == k) {
                v.push_back(copy);
            } else {
                push(v, n, a, i + 1, k, copy);
            }
        }
    }
};


int main(int argc, char **argv) {
    if (argc > 1) {
        int n, k;
        sscanf(argv[1], "%d %d", &n, &k);
        printf("n: %d, k: %d\n", n, k);
        Solution s;
        vector<vector<int> > v = s.combine(n, k);

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                printf("%d ", v[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("invalid args.\n");
    }
}



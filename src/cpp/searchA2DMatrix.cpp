/*
 *

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
 * */
#include "header.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) { return false; }
        int m = matrix.size();
        int n = matrix[0].size();
        return bin_srch(matrix, 0, m * n - 1, n, target);
    }
    bool bin_srch(vector<vector<int> > &m, int l, int u, int n, int x) {
        if (l == u) {
            return m[l/n][l%n] == x;
        }
        int i = (l + u) / 2;
        if (m[i/n][i%n] == x) {
            return true;
        } else if (m[i/n][i%n] > x) {
            return bin_srch(m, l, i, n, x);
        } else {
            return bin_srch(m, i + 1, u, n, x);
        }
    }
};

int main(int argc, char **argv) {
    vector<vector<int> > m = read_grid();
    Solution s;
    cout << s.searchMatrix(m, atoi(argv[1])) << endl;
    return 0;
}

/*
 *Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) { return 0; }
        int m = matrix.size();
        int n = matrix[0].size();
        int edge = 0;
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            f[i][n - 1] = (matrix[i][n - 1] == '1');
            edge = max(edge, f[i][n - 1]);
        }
        for (int i = 0; i < n; i++) {
            f[m - 1][i] = (matrix[m - 1][i] == '1');
            edge = max(edge, f[m - 1][i]);
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                f[i][j] = (matrix[i][j] - '0') * 
                    min(f[i + 1][j], min(f[i + 1][j + 1], f[i][j + 1])) +
                    (matrix[i][j] - '0');
                edge = max(edge, f[i][j]);
            }
        }
        return edge * edge;
    }
};

int main(int argc, char** argv) {
    cout << Solution().maximalSquare(read_grid<char>()) << endl;
    return 0;
}

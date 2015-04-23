/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
Note: m and n will be at most 100.
 * */
#include "header.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        int matrix[100][100] = {0};
        for (int i = 0; i < m; i++) {
            matrix[i][n - 1] = 1;
        }
        for (int i = 0; i < n; i++) {
            matrix[m - 1][i] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
            }
        }
        return matrix[0][0];
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.uniquePaths(atoi(argv[1]), atoi(argv[2])) << endl;
    return 0;
}

/*
 *Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 * */
#include "header.h"

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < m; i++)
            grid[i][0] = grid[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            grid[0][j] = grid[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = min(grid[i - 1][j] + grid[i][j],
                    grid[i][j - 1] + grid[i][j]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main(int argc, char **argv) {
    string line;
    vector<vector<int> > grid;
    while (getline(cin, line)) {
        if (line.size() > 0) {
            stringstream stream(line);
            int n;
            vector<int> row;
            while (stream >> n)
                row.push_back(n);
            grid.push_back(row);
        }
    }
    print_grid(grid);
    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}

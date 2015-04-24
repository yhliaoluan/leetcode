/*
 *Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.
 * */
#include "header.h"
void print_grid(vector<vector<int> > &grid);

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] ^= 1;
            }
        }
        for (int i = m - 2; i>= 0; i--) {
            if (grid[i][n - 1])
                grid[i][n - 1] = grid[i + 1][n - 1];
        }
        for (int j = n - 2; j >= 0; j--) {
            if (grid[m - 1][j])
                grid[m - 1][j] = grid[m - 1][j + 1];
        }
        for (int i = grid.size() - 2; i >= 0; i--) {
            for (int j = grid[i].size() - 2; j >= 0; j--) {
                if (grid[i][j])
                    grid[i][j] = grid[i+1][j] + grid[i][j+1];
            }
        }
        return grid[0][0];
    }
};

void print_grid(vector<vector<int> > &grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

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
    cout << s.uniquePathsWithObstacles(grid) << endl;
    return 0;
}

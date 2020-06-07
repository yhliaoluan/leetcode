/*
 *Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    stack<pair<int, int> > islands;
                    grid[i][j] = '-';
                    islands.push(make_pair(i, j));
                    while (!islands.empty()) {
                        pair<int, int> island = islands.top();
                        islands.pop();
                        check(island.first - 1, island.second, islands, grid);
                        check(island.first + 1, island.second, islands, grid);
                        check(island.first, island.second - 1, islands, grid);
                        check(island.first, island.second + 1, islands, grid);
                    }
                    num++;
                }
            }
        }
        return num;
    }
private:
    void check(int x, int y, stack<pair<int, int> > &s,
        vector<vector<char> > &grid) {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()
            && grid[x][y] == '1') {
            grid[x][y] = '-';
            s.push(make_pair(x, y));
        }
    }
};

int main(int argc, char **argv) {
    vector<vector<char> > grid = read_grid<char>();
    cout << Solution().numIslands(grid) << endl;
    return 0;
}

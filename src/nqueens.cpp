/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
#include "header.h"
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> rows(n, -1);
        vector<vector<string> > result;
        dfs(rows, 0, result);
        return result;
    }
private:
    void dfs(vector<int> &rows, int row, vector<vector<string> > &result) {
        if (row >= rows.size()) {
            vector<string> board;
            for (int i = 0; i < rows.size(); i++) {
                string s(rows.size(), '.');
                s[rows[i]] = 'Q';
                board.push_back(s);
            }
            result.push_back(board);
            return;
        }

        for (int col = 0; col < rows.size(); col++) {
            if (valid(col, rows, row)) {
                rows[row] = col;
                dfs(rows, row + 1, result);
                rows[row] = -1;
            }
        }
    }
    bool valid(int col, vector<int> &rows, int row) {
        for (int i = 0; i < row; i++) {
            if (rows[i] == col || abs(i - row) == abs(rows[i] - col)) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<string> > result = s.solveNQueens(atoi(argv[1]));
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}

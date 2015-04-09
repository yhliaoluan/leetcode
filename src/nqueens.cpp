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
static void solve(int i, vector<string> &board, vector<vector<string> > &result) {
    if (i >= board.size()) {
        result.push_back(board);
        return;
    }
    for (int j = 0; j < board.size(); j++) {
        if (board[i][j] == 'Q') {
            vector<string> copy = board;
            for (int x = 1; x < board.size(); x++) {
                copy[(i+x)%board.size()][j] = '.';
                copy[(i+x)%board.size()][(j+x)%board.size()] = '.';
                copy[i][(j+x)%board.size()] = '.';
                copy[(i+x)%board.size()][abs(j-x)%board.size()] = '.';
            }
            solve(i + 1, copy, result);
        }
    }
}

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<string> init;
        for (int i = 0; i < n; i++) {
            string s;
            for (int j = 0; j < n; j++) {
                s += 'Q';
            }
            init.push_back(s);
        }
        solve(0, init, result);
        return result;
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

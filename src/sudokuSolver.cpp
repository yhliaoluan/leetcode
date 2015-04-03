#include "header.h"
bool check(vector<vector<char> > &board, int i, int j, char c) {
    for (int m = 0; m < 9; m++) {
        if (board[i][m] == c || board[m][j] == c || board[i / 3 * 3 + m / 3][j / 3 * 3 + m % 3] == c) {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char> > &board, int index) {
    if (index == 81) {
        return true;
    }
    int m = index / 9;
    int n = index % 9;
    if (board[m][n] != '.') {
        return solve(board, index + 1);
    }
    for (int i = 0; i < 9; i++) {
        if (check(board, m, n, i + '1')) {
            board[m][n] = i + '1';
            if (solve(board, index + 1)) {
                return true;
            }
            board[m][n] = '.';
        }
    }
    return false;
}

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0);
    }
};

int main(int argc, char **argv) {
    char c;
    vector<vector<char> > board;
    for (int i = 0; i < 9; i++) {
        vector<char> line;
        for (int j = 0; j < 9; j++) {
            cin >> c;
            line.push_back(c);
        }
        board.push_back(line);
    }
    solve(board, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}
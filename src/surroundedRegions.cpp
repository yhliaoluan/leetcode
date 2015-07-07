/*
 *Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
 * */

#include "header.h"

class Solution {
public:
    void push(vector<vector<char> > &board, queue<pair<int, int> > &q, int x, int y) {
        if (board[x][y] == 'O') {
            q.push(pair<int, int>(x, y));
            board[x][y] = '-';
        }
    }
    void solve(vector<vector<char> >& board) {
        if (board.size() == 0 || board[0].size() == 0) { return; }
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int> > q;
        for (int i = 0; i < m; i++) {
            push(board, q, i, 0);
            push(board, q, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            push(board, q, 0, i);
            push(board, q, m - 1, i);
        }
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first > 0)
                push(board, q, p.first - 1, p.second);
            if (p.first < m - 1)
                push(board, q, p.first + 1, p.second);
            if (p.second > 0)
                push(board, q, p.first, p.second - 1);
            if (p.second < n - 1)
                push(board, q, p.first, p.second + 1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main(int argc, char **argv) {
    vector<vector<char> > grid = read_grid<char>();
    Solution s;
    s.solve(grid);
    print_grid(grid);
    return 0;
}

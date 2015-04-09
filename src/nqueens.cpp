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
static void set(vector<vector<int> > &board, int i, int j) {
}

static void nqueen(int i, vector<vector<int> > board, vector<vector<string> > &result) {
    if (i == board.size()) {
        vector<string> r;
        for (int x = 0; x < board.size(); x++) {
            string line;
            for (int y = 0; y < board.size(); y++) {
                if (board[x][y]) {
                    line.append('Q');
                } else {
                    line.append('.');
                }
            }
            r.push_back(line);
        }
        result.push_back(r);
    }
    for (int j = 0; j < board.size(); j++) {
        if (board[i][j]) {
            vector<vector<int> > copy = board;
            set(copy, i, j);
            nqueen(i + 1, copy, result);
        }
    }
}

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<int> > q;
        for (int i = 0; i < n; i++) {
            vector<int> line;
            for (int j = 0; j < n; j++) {
                line.push_back(1);
            }
            q.push_back(line);
        }
    }
};

int main(int argc, char **argv) {
    return 0;
}
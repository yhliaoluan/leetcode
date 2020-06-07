#include "header.h"
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> rows(n, -1);
        dfs(rows, 0, &count);
        return count;
    }
private:
    void dfs(vector<int> &rows, int row, int *count) {
        if (row >= rows.size()) {
            (*count)++;
            return;
        }

        for (int col = 0; col < rows.size(); col++) {
            if (valid(col, rows, row)) {
                rows[row] = col;
                dfs(rows, row + 1, count);
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
    cout << s.totalNQueens(atoi(argv[1])) << endl;
}
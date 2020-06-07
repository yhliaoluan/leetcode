/*
 *According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 * */

#include "header.h"

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int status = getStatus(board, i, j);
                int live = (getStatus(board, i - 1, j - 1) +
                    getStatus(board, i - 1, j) +
                    getStatus(board, i - 1, j + 1) +
                    getStatus(board, i, j - 1) +
                    getStatus(board, i, j + 1) +
                    getStatus(board, i + 1, j - 1) + 
                    getStatus(board, i + 1, j) +
                    getStatus(board, i + 1, j + 1));
                if (status == 1 && (live == 2 || live == 3)) {
                    setStatus(board, i, j, 1);
                } else if (status == 0 && live == 3) {
                    setStatus(board, i, j, 1);
                }
            }
        }
        refreshBoard(board);
    }
private:
    int getStatus(vector<vector<int>>& board, int x, int y) {
        if (x < 0 || x >= board.size() ||
            y < 0 || y >= board[0].size()) {
            return 0;
        }
        return board[x][y] & 0x01;
    }
    void setStatus(vector<vector<int>>& board, int x, int y, int s) {
        board[x][y] |= (s << 1);
    }
    void refreshBoard(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1;
            }
        }
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> board = read_grid<int>();
    print_grid(board);
    Solution().gameOfLife(board);
    print_grid(board);
    return 0;
}

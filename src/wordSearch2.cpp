/*
 *Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
 * */

#include "header.h"

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board,
        vector<string>& words) {
        vector<string> res;
        unordered_set<string> hash;
        if (board.empty()) { return res; }
        for (string &word : words) {
            if (contains(board, word)) {
                if (hash.find(word) == hash.end()) {
                    hash.insert(word);
                    res.push_back(word);
                }
            }
        }
        return res;
    }

    bool contains(vector<vector<char>> &board, string &word) {
        if (word.empty()) { return true; }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> used(board.size(),
                        vector<int>(board[0].size(), 0));
                    if (check(used, i, j, word, 0, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool check(vector<vector<int>> &used, int x, int y,
        string &word, int index, vector<vector<char>> &board) {
        if (index >= word.size()) { return true; }
        if (x < 0 || y < 0
            || x >= board.size() || y >= board[0].size()) { return false; }
        if (used[x][y]) { return false; }
        if (board[x][y] != word[index]) { return false; }
        used[x][y] = 1;
        bool result = check(used, x - 1, y, word, index + 1, board) ||
            check(used, x + 1, y, word, index + 1, board) ||
            check(used, x, y - 1, word, index + 1, board) ||
            check(used, x, y + 1, word, index + 1, board);
        used[x][y] = 0;
        return result;
    }
};

int main(int argc, char **argv) {
    vector<vector<char>> board = read_grid<char>();
    vector<string> words;
    for (int i = 1; i < argc; i++) {
        words.push_back(argv[i]);
    }
    print_vector(Solution().findWords(board, words));
    return 0;
}

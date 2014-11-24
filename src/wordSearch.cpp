/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0) {
            return false;
        }
        if (word.size() == 0) {
            return true;
        }

        vector<vector<int> > roads;
        for (int i = 0; i < board.size(); i++) {
            vector<int> road;
            for (int j = 0; j < board[i].size(); j++) {
                road.push_back(0);
            }
            roads.push_back(road);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (match(board, i, j, 0, word, roads)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
private:
    bool match(vector<vector<char> > &board, int i, int j, int index,
        string word, vector<vector<int> > &road) {
        if (index >= word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) {
            return false;
        }
        if (road[i][j] == 1) {
            return false;
        }
        if (board[i][j] != word[index]) {
            return false;
        }

        road[i][j] = 1;
        index++;

        bool result = match(board, i + 1, j, index, word, road) ||
            match(board, i - 1, j, index, word, road) ||
            match(board, i, j + 1, index, word, road) ||
            match(board, i, j - 1, index, word, road);

        if (!result) {
            road[i][j] = 0;
        }

        return result;
    }

    void clear(vector<vector<int> > &road) {
        for (int i = 0; i < road.size(); i++) {
            for (int j = 0; j < road[i].size(); j++) {
                road[i][j] = 0;
            }
        }
    }
};

int main(int argc, char **argv) {
    vector<vector<char> >v;
    vector<char> a;
    a.push_back('A');
    a.push_back('B');
    a.push_back('C');
    a.push_back('E');
    v.push_back(a);
    a.clear();
    a.push_back('S');
    a.push_back('F');
    a.push_back('E');
    a.push_back('S');
    v.push_back(a);
    a.clear();
    a.push_back('A');
    a.push_back('D');
    a.push_back('E');
    a.push_back('E');
    v.push_back(a);

    Solution s;
    if (argc > 1) {

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                printf("%c", v[i][j]);
            }
            printf("\n");
        }
        printf("input %s\n", argv[1]);

        printf(s.exist(v, argv[1]) ? "true\n" : "false\n");
    }
    return 0;
}

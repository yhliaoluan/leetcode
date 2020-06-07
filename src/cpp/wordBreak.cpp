/*
 *Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
 * */
#include "header.h"

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty()) { return false; }
        vector<vector<bool> > f(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size() - i; j++) {
                segment(s, j, j + i, f, wordDict);
            }
        }
        return f[0][s.size() - 1];
    }

    void segment(string &s, int a, int b, vector<vector<bool> > &f,
        unordered_set<string> &dict) {
        if (dict.find(s.substr(a, b - a + 1)) != dict.end()) {
            f[a][b] = true;
        } else {
            for (int i = a; i < b; i++) {
                if (f[a][i] && f[i + 1][b]) {
                    f[a][b] = true;
                    break;
                }
            }
        }
    }
};

int main(int argc, char **argv) {
    unordered_set<string> dict;
    for (int i = 2; i < argc; i++) {
        dict.insert(argv[i]);
    }
    Solution s;
    cout << s.wordBreak(argv[1], dict) << endl;
    return 0;
}

/*
 *Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
 * */

#include "header.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m == 0 || n == 0) { return 0; }
        vector<vector<int> > f;
        for (int i = 0; i < m; i++) {
            f.push_back(vector<int>(n, 0));
        }

    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.numDistinct(argv[1], argv[2]) << endl;
    return 0;
}

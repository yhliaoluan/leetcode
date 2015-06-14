/*
 *Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
 * */
#include "header.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m == 0) {
            return s2.compare(s3) == 0;
        }
        if (n == 0) {
            return s1.compare(s3) == 0;
        }
        if (m + n != s3.size()) { return false; }
        vector<vector<int> > f;
        for (int i = 0; i <= m; i++) {
            vector<int> row(n + 1, 0);
            f.push_back(row);
        }
        for (int i = 0; i < m; i++) {
            f[i][n] = (s1.compare(i, m - i, s3, i + n, m - i) == 0);
        }
        for (int j = 0; j < n; j++) {
            f[m][j] = (s2.compare(j, n - j, s3, j + m, n - j) == 0);
        }
        for (int j = n - 1; j >= 0; j--) {
            for (int i = m - 1; i >= 0; i--) {
                f[i][j] = (f[i][j + 1] && (s2[j] == s3[i + j])) ||
                    (f[i + 1][j] && (s1[i] == s3[i + j]));
            }
        }
        return f[0][0];
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.isInterleave(argv[1], argv[2], argv[3]) << endl;
    return 0;
}

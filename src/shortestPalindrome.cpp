/*
 *Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.
 * */
#include "header.h"

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() <= 1) { return s; }
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        rev_s = s + "#" + rev_s;
        vector<int> next(rev_s.size(), 0);
        for (int i = 1; i < rev_s.size(); i++) {
            int j = next[i - 1];
            while (j > 0 && rev_s[j] != rev_s[i])
                j = next[j - 1];
            next[i] = j + (rev_s[j] == rev_s[i]);
        }
        return rev_s.substr(s.size() + 1,
            s.size() - min((int)s.size(), next[rev_s.size() - 1])) + s;
    }
};

int main(int argc, char** argv) {
    cout << Solution().shortestPalindrome(argv[1]) << endl;
    return 0;
}

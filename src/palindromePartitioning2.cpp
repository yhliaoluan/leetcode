/*
 *Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 * */

#include "header.h"

class Solution {
public:
    int minCut(string s) {
        int m = INT_MAX;
        partition(s, 0, m, 0);
        return max(0, m - 1);
    }

    void partition(string &s, int a, int &m, int count) {
        if (a >= s.size()) {
            m = min(m, count);
            return;
        }
        for (int i = a; i < s.size(); i++) {
            if (isPalindrome(s, a, i)) {
                partition(s, i + 1, m, count + 1);
            }
        }
    }

    bool isPalindrome(string &s, int i, int j) {
        while (i <= j) {
            if (s[i++] != s[j--]) { return false; }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.minCut(argv[1]) << endl;
    return 0;
}

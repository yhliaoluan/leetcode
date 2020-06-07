/*
 *Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
 * */

#include "header.h"

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        vector<string> path;
        partition(s, result, 0, path);
        return result;
    }

    void partition(string &s, vector<vector<string> > &result, int a, vector<string> &path) {
        if (a >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = a; i < s.size(); i++) {
            if (isPalindrome(s, a, i)) {
                path.push_back(s.substr(a, i - a + 1));
                partition(s, result, i + 1, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int a, int b) {
        while (a <= b) {
            if (s[a++] != s[b--]) { return false; }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    print_grid(s.partition(argv[1]));
    return 0;
}

/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/
#include "header.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (0 == s1.compare(s2)) { return true; }
        string copy1 = s1;
        string copy2 = s2;
        sort(copy1.begin(), copy1.end());
        sort(copy2.begin(), copy2.end());
        if (0 != copy1.compare(copy2)) { return false; }
        for (int i = 1; i < s1.size(); i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i)) &&
                isScramble(s2.substr(0, s2.size() - i), s1.substr(i, s1.size() - i))) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.isScramble(argv[1], argv[2]) << endl;
    return 0;
}
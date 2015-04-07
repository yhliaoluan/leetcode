/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/
#include "header.h"

class Solution {
public:
    bool isMatch(const char *s, const char *p) {}
};

int main(int argc, char **argv) {
    cout << strncmp(argv[1], argv[2], strlen(argv[2])) << endl;
    return 0;
}
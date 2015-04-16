/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
#include "header.h"

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while (*s) {
            if (*s == ' ') {
                while (*s == ' ') s++;
                if (*s) len = 0;
            } else {
                len++;
                s++;
            }
        }
        return len;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.lengthOfLastWord(argv[1]) << endl;
    return 0;
}
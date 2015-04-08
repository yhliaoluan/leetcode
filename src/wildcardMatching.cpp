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
bool is_match(const char *s, const char *p) {
    const char* star=NULL;
    const char* ss=s;
    while (*s){
        //advancing both pointers when (both characters match) or ('?' found in pattern)
        //note that *p will not advance beyond its length 
        if ((*p=='?')||(*p==*s)){s++;p++;continue;} 

        // * found in pattern, track index of *, only advancing pattern pointer 
        if (*p=='*'){star=p++; ss=s;continue;} 

        //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
        //only advancing pattern pointer
        if (star){ p = star+1; s=++ss;continue;} 

        //current pattern pointer is not star, last patter pointer was not *
        //characters do not match
        return false;
    }

    //check for remaining characters in pattern
    while (*p=='*'){p++;}

    return !*p;  
}

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s) {
            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p=='*') {
                star=p++;
                ss=s;
            } else if ((*p == '?') || (*p == *s)) {
                s++;
                p++;
            } else if (star) {
                p = star + 1;
                s = ++ss;
            } else {
                return false;
            }
        }

        //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;  
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << is_match(argv[1], argv[2]) << endl;
    cout << s.isMatch(argv[1], argv[2]) << endl;
    return 0;
}
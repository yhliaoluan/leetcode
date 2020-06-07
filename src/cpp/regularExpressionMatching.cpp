/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true
 * */

#include <stdio.h>
#include <string.h>

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int m = strlen(s);
        int n = strlen(p);

        int x = 0;
        int y = 0;

        return match(s, m, x, p, n, y);
    }

    bool match(const char *s, int m, int x, const char *p, int n, int y) {
        if (x == m && y == n) {
            return true;
        }

        if (y == n) {
            return false;
        }

        if (x == m) {
            return y + 1 < n &&
                p[y + 1] == '*' &&
                match(s, m, x, p, n, y + 2);
        }

        if (y + 1 < n && p[y + 1] == '*') {
            if (y + 2 == n) {
                while (x < m) {
                    if (!match(s[x++], p[y])) {
                        return false;
                    }
                }
            } else {
                for (;;) {
                    if (x == m) {
                        return match(s, m, x, p, n, y + 2);
                    }
                    if (match(s, m, x, p, n, y + 2)) {
                        return true;
                    }
                    if (!match(s[x++], p[y])) {
                        return false;
                    }
                }
            }
        } else {
            if (match(s[x], p[y])) {
                return match(s, m, x + 1, p, n, y + 1);
            } else {
                return false;
            }
        }
    }

    bool match(char x, char y) {
        return x == y || y == '.';
    }
};

static Solution _s;

#define TEST(x, y) if (!_s.isMatch(x, y)) printf("FAILED %s %s\n", x, y);

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char x[1024] = {0};
        char y[1024] = {0};
        scanf("%s", x);
        scanf("%s", y);
        TEST(x, y);
    }

    return 0;
}

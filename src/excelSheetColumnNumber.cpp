/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

#include "header.h"

class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        int factor = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            num += (s[i] - 64) * factor;
            factor *= 26;
        }
        return num;
    }
};

int main(int argc, char **argv) {
    cout << Solution().titleToNumber(argv[1]) << endl;
    return 0;
}
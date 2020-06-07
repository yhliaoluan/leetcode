/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. 
*/
#include "header.h"

string cs_next(string s) {
    string next;
    for (int i = 0; i < s.size();) {
        int j = i + 1;
        while (j < s.size() && s[j] == s[i]) {
            j++;
        }
        next += (char)('0' + (j - i));
        next += s[i];
        i = j;
    }
    return next;
}

class Solution {
public:
    string countAndSay(int n) {
        string first("1");
        while (--n > 0) {
            first = cs_next(first);
        }
        return first;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.countAndSay(atoi(argv[1])) << endl;
    return 0;
}

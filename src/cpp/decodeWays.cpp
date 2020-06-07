/*
 *A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
 * */
#include "header.h"

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') { return 0; }
        int odd = 1;
        int even = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0' && (s[i - 1] == '0' || s[i - 1] > '2')) {
                odd = even = 0;
                break;
            }
            if ((s[i] > '6' && s[i - 1] > '1') || s[i - 1] > '2' || s[i - 1] == '0') {
                odd = odd + even;
                even = 0;
            } else if (s[i] == '0') {
                even = odd;
                odd = 0;
            } else {
                odd = odd + even;
                even = odd - even;
            }
        }
        return odd + even;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.numDecodings(argv[1]) << endl;
    return 0;
}

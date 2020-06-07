/*
 * Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
 * */
#include "header.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1;
        int n = b.size() - 1;
        int factor = 0;
        string result;
        while (m >= 0 || n >= 0) {
            int sum = (m >= 0 ? (a[m--] - '0') : 0) + (n >= 0 ? (b[n--] - '0') : 0) + factor;
            factor = sum / 2;
            result += (char)((sum % 2) + '0');
        }
        if (factor > 0) {
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.addBinary(argv[1], argv[2]) << endl;
    return 0;
}

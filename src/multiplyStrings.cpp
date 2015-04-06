/*
 Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
 * */
#include "header.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int *r = new int[m + n];
        memset(r, 0, sizeof(int) * (m + n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mul = ((int)num1[i] - '0') * ((int)num2[j] - '0');
                r[i + j] += mul;
            }
        }
        for (int i = 0; i < m + n - 1; i++) {
            r[i + 1] += r[i] / 10;
            r[i] %= 10;
        }
        int index = m + n - 1;
        while (r[index] == 0) {
            index--;
        }
        string result;
        while (index >= 0) {
            result += (char)(r[index] + '0');
            index--;
        }
        delete[] r;
        return result.empty() ? "0" : result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.multiply(argv[1], argv[2]) << endl;
    return 0;
}

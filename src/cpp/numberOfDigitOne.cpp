/*
 *Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13. 
 * */
#include "header.h"

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for (long long k = 1; k <= n; k *= 10) {
            long long r = n / k, m = n % k;
            count += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
        }
        return count;
    }
};

int main(int argc, char **argv) {
    cout << Solution().countDigitOne(atoi(argv[argc - 1])) << endl;
    return 0;
}

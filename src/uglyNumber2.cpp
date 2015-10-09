/*
 *Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
 * */

#include "header.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> f(n, 1);
        int x = 0, y = 0, z = 0;
        for (int i = 1; i < n; i++) {
            f[i] = min(f[x] * 2, min(f[y] * 3, f[z] * 5));
            if (f[i] == f[x] * 2) x++;
            if (f[i] == f[y] * 3) y++;
            if (f[i] == f[z] * 5) z++;
        }
        return f[n - 1];
    }
};

int main(int argc, char **argv) {
    cout << Solution().nthUglyNumber(atoi(argv[1])) << endl;
    return 0;
}

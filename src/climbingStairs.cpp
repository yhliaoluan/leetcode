/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include "header.h"

static int cmn(int m, int n) {
    if (n > m - n) {
        return cmn(m, m - n);
    }
    unsigned long long num = 1;
    unsigned long long den = 1;
    while (n > 0) {
        num *= m--;
        den *= n--;
    }
    return num / den;
}
class Solution {
public:
    int climbStairs(int n) {
        int times = n / 2;
        int sum = 0;
        for (int i = 0; i <= times; i++) {
            sum += cmn(n - i, i);
        }
        return sum;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.climbStairs(atoi(argv[1])) << endl;
    return 0;
}
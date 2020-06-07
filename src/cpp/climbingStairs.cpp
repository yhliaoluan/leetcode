/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include "header.h"

class Solution {
public:
    int climbStairs(int n) {
        int a[64] = {0};
        a[0] = 1;
        a[1] = 2;
        for (int i = 2; i < n; i++) {
            a[i] = a[i - 2] + a[i - 1];
        }
        return a[n - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.climbStairs(atoi(argv[1])) << endl;
    return 0;
}

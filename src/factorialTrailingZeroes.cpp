/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
#include "header.h"

class Solution {
public:
    int trailingZeroes(int n) {
        return min(countOf2(n), countOf5(n));
    }

    int countOf2(int n) {
        if (n < 2) { return 0; }
        return n / 2 + countOf2(n / 2);
    }

    int countOf5(int n) {
        if (n < 5) { return 0; }
        return n / 5 + countOf5(n / 5);
    }
};

int main(int argc, char **argv) {
    cout << Solution().trailingZeroes(atoi(argv[1])) << endl;
    return 0;
}
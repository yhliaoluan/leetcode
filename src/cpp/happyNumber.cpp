/*
 *Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Credits:
Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
 * */

#include "header.h"
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sums;
        for (;;) {
            int sum = 0;
            while (n) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            if (sum == 1) { return true; }
            if (sums.find(sum) != sums.end()) { return false; }
            sums.insert(sum);
            n = sum;
        }
    }
};

int main(int argc, char **argv) {
    cout << Solution().isHappy(atoi(argv[1])) << endl;
    return 0;
}

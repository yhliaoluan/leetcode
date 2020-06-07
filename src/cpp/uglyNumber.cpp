/*
 *Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
 * */
#include "header.h"

class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;
        int primes[] = { 2, 3, 5 };
        for (int prime : primes) {
            while (num % prime == 0)
                num /= prime; 
        }
        return num == 1;
    }
};

int main(int argc, char **argv) {
    cout << Solution().isUgly(atoi(argv[1])) << endl;
    return 0;
}

/*
 *Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int factor = 1;
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & factor) == factor) count++;
            factor <<= 1;
        }
        return count;
    }
};

int main(int argc, char **argv) {
    cout << Solution().hammingWeight(atoll(argv[1])) << endl;
    return 0;
}

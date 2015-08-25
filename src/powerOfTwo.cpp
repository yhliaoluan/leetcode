/*
 *Given an integer, write a function to determine if it is a power of two.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int factor = 1;
        int count = 0;
        for (int i = 0; i < 31; i++) {
            if ((n & factor) == factor) count++;
            factor = factor << 1;
        }
        return count == 1;
    }
};

int main(int argc, char **argv) {
    cout << Solution().isPowerOfTwo(atoi(argv[1])) << endl;
    return 0;
}

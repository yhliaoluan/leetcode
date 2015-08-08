/*
 *Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        int bit = 0x40000000;
        for (int i = 0; i < 31; i++) {
            if ((n & bit) == bit) {
                if ((m & bit) == bit) {
                    result |= bit;
                } else {
                    break;
                }
            }
            bit >>= 1;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    cout << Solution().rangeBitwiseAnd(atoi(argv[1]), atoi(argv[2])) << endl;
    return 0;
}

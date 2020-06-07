/*
 *Implement int sqrt(int x).

Compute and return the square root of x.
 * */
#include "header.h"

class Solution {
public:
    int mySqrt(int x) {
        return bin_src(x, 0, min(x, 46340));
    }
    int bin_src(int x, int low, int up) {
        if (low == up) { return low * low <= x ? low : max(0, low - 1); }
        int bin = (low + up) / 2;
        if (bin * bin >= x) {
            return bin_src(x, low, bin);
        } else {
            return bin_src(x, bin + 1, up);
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.mySqrt(atoi(argv[1])) << endl;
    return 0;
}

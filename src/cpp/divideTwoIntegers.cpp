/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return INT_MAX.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        long long m = abs((long long)dividend);
        long long n = abs((long long)divisor);
        long long sum = 0;
        long long count = 0;
        while ((sum + n) <= m) {
            long long step = n;
            long long c = 1;
            while ((sum + step) <= m) {
                step <<= 1;
                c <<= 1;
            }
            sum += (step >> 1);
            count += (c >> 1);
        }
        if (dividend < 0 && divisor > 0 || divisor < 0 && dividend > 0) {
            count = -count;
        }
        return min(count, (long long)INT_MAX);
    }
};

int main(int argc, char **argv) {
    if (argc > 2) {
        Solution s;
        cout << s.divide(atoi(argv[1]), atoi(argv[2])) << endl;
    } else {
        cout << "invalid arguments." << endl;
    }
}
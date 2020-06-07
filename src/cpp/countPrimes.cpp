/*
 *Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        int count = n - 2;
        for (int i = 2; i * i < n; i++) {
            if (primes[i]) {
                for (int j = i * i; j < n; j += i) {
                    if (primes[j]) {
                        primes[j] = false;
                        count--;
                    }
                }
            }
        }
        return max(0, count);
    }
};

int main(int argc, char **argv) {
    cout << Solution().countPrimes(atoi(argv[1])) << endl;
    return 0;
}

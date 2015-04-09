/*

*/
#include "header.h"

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double r = pow(x, n / 2);
        if (n % 2 == 0) {
            return r * r; 
        } else {
            return x * r * r;
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.pow(stod(argv[1]), atoi(argv[2])) << endl;
    return 0;
}
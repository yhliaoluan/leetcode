/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        return dividend / divisor;
    }
};

int main(int argc, char **argv) {
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
    if (argc > 2) {
        Solution s;
        cout << s.divide(atoi(argv[1]), atoi(argv[2])) << endl;
    } else {
        cout << "invalid arguments." << endl;
    }
}
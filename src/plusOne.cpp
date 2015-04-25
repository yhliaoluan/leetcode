/*
 *Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
 * */
#include "header.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int factor = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += factor;
            factor = digits[i] / 10;
            digits[i] %= 10;
        }
        if (factor > 0) {
            digits.insert(digits.begin(), factor);
        }
        return digits;
    }
};

int main(int argc, char **argv) {
    vector<int> digits;
    for (int i = 1; i < argc; i++)
        digits.push_back(atoi(argv[i]));
    print_vector(digits);
    Solution s;
    print_vector(s.plusOne(digits));
    return 0;
}

/*
 *Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator;
        long long den = denominator;
        int factor = num * den >= 0 ? 1 : -1;
        num = abs(num);
        den = abs(den);
        long long integer = num / den;
        long long mod = num % den; 
        unordered_map<long long, int> mods;
        int index = 0;
        mods.insert(make_pair(mod, index));
        string frac;
        while (mod != 0) {
            frac += std::to_string(mod * 10 / den);
            index++;
            mod = mod * 10 % den;
            if (mods.find(mod) != mods.end()) {
                break;
            }
            mods.insert(make_pair(mod, index));
        }
        if (mod != 0) {
            frac.append(")");
            frac.insert(mods[mod], "(");
        }
        string result;
        if (factor < 0) { result.append("-"); }
        result += std::to_string(integer);
        if (!frac.empty()) {
            result.append(".").append(frac);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    cout << Solution().fractionToDecimal(atoi(argv[1]), atoi(argv[2])) << endl;
    return 0;
}

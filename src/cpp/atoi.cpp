/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/

#include <stdio.h>
#include <limits.h>

class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL) return 0;

        long long value = 0;
        int positive = 1;
        char *begin = const_cast<char *>(str);
        while (*begin == ' ') begin++;

        if (*begin == '+') {
            begin++;
        } else if (*begin == '-') {
            begin++;
            positive = -1;
        }

        char *end = begin;
        while (*end >= '0' && *end <= '9')
            end++;

        long long factor = 1;
        while (end-- != begin) {
            long long v = *end - '0';
            v *= factor;
            value += v;
            if (value > INT_MAX) {
                return positive == 1 ? INT_MAX : INT_MIN;
            }
            factor *= 10;
        }

        return value * positive;
    }
};

int main(int argc, char **argv) {
    if (argc > 1) {
        Solution s;
        printf("%s to %d\n", argv[1], s.atoi(argv[1]));
    }
    return 0;
}

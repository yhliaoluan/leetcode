/*
 Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
 * */
#include <stdio.h>

char r[16];

char *convert(int n, char *result, char x, char y, char z) {
    if (n >= 1 && n < 4) {
        while (n-- > 0) {
            *result++ = x;
        }
    } else if (n == 4) {
        *result++ = x;
        *result++ = y;
    } else if (n >= 5 && n < 9) {
        *result++ = y;
        while (n-- > 5) {
            *result++ = x;
        }
    } else if (n == 9) {
        *result++ = x;
        *result++ = z;
    }
    return result;
}

char *intToRoman(int num) {
    char *result = r;
    int n = num / 1000;
    memset(result, 0, sizeof(char) * 16);
    while (n-- > 0) {
        *result++ = 'M';
    }
    num %= 1000;
    n = num / 100;
    result = convert(n, result, 'C', 'D', 'M');
    num %= 100;
    n = num / 10;
    result = convert(n, result, 'X', 'L', 'C');
    num %= 10;
    result = convert(num, result, 'I', 'V', 'X');
    return r;
}

#define TEST(n) printf("%d to %s\n", n, intToRoman(n))

int main(int argc, char **argv) {
    int i;
    TEST(3000);
    TEST(3300);
    TEST(3333);
    TEST(99);
    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            TEST(atoi(argv[i]));
        }
    }
    return 0;
}

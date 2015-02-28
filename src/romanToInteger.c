/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999. 
 * */

int romanToInt(char *s) {
    int num = 0;
    char c;
    while (*s != '\0') {
        c = *s++;
        switch (c) {
        case 'I':
            if (*s == 'V') {
                num += 4;
                s++;
            } else if (*s == 'X') {
                num += 9;
                s++;
            } else {
                num += 1;
            }
            break;
        case 'V':
            num += 5;
            break;
        case 'X':
            if (*s == 'L') {
                num += 40;
                s++;
            } else if (*s == 'C') {
                num += 90;
                s++;
            } else {
                num += 10;
            }
            break;
        case 'L':
            num += 50;
            break;
        case 'C':
            if (*s == 'D') {
                num += 400;
                s++;
            } else if (*s == 'M') {
                num += 900;
                s++;
            } else {
                num += 100;
            }
            break;
        case 'D':
            num += 500;
            break;
        case 'M':
            num += 1000;
            break;
        default:
            break;
        }
    }
    return num;
}

#define TEST(x, y) if (romanToInt(x) != y)\
    printf("FAILED %s, result: %d, should be: %d\n", x, romanToInt(x), y)

int main(int argc, char **argv) {
    int n;
    TEST("MMMCCCXXXIII", 3333);
    TEST("MCDXXXVII", 1437);
    TEST("MDCCCLXXX", 1880);
    TEST("XC", 90);
    if (argc > 1) {
        for (n = 0; n < argc; n += 2) {
            TEST(argv[n], atoi(argv[n + 1]));
        }
    }
    return 0;
}

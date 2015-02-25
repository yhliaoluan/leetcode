/**
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
 */

#include <stdio.h>
#include <math.h>

#define INT_MAX 2147483647
#define INT_MIN -INT_MAX - 1

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int factor = x > 0 ? 1 : -1;
        x = abs(x);
        while (x > 0) {
            int mod = x % 10;
            if (result > (INT_MAX / 10)) {
                return 0;
            }
            result = result * 10 + x % 10;
            x = x / 10;
        }

        return result * factor;
    }
};
static Solution _solution;

#define TEST(x,y) if ((y) != _solution.reverse((x))) printf("FAILED %d %d\n", x, y); else printf("PASS %d %d\n", x, y);

int main(int argc, char **argv) {
    TEST(123, 321);
    TEST(-123, -321);
    TEST(100, 1);
    TEST(INT_MAX, 0);
    TEST(INT_MIN, 0);

    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        TEST(x, y);
    }

    return 0;
}

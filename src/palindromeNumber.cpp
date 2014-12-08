#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        } else if (x < 100) {
            return (x / 10) == (x % 10);
        } else if (x < 1000) {
            return (x / 100) == (x % 10);
        } else if (x < 10000) {
            return (x / 1000) == (x % 10) &&
                (x / 100 % 10) == (x % 100 /10);
        } else if (x < 100000) {
            return (x / 10000) == (x % 10) &&
                (x / 1000 % 10) == (x % 100 / 10);
        } else if (x < 1000000) {
            return (x / 100000) == (x % 10) &&
                (x / 10000 % 10) == (x % 100 / 10) &&
                (x / 1000 % 10) == (x % 1000 / 100);
        } else if (x < 10000000) {
            return (x / 1000000) == (x % 10) &&
                (x / 100000 % 10) == (x % 100 / 10) &&
                (x / 10000 % 10) == (x % 1000 / 100);
        } else if (x < 100000000) { 
            return (x / 10000000) == (x % 10) &&
                (x / 1000000 % 10) == (x % 100 / 10) &&
                (x / 100000 % 10) == (x % 1000 / 100) &&
                (x / 10000 % 10) == (x % 10000 / 1000);
        } else if (x < 1000000000) {
            return (x / 100000000) == (x % 10) &&
                (x / 10000000 % 10) == (x % 100 / 10) &&
                (x / 1000000 % 10) == (x % 1000 / 100) &&
                (x / 100000 % 10) == (x % 10000 / 1000);
        } else if (x < 10000000000) {
            return (x / 1000000000) == (x % 10) &&
                (x / 100000000 % 10) == (x % 100 / 10) &&
                (x / 10000000 % 10) == (x % 1000 / 100) &&
                (x / 1000000 % 10) == (x % 10000 / 1000) &&
                (x / 100000 % 10) == (x % 100000 / 10000);
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    printf(s.isPalindrome(atoi(argv[1])) ? "true" : "false");
}

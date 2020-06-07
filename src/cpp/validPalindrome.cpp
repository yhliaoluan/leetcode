#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        size_t size = s.size();
        if (size < 2) {
            return true;
        }
        const char *msg = s.c_str();
        int begin = 0;
        int end = size - 1;
        for (;;) {
            int type1, type2;
            while (begin < size && (type1 = getType(msg[begin])) == 0)
                begin++;
            while (end > -1 && (type2 = getType(msg[end])) == 0)
                end--;
            if (begin >= end) {
                break;
            }
            if (type1 != type2) {
                return false;
            }
            if (!isEqual(msg[begin], msg[end])) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }

private:
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z');
    }

    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }

    int getType(char c) {
        if (isLetter(c)) {
            return 1;
        } else if (isNumber(c)) {
            return 2;
        } else {
            return 0;
        }
    }

    bool isEqual(char a, char b) {
        int result = abs(a - b);
        return result == 0 || result == 32;
    }
};

int main(int argc, char **argv) {
    Solution s;
    if (argc >= 2) {
        printf("%d\n", s.isPalindrome(argv[1]));
    }
    return 0;
}

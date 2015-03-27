/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
*/
#include <iostream>
using namespace std;

static int getMaxMatchLength(const char *needle, int index) {
    for (int i = index; i > 0; i--) {
        if (memcmp(needle, needle + index + 1 - i, i) == 0) {
            return i;
        }
    }
    return 0;
}

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (!haystack || !needle) {
            return -1;
        }
        int ln = strlen(needle);
        int *table = new int[ln];
        int index = 0;
        while (needle[index] != '\0') {
            table[index] = getMaxMatchLength(needle, index);
            index++;
        }
        int i = 0;
        for (;;) {
            index = i;
            int j = 0;
            while (haystack[i] != '\0' && needle[j] != '\0' && haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (needle[j] == '\0') {
                return index;
            }
            if (haystack[i] == '\0') {
                return -1;
            }
            index += j > 0 ? (j - table[j - 1]) : 1;
            i = index;
        }
        return -1;
    }
};

int main(int argc, char **argv) {
    if (argc > 2) {
        Solution s;
        cout << s.strStr(argv[1], argv[2]) << endl;
    }
    return 0;
}
/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
*/
#include "header.h"

static vector<int> getNextTable(string& needle) {
    if (needle.size() == 0) {
        return vector<int>();
    }
    vector<int> next(needle.size(), 0);
    for (int i = 1; i < needle.size(); i++) {
        int j = next[i - 1];
        while (j > 0 && needle[j] != needle[i])
            j = next[j - 1];
        next[i] = j + (needle[j] == needle[i]);
    }
    return next;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> table = getNextTable(needle);
        int index = 0;
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
    cout << Solution().strStr(argv[1], argv[2]) << endl;
    return 0;
}

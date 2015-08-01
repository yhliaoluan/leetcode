/*
 *Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
 * */
#include "header.h"

static vector<string> split(string &s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');
        for (int i = 0; i < v1.size() || i < v2.size(); i++) {
            int v1int = 0, v2int = 0;
            if (i < v1.size()) { v1int = stoi(v1[i]); }
            if (i < v2.size()) { v2int = stoi(v2[i]); }
            if (v1int > v2int) { return 1; }
            else if (v1int < v2int) { return -1; }
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    cout << Solution().compareVersion(argv[1], argv[2]) << endl;
    return 0;
}

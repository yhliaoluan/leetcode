/*
 *Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.
 * */

#include "header.h"

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0) {
            result.insert(0, 1, (char) ((n - 1) % 26 + 'A'));
            n = (n - 1) / 26;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    cout << Solution().convertToTitle(atoi(argv[1])) << endl;
    return 0;
}

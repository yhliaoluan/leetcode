/**
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }

        char *content = (char *)malloc(sizeof(char) * (s.size() + 1));
        content[s.size()] = 0;
        int index = 0;
        int indexTmp = 0;
        while (index < s.size()) {
            int i = indexTmp * 2 * (nRows - 1);
            if (i >= s.size()) {
                break;
            }
            content[index++] = s[i];
            indexTmp++;
        }

        for (int row = 1; row < nRows - 1; row++) {
            indexTmp = 0;
            while (index < s.size()) {
                int i = indexTmp * 2 * (nRows - 1) + row;
                if (i >= s.size()) {
                    break;
                }
                content[index++] = s[i];
                i = (indexTmp + 1) * 2 * (nRows - 1) - row;
                if (i >= s.size()) {
                    break;
                }
                content[index++] = s[i];
                indexTmp++;
            }
        }

        indexTmp = 0;
        while (index < s.size()) {
            int i = indexTmp * 2 * (nRows - 1) + nRows - 1;
            if (i >= s.size()) {
                break;
            }
            content[index++] = s[i];
            indexTmp++;
        }

        return string(content);
    }
};

int main() {
    Solution s;
    string converted = s.convert("PAYPALISHIRING", 3);
    printf("%s\n", converted.c_str());

    return 0;
}

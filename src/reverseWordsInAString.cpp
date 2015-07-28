/*
 *Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
 * */
#include "header.h"

class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
        int start = 0;
        while (s[start] == ' ') {
            start++;
        }
        i = j = start;
        int index = 0;
        while (j < s.size()) {
            i = j;
            while (s[j] != ' ' && j < s.size()) {
                j++;
            }
            int end = j - 1;
            start = i;
            while (start < end) {
                swap(s[start++], s[end--]);
            }
            while (i < j) {
                s[index++] = s[i++];
            }
            while (s[j] == ' ') {
                j++;
            }
            if (j < s.size()) {
                s[index++] = ' ';
            }
        }
        s.resize(index);
    }
};

int main(int argc, char **argv) {
    string str(argv[1]);
    Solution s;
    s.reverseWords(str);
    cout << "\"" << str << "\"" << endl;
    return 0;
}

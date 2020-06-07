/*
Write a function to find the longest common prefix string amongst an array of strings. 
 * */
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int index = 0;
        int i = 0;
        char c = 0;
        if (strs.size() == 0) {
            return "";
        }
        for (;;) {
            if (index >= strs[0].size()) {
                break;
            }
            c = strs[0][index];
            for (i = 1; i < strs.size(); i++) {
                if (strs[i].size() <= index ||
                    strs[i][index] != c) {
                    goto lbl_break;
                }
            }
            index++;
        }
lbl_break:
        return strs[0].substr(0, index);
    }
};

static Solution _s;

int main() {
    vector<string> strs;
    strs.push_back("a");
    printf("%s\n", _s.longestCommonPrefix(strs).c_str());
    return 0;
}

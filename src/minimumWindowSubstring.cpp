/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
 * */
#include "header.h"

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) { return ""; }
        int start = 0;
        int pre = 0;
        unordered_map<char, int> mapt;
        for (int i = 0; i < t.size(); i++) {
            mapt[t[i]]++;
        }
        unordered_map<char, int> maps;
        int count = 0;
        string result;
        while (pre < s.size()) {
            if (mapt.find(s[pre]) != mapt.end()) {
                maps[s[pre]]++;
                if (maps[s[pre]] <= mapt[s[pre]]) {
                    count++;
                    if (count == t.size()) {
                        unordered_map<char, int>::iterator itt;
                        while ((itt = mapt.find(s[start])) == mapt.end() ||
                            maps[s[start]] > itt->second) {
                            if (itt != mapt.end()) maps[s[start]]--;
                            start++;
                        }
                        if (result.empty() || (pre-start+1) < result.size()) {
                            result = s.substr(start, pre-start+1);
                        }
                        maps[s[start]]--;
                        start++;
                        count--;
                    }
                }
            }
            pre++;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.minWindow(argv[1], argv[2]) << endl;
    return 0;
}

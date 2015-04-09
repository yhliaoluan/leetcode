/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
#include "header.h"
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > m;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            m[str].push_back(strs[i]);
        }
        vector<string> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second.size() > 1) {
                result.insert(result.end(), it->second.begin(), it->second.end());
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    vector<string> strs;
//    for (int i = 1; i < argc; i++) {
//        strs.push_back(argv[i]);
//    }
    string ss;
    while (cin >> ss)
        strs.push_back(ss);
    cout << strs.size() << endl;
    Solution s;
    vector<string> result = s.anagrams(strs);
    cout << "result: " << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
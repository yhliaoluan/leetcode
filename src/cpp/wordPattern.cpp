/*
 *Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 * */
#include "header.h"

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> elems;
        split(str, ' ', elems);
        unordered_map<string, char> table;
        vector<bool> used(26, false);
        if (elems.size() != pattern.size()) return false;
        for (int i = 0; i < pattern.size(); i++) {
            if (table.find(elems[i]) == table.end()) {
                if (used[pattern[i] - 'a']) return false;
                table[elems[i]] = pattern[i];
                used[pattern[i] - 'a'] = true;
            } else {
                if (table[elems[i]] != pattern[i]) return false;
            }
        }
        return true;
    }
private:
    void split(string &str, char delim, vector<string> &result) {
        stringstream ss(str);
        string item;
        while (getline(ss, item, delim)) {
            result.push_back(item);
        }
    }
};

int main(int argc, char **argv) {
    cout << Solution().wordPattern(argv[1], argv[2]) << endl;
    return 0;
}

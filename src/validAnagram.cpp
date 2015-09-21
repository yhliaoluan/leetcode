/*
 *Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
 * */
#include "header.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        char table[26] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            table[s[i] - 'a']++;
            table[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (table[i] != 0) return false;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    cout << Solution().isAnagram(argv[1], argv[2]) << endl;
    return 0;
}

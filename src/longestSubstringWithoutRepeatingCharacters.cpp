/*
   Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
   */
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        unordered_map<char, int> m;
        int longest = 0;
        while (j < s.size()) {
            if (m.find(s[j]) != m.end()) {
                longest = max(j - i, longest);
                while (i < j && s[i] != s[j]) {
                    m.erase(s[i++]);
                }
                m.erase(s[i++]);
            } else {
                pair<char, int> p(s[j], j);
                m.insert(p);
                j++;
            }
        }
        return max(j - i, longest);
    }
};

int main(int argc, char **argv) {
    Solution s;
    printf("%d\n", s.lengthOfLongestSubstring(argv[1]));
}

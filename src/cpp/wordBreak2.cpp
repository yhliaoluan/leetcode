/*
 *Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
 * */
#include "header.h"

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (hash.find(s) != hash.end()) {
            return hash[s];
        }
        hash.insert(make_pair(s, vector<string>()));

        if (wordDict.find(s) != wordDict.end()) {
            hash[s].push_back(s);
        }

        for (int i = 0; i < s.size() - 1; i++) {
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                vector<string> s2s = wordBreak(s.substr(i + 1, s.size() - 1 - i), wordDict);
                for (string s2 : s2s) {
                    hash[s].push_back(s.substr(0, i + 1) + " " + s2);
                }
            }
        }
        return hash[s];
    }

private:
    unordered_map<string, vector<string> > hash;
};

int main(int argc, char **argv) {
    unordered_set<string> dict;
    for (int i = 2; i < argc; i++) {
        dict.insert(argv[i]);
    }
    Solution s;
    vector<string> words = s.wordBreak(argv[1], dict);
    for (int i = 0; i < words.size(); i++) {
        cout << "\"" << words[i] << "\"" << endl;
    }

    return 0;
}

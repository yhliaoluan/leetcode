/*
 *Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
 * */
#include "header.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        int count = 1;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                string pop = q.front();
                if (pop.compare(endWord) == 0) { return count; }
                q.pop();
                for (int i = 0; i < pop.size(); i++) {
                    for (int j = 0; j < 26; j++) {
                        pop[i] = ((pop[i] + 1 - 'a') % 26 + 'a');
                        if (pop.compare(endWord) == 0) {
                            return count + 1;
                        }
                        unordered_set<string>::iterator it = wordDict.find(pop);
                        if (it != wordDict.end()) {
                            q.push(pop);
                            wordDict.erase(it);
                        }
                    }
                }
            }
            count++;
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    unordered_set<string> dict;
    for (int i = 3; i < argc; i++) {
        dict.insert(argv[i]);
    }
    Solution s;
    cout << s.ladderLength(argv[1], argv[2], dict) << endl;
    return 0;
}

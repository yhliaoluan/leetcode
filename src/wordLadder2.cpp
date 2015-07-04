/*
 *Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
 * */

#include "header.h"

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;
        queue<vector<string> > q;
        vector<string> v;
        v.push_back(start);
        q.push(v);
        if (start.compare(end) == 0) {
            result.push_back(v);
            return result;
        }
        int found = 0;
        while (!q.empty() && !found) {
            int size = q.size();
            while (size-- > 0) {
                vector<string> vec = q.front();
                q.pop();
                string last = vec[vec.size() - 1];
                for (int i = 0; i < last.size(); i++) {
                    for (int j = 0; j < 26; j++) {
                        last[i] = ((last[i] + 1 - 'a') % 26 + 'a');
                        if (last.compare(end) == 0) {
                            vec.push_back(end);
                            result.push_back(vec);
                            found = 1;
                        } else if (dict.find(last) != dict.end()) {
                            int duplicated = 0;
                            for (int k = 0; k < vec.size(); k++) {
                                if (last.compare(vec[k]) == 0) {
                                    duplicated = 1;
                                    break;
                                }
                            }
                            if (!duplicated) {
                                vector<string> copy = vec;
                                copy.push_back(last);
                                q.push(copy);
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    unordered_set<string> dict;
    for (int i = 3; i < argc; i++) {
        dict.insert(argv[i]);
    }
    Solution s;
    print_grid(s.findLadders(argv[1], argv[2], dict));
    return 0;
}

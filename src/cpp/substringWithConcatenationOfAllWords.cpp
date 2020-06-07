/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        if (L.size() == 0) {
            return result;
        }
        unordered_map<string, int> m;
        unordered_map<string, int> tmp;
        for (int i = 0; i < L.size(); i++) {
            m[L[i]]++;
            tmp[L[i]] = 0;
        }
        int len = L[0].size();
        for (int i = 0; i < (int)S.size() - len * (int)L.size() + 1; i++) {
            if (m.count(S.substr(i, len))) {
                int match = 1;
                for (int j = i; j < i + len * L.size(); j+= len) {
                    string str = S.substr(j, len);
                    unordered_map<string, int>::iterator it_m = m.find(str);
                    if (it_m != m.end()) {
                        int c = ++tmp[str];
                        if (c > it_m->second) {
                            match = 0;
                            break;
                        }
                    } else {
                        match = 0;
                        break;
                    }
                }
                if (match) {
                    result.push_back(i);
                }
                for (auto it = tmp.begin(); it != tmp.end(); it++) {
                    it->second = 0;
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    vector<string> l;
    for (int i = 2; i < argc; i++) {
        l.push_back(argv[i]);
    }
    Solution s;
    vector<int> result = s.findSubstring(argv[1], l);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
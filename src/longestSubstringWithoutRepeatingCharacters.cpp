/*
   Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
   */
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Node {
    int index;
    char val;
    Node(int x, char y) : index(x), val(y) {}
} Node;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        map<char, Node> m;
        for (int j = 0; j < s.size(); j++) {
            map<char, Node>::iterator it = m.find(s[j]);
            if (it != m.end()) {
                if (m.size() > longest) {
                    longest = m.size();
                }
                removeLessThan(m, it->second.index + 1);
            }
            printf("insert %c %d\n", s[j], j);
            m.insert(map<char, Node>::value_type(s[j], Node(j, s[j])));
        }

        if (m.size() > longest) {
            longest = m.size();
        }
        return longest;
    }

private:
    void removeLessThan(map<char, Node> &m, int index) {
        map<char, Node>::iterator it = m.begin();
        for (; it != m.end();) {
            if (it->second.index < index) {
                printf("erase %c %d\n", it->second.val, it->second.index);
                it = m.erase(it);
            } else {
                it++;
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    printf("%d\n", s.lengthOfLongestSubstring(argv[1]));
}

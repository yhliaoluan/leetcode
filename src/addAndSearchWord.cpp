/*
 *Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
 * */
#include "header.h"
class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        map[word.size()].push_back(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        for (string &str : map[word.size()]) {
            if (compare(str, word) == 0) {
                return true;
            }
        }
        return false;
    }

private:
    int compare(const string &l, const string &r) {
        for (int i = 0; i < l.size() && i < r.size(); i++) {
            if (l[i] == '.' || r[i] == '.' || l[i] == r[i]) continue;
            return l[i] < r[i] ? -1 : 1;
        }
        if (l.size() < r.size()) { return -1; }
        else if (l.size() > r.size()) { return 1; }
        else return 0;
    }
    std::unordered_map<int, vector<string>> map;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
//

int main(int argc, char **argv) {
    WordDictionary dic;
    int opt = 1;//add
    for (int i = 1; i < argc; i++) {
        if (string("1").compare(argv[i]) == 0) {
            opt = 1;
        } else if (string("2").compare(argv[i]) == 0) {
            opt = 2;
        } else {
            if (opt == 1) {
                dic.addWord(argv[i]);
                cout << "add " << argv[i] << endl;
            } else if (opt == 2) {
                cout << "contain " << argv[i] << "? "
                    << dic.search(argv[i]) << endl;;
            }
        }
    }
    return 0;
}

/*
 *Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
 * */
#include "header.h"

class TrieNode {
public:
    TrieNode() : isLeaf(false), nodes(26, NULL) { }
    ~TrieNode() { for (auto n : nodes) if (n) delete n; }
    vector<TrieNode *> nodes;
    bool isLeaf;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->nodes[index] == NULL) {
                cur->nodes[index] = new TrieNode();
            }
            cur = cur->nodes[index];
        }
        cur->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->nodes[index] == NULL) { return false; }
            cur = cur->nodes[index];
        }
        return cur->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (cur->nodes[index] == NULL) { return false; }
            cur = cur->nodes[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(int argc, char **argv) {
    Trie trie;
    int opt = 1;
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]).compare("1") == 0) {
            opt = 1;
        } else if (string(argv[i]).compare("2") == 0) {
            opt = 2;
        } else if (string(argv[i]).compare("3") == 0) {
            opt = 3;
        } else {
            if (opt == 1) {
                trie.insert(argv[i]);
                cout << "insert " << argv[i] << endl;
            } else if (opt == 2) {
                cout << "search " << argv[i] << " " << trie.search(argv[i]) << endl;
            } else if (opt == 3) {
                cout << "start with " << argv[i] << " " << trie.startsWith(argv[i]) << endl;
            }
        }
    }
    return 0;
}

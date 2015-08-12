/*
 *Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
 * */
#include "header.h"

class TrieNode {
public:
    TrieNode(string val) : value(val), left(NULL), right(NULL) { }
    TrieNode() : value(""), left(NULL), right(NULL) { }
    TrieNode *left;
    TrieNode *right;
    string value;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        while (cur) {
            int res = cur->value.compare(word);
            if (res < 0) {
                if (cur->left == NULL) {
                    cur->left = new TrieNode(word);
                    return;
                } else {
                    cur = cur->left;
                }
            } else if (res > 0) {
                if (cur->right == NULL) {
                    cur->right = new TrieNode(word);
                    return;
                } else {
                    cur = cur->right;
                }
            } else {
                return;
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        while (cur) {
            int res = cur->value.compare(word);
            if (res < 0) {
                cur = cur->left;
            } else if (res > 0) {
                cur = cur->right;
            } else {
                return true;
            }
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        while (cur) {
            int res = cur->value.substr(0,
                min(prefix.size(), cur->value.size())).compare(prefix);
            if (res < 0) {
                cur = cur->left;
            } else if (res > 0) {
                cur = cur->right;
            } else {
                return true;
            }
        }
        return false;
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
    trie.search("a");
    return 0;
}

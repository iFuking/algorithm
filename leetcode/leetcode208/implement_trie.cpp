#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int CHILDSIZE = 30;

class TrieNode {
public:
    // Initialize your data structure here.
    bool is_word;
    TrieNode *next[CHILDSIZE];

    TrieNode(): is_word(false) {
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word[i]-'a';
            if (p->next[idx] == NULL) {
                p->next[idx] = new TrieNode();
            }
            p = p->next[idx];
        }
        p->is_word = true;
        return;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word[i]-'a';
            if (p->next[idx] == NULL) return false;
            p = p->next[idx];
        }
        return p->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i < prefix.length(); ++i) {
            int idx = prefix[i]-'a';
            if (p->next[idx] == NULL) return false;
            p = p->next[idx];
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


int main() {
    return 0;
}
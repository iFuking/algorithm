#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

const int CHSIZE = 30;

typedef struct TrieNode {
    bool is_word;
    TrieNode *next[CHSIZE];
    TrieNode(): is_word(false) {
        memset(next, 0, sizeof(next));
    }
}TrieNode;

class WordDictionary {
public:

    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
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

    void dfs(const string &word, int index, TrieNode *t, bool &found) {
        if (found) return;
        if (word.length() == index) {
            found = t->is_word;
            return;
        }

        if (isalpha(word[index])) {
            int idx = word[index]-'a';
            if (t->next[idx] == NULL) return;
            dfs(word, index+1, t->next[idx], found);
            return;
        }

        for (int i = 0; i < CHSIZE; ++i) {
            if (t->next[i] != NULL) {
                dfs(word, index+1, t->next[i], found);
            }
        }
        return;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        bool found = false;
        dfs(word, 0, root, found);
        return found;
    }

private:
    TrieNode *root;

};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


int main() {
    WordDictionary sol;
    sol.addWord("bat");
    sol.addWord("dad");
    sol.addWord("mad");
    cout << sol.search("pad") << endl;
    cout << sol.search("bad") << endl;
    cout << sol.search(".ad") << endl;
    cout << sol.search("b.") << endl;
    return 0;
}
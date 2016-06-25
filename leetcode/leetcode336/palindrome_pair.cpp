#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    TrieNode(): index(-1) {
        memset(next, 0, sizeof(next));
    }

    static const int ALPHASIZE = 'z'-'a'+1;
    int index;
    TrieNode *next[ALPHASIZE];
};

class Solution {
public:
    Solution() {
        root = new TrieNode();
    }

    void insert_trie(const string &word, int index) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word[i]-'a';

            if (p->next[idx] == NULL) {
                p->next[idx] = new TrieNode();
            }
            p = p->next[idx];
        }
        p->index = index;
        return;
    }

    bool is_palindrome(const string &s) {
        for (int i = 0; i < s.length()/2; ++i) {
            if (s[i] != s[s.length()-1-i]) {
                return false;
            }
        }
        return true;
    }

    void traverse_trie(TrieNode *p, string s, vector<pair<string, int> > &v) {
        if (p->index != -1) {
            v.push_back(make_pair(s, p->index));
        }

        for (int i = 0; i < p->ALPHASIZE; ++i) {
            if (p->next[i] != NULL) {
                char ch = 'a'+i;
                traverse_trie(p->next[i], s+ch, v);
            }
        }
        return;
    }

    // build trie tree, words in reverse order
    void build_trie(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            reverse(s.begin(), s.end());
            insert_trie(s, i);
        }
        return;
    }

    void search_trie(vector<string>& words, vector<vector<int> > &palin_pair) {
        // for each word, search in trie tree
        for (int i = 0; i < words.size(); ++i) {
            TrieNode *p = root;
            int j = 0;
            bool flag = false;
            // word character search, if palindrome
            for ( ; j < words[i].length(); ++j) {
                int idx = words[i][j]-'a';
                if (p->next[idx] == NULL) {
                    // trie tree path end
                    // 1. no match
                    // 2. end of a trie tree path word
                    if (p->index == -1) {
                        flag = true;  // 1. not match
                    }
                    break;
                }

                // for each word in trie tree path
                // is a palindrome pair
                if (p->index!=-1 && is_palindrome(words[i].substr(j))) {
                    vector<int> v(2);
                    v[0] = i; v[1] = p->index;
                    if (v[0] != v[1]) {
                        palin_pair.push_back(v);
                    }
                }

                p = p->next[idx];
            }

            if (flag) continue;

            // end of words[i], but trie tree path not
            // find all remained trie tree path, if palindrome
            if (j == words[i].length()) {
                vector<pair<string, int> > v;
                traverse_trie(p, "", v);
                for (int k = 0; k < v.size(); ++k) {
                    if (is_palindrome(v[k].first)) {
                        vector<int> u(2);
                        u[0] = i; u[1] = v[k].second;
                        if (u[0] != u[1]) {
                            palin_pair.push_back(u);
                        }
                    }
                }
                continue;
            }

            // end of trie tree path
            // find remain words[i] substring, if palindrome
            if (is_palindrome(words[i].substr(j))) {
                vector<int> v(2);
                v[0] = i; v[1] = p->index;
                if (v[0] != v[1]) {
                    palin_pair.push_back(v);
                }
            }
        }
        return;
    }

    vector<vector<int> > palindromePairs(vector<string>& words) {
        build_trie(words);

        vector<vector<int> > palin_pair;
        search_trie(words, palin_pair);

        return palin_pair;
    }

private:
    TrieNode *root;
};

int main() {
    string s[] = {
        "sll", "s", "lls", "sssll"
    };
    vector<string> v;
    for (int i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
        v.push_back(s[i]);
    }

    Solution sol;
    vector<vector<int> > ans = sol.palindromePairs(v);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i][0] << "," << ans[i][1] << endl;
    }
    return 0;
}
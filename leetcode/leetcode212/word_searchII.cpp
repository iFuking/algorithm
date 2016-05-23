#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

const int CHSIZE = 30;

typedef struct TrieNode {
    bool is_word;
    TrieNode *next[CHSIZE];
    TrieNode(): is_word(false) {
        memset(next, 0, sizeof(next));
    }
}TrieNode;

const int dir[][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

class Solution {
public:

    void init(vector<vector<char> >& board, vector<string>& words) {
        board_2d = board;
        row = board.size();
        if (row == 0) col = 0;
        else col = board[0].size();

        root = new TrieNode();
        build_trie(words);
        return;
    }

    void build_trie(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            TrieNode *p = root;
            for (int j = 0; j < words[i].length(); ++j) {
                int idx = words[i][j]-'a';
                if (p->next[idx] == NULL) {
                    p->next[idx] = new TrieNode();
                }
                p = p->next[idx];
            }
            p->is_word = true;
        }
        return;
    }

    void dfs(TrieNode *t, int r, int c, vector<char> &word, vector<vector<bool> > &visit) {
        int idx = board_2d[r][c]-'a';
        if (t->next[idx] == NULL) return;

        t = t->next[idx];
        if (t->is_word) {
            string str;
            for (int i = 0; i < word.size(); ++i) {
                str += word[i];
            }
            s.insert(str);
        }

        for (int i = 0; i < sizeof(dir)/sizeof(dir[0]); ++i) {
            int dr = r+dir[i][0], dc = c+dir[i][1];
            if (dr>=0 && dr<row && dc>=0 && dc<col && !visit[dr][dc]) {
                visit[dr][dc] = true;
                word.push_back(board_2d[dr][dc]);
                dfs(t, dr, dc, word, visit);
                word.pop_back();
                visit[dr][dc] = false;
            }
        }
        return;
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        init(board, words);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                vector<char> word;
                vector<vector<bool> > visit(row, vector<bool>(col, false));
                word.push_back(board[i][j]); visit[i][j] = true;
                dfs(root, i, j, word, visit);
            }
        }
        

        set<string>::iterator iter = s.begin();
        for ( ; iter != s.end(); ++iter) {
            v.push_back(*iter);
        }
        return v;
    }

private:
    TrieNode *root;
    vector<vector<char> > board_2d;
    int row, col;

    set<string> s;
    vector<string> v;

};

int main() {
    char b[4][4] = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    int row = sizeof(b)/sizeof(b[0]), col = sizeof(b[0])/sizeof(b[0][0]);
    vector<vector<char> > board(row, vector<char>(col));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            board[i][j] = b[i][j];
        }
    }

    vector<string> words;
    words.push_back("oath"); words.push_back("pea");
    words.push_back("eat"); words.push_back("rain");

    Solution sol;
    vector<string> v = sol.findWords(board, words);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    return 0;
}
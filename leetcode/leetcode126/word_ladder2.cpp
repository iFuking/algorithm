#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string> > ladders;

    bool find_path(const string beginWord, const string endWord, set<string>& wordList, map<string, vector<string> > &path) {
        int head = 0, tail = 1, tp_tail = tail;
        queue<string> q; q.push(beginWord); wordList.erase(beginWord);
        while (!q.empty()) {
            bool reach = false; vector<string> visit;
            while (head < tail) {
                string frnt = q.front(); q.pop(); ++head;
                for (int i = 0; i < frnt.length(); ++i) {
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        string word = frnt; word[i] = ch;
                        if (wordList.find(word) != wordList.end()) {
                            if (word == endWord) reach = true;
                            path[word].push_back(frnt);
                            visit.push_back(word);
                            q.push(word);
                            ++tp_tail;
                        }
                    }
                }
            }
            if (reach) return true;
            for (int i = 0; i < visit.size(); ++i) wordList.erase(visit[i]);
            tail = tp_tail;
        }
        return false;
    }

    void swap(string &s1, string &s2)
    {
        string s = s1; s1 = s2; s2 = s;
        return;
    }

    void back_trace_path(const string &word, const string &beginWord, map<string, vector<string> > &path, vector<string> &ladder)
    {
        if (word == beginWord) {
            for (int i = 0; i < ladder.size()/2; ++i) swap(ladder[i], ladder[ladder.size()-1-i]);
            ladders.push_back(ladder);
            return;
        }
        vector<string>::iterator iter = path[word].begin();
        for ( ; iter != path[word].end(); ++iter) {
            ladder.push_back(*iter);
            back_trace_path(*iter, beginWord, path, ladder);
            ladder.pop_back();
        }
        return;
    }

    vector<vector<string> > findLadders(string beginWord, string endWord, set<string> &wordList) {
        wordList.insert(beginWord); wordList.insert(endWord);
        map<string, vector<string> > path;
        if (!find_path(beginWord, endWord, wordList, path)) return ladders;
        vector<string> ladder; ladder.push_back(endWord);
        back_trace_path(endWord, beginWord, path, ladder);
        return ladders;
    }
};

int main()
{
	string a[] = {"hot", "dot", "dog", "lot", "log"};
	set<string> s;
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) s.insert(a[i]);
	set<string>::iterator iter = s.begin();
//	for ( ; iter != s.end(); ++iter) cout << *iter << " ";
//	cout << endl; cout << endl;

	Solution sol;
    vector<vector<string> > res = sol.findLadders("hit", "cog", s);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) cout << res[i][j] << " ";
        cout << endl;
    }
	return 0;
}

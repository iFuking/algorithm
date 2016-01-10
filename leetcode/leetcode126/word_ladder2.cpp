#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string> > ladders;

    bool diff_one(const string &w1, const string &w2)
    {
        if (w1.length() != w2.length()) return false;
        int diff_cnt = 0;
        for (int i = 0; i < w1.length(); ++i) {
            if (w1[i] != w2[i]) ++diff_cnt;
            if (diff_cnt > 1) return false;
        }
        return true;
    }

    void dfs(const string &word, const string &endWord, map<string, int> &word_map, vector<bool> &visit, vector<string> &ladder)
    {
        if (ladders.size()>0 && ladder.size()>ladders[0].size()) return;
        if (word == endWord) {
            if (ladders.size()>0 && ladder.size()<ladders[0].size()) ladders.clear();
            ladders.push_back(ladder);
            // for (int i = 0; i < ladder.size(); ++i) cout << ladder[i] << " ";
            // cout << endl;
            return;
        }
        map<string, int>::iterator iter = word_map.begin();
        for ( ; iter != word_map.end(); ++iter) {
            if (!visit[iter->second] && diff_one(word, iter->first)) {
                // string new_word = iter->first;
                ladder.push_back(iter->first);
                visit[iter->second] = true;
                dfs(iter->first, endWord, word_map, visit, ladder);
                visit[iter->second] = false;
                ladder.pop_back();
            }
        }
        return;
    }

    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(beginWord); wordList.insert(endWord);
        map<string, int> word_map; vector<string> ladder;
        unordered_set<string>::iterator iter = wordList.begin();
        for (int i = 0; iter != wordList.end(); ++iter) {
            word_map[*iter] = i++;
            // cout << *iter << " " << word_map[*iter] << ", ";
        }
        // cout << endl;
//        map<string, int>::iterator it = word_map.begin();
//        cout << it->first << " " << it->second << endl;

        vector<bool> visit(wordList.size(), false);
        visit[word_map[beginWord]] = true; ladder.push_back(beginWord);
        dfs(beginWord, endWord, word_map, visit, ladder);
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

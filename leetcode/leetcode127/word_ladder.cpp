#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;

//class Solution {
//public:
//    bool check_diff(string &w1, string &w2)
//    {
//        if (w1.length() != w2.length()) return false;
//        int diffs = 0;
//        for (int i = 0; i < w1.length(); ++i) {
//            if (w1[i] != w2[i]) ++diffs;
//            if (diffs > 1) return false;
//        }
//        return diffs==1;
//    }
//
//    int bfs(int begin_idx, int end_idx, vector<bool> &visit, map<int, vector<int> > &word_gp)
//    {
//        queue<int> q; int dist = 1;
//        q.push(begin_idx);
//
//        int head = 0, tail = 1, tp_tail = tail;
//        visit[begin_idx] = true;
//        while (!q.empty()) {
//            int idx = q.front(); q.pop(); ++head;
//            if (idx == end_idx) return dist;
//            vector<int>::iterator iter = word_gp[idx].begin();
//            for ( ; iter != word_gp[idx].end(); ++iter) {
//                if (!visit[*iter]) { q.push(*iter); visit[*iter] = true; ++tp_tail; }
//            }
//            if (head == tail) { ++dist; tail = tp_tail; }
//        }
//        return 0;
//    }
//
//    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
//        wordList.insert(beginWord); wordList.insert(endWord);
//        unordered_set<string>::iterator iter = wordList.begin();
//        vector<string> word_list;
//        for ( ; iter != wordList.end(); ++iter) word_list.push_back(*iter);
//
//        int begin_idx, end_idx;
//        for (int i = 0; i < word_list.size(); ++i) {
//            if (beginWord == word_list[i]) begin_idx = i;
//            if (endWord == word_list[i]) end_idx = i;
//        }
//
//        map<int, vector<int> > word_gp;
//        for (int i = 0; i < word_list.size()-1; ++i) {
//            for (int j = i+1; j < word_list.size(); ++j) {
//                if (check_diff(word_list[i], word_list[j])) {
//                    word_gp[i].push_back(j);
//                    word_gp[j].push_back(i);
//                }
//            }
//        }
//
//        vector<bool> visit(word_list.size(), false);
//        return bfs(begin_idx, end_idx, visit, word_gp);
//    }
//};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(beginWord); wordList.insert(endWord);
        queue<pair<string, int> > q; q.push(make_pair(beginWord, 1));
        wordList.erase(beginWord);
        while (!q.empty()) {
            pair<string, int> frnt = q.front(); q.pop();
            for (int i = 0; i < frnt.first.length(); ++i) {
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    string word = frnt.first; word[i] = ch;
                    if (wordList.find(word) != wordList.end()) {
                        if (word == endWord) return frnt.second+1;
                        q.push(make_pair(word, frnt.second+1));
                        wordList.erase(word);
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
	string a[] = {"hot", "dog", "dot", "lot", "log"};
	set<string> v;
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) v.insert(a[i]);
	Solution sol;
	cout << sol.ladderLength("hit", "cog", v) << endl;
	return 0;
}

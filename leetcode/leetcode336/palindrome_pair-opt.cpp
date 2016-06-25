#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool is_palindrome(const string &s) {
        int s_length = s.length();
        for (int i = 0; i < s_length/2; ++i) {
            if (s[i] != s[s_length-1-i]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int> > palindromePairs(vector<string>& words) {
        unordered_map<string, int> rev_m;
        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            reverse(s.begin(), s.end());
            rev_m[s] = i;
        }

        vector<vector<int> > pali_pair;
        if (rev_m.find("") != rev_m.end()) {
            for (int i = 0; i < words.size(); ++i) {
                if (words[i].size()>0 && is_palindrome(words[i])) {
                    vector<int> v(2);
                    v[0] = rev_m[""]; v[1] = i;
                    pali_pair.push_back(v);
                }
            }
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (rev_m.find(left)!=rev_m.end() && 
                    is_palindrome(right)) {
                    vector<int> v(2);
                    v[0] = i; v[1] = rev_m[left];
                    if (v[0] != v[1]) {
                        pali_pair.push_back(v);
                    }
                }

                if (rev_m.find(right)!=rev_m.end() &&
                    is_palindrome(left)) {
                    vector<int> v(2);
                    v[0] = rev_m[right]; v[1] = i;
                    if (v[0] != v[1]) {
                        pali_pair.push_back(v);
                    }
                }
            }
        }
        return pali_pair;
    }
};

int main() {
    string s[] = {
        "a", "", "aa", "ba"
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
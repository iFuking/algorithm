#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        // dp[i]: whether s.substr(0, i) can word_break
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;  // empty string

        // dp[i] = true, when dp[j]=true and s.substr(j, i-j+1) in wordDict
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (dp[j] && wordDict.find(s.substr(j, i-j))!=wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

int main() {
    Solution sol;

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string int2str[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
	void dfs(vector<string> &dig2str, string s, int len, vector<string> &combs)
	{
		if (len == dig2str.size()) { combs.push_back(s); return; }
		for (int i = 0; i < dig2str[len].length(); ++i) dfs(dig2str, s+dig2str[len][i], len+1, combs);
	}

    vector<string> letterCombinations(string digits) {
		vector<string> dig2str, combs;
		for (int i = 0; i < digits.length(); ++i) {
			if (digits[i]>='2' && digits[i]<='9') dig2str.push_back(int2str[digits[i]-'2']);
		}
		if (dig2str.size() > 0) dfs(dig2str, "", 0, combs);
		return combs;
    }
};

int main()
{
	Solution sol;
	vector<string> ans = sol.letterCombinations("");
	for (int i = 0; i < ans.size(); ++i) printf("%8s", ans[i].c_str());
	cout << ans.size() << endl;
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		else if (strs.size() == 1) return strs[0];

		int len = 0x7fffffff;
		for (int i = 0; i < strs.size(); ++i) {
			if (strs[i].length() < len) len = strs[i].length();
		}

		string common = "";
		for (int i = 0; i < len; ++i) {
			int flag = 0;
			for (int j = 1; j < strs.size(); flag=++j) {
				if (strs[0][i] != strs[j][i]) break;
			}
			if (flag == strs.size()) common += strs[0][i];
			else break;
		}
		return common;
    }
};

int main()
{
	Solution sol;
	string strs[] = {"apple", "ape", "application"};
	vector<string> ss(strs, strs+3);
	cout << sol.longestCommonPrefix(ss) << endl;
	return 0;
}
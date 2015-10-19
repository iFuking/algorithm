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

		string long_pre; int long_len = 0x7fffffff;
		for (int i = 0; i < strs.size()-1; ++i) {
			for (int j = i+1; j < strs.size(); ++j) {
				string common = "";
				for (int k = 0; k < len; ++k) {
					if (strs[i][k] != strs[j][k]) break;
					common += strs[i][k];
				}
				if (common.size() == 0) return "";
				if (common.size() < long_len) { long_pre = common; long_len = common.size(); len = long_len; }
			}
		}
		return long_pre;
    }
};

int main()
{
	Solution sol;
	string ss[] = {"apple", "application", "ape"};
	vector<string> strs(ss, ss+3);
	cout << sol.longestCommonPrefix(strs) << endl;
	return 0;
}
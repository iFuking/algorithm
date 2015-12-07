#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
		vector<char> s; s.push_back('1');
		for (int j = 1; j < n; ++j) {
			int len = s.size();
			vector<char> str;
			int index = 0, cnt = 0;
			for (int i = 0; i < len; ) {
				while (i<len && s[index]==s[i]) { ++cnt; ++i; }
				str.push_back(cnt+'0'); str.push_back(s[index]);
				index = i; cnt = 0;
			}
			s = str;
		}
		string str = "";
		for (int i = 0; i < s.size(); ++i) str += s[i];
		return str;
    }
};

int main()
{
	Solution sol;
	sol.countAndSay(7);
	return 0;
}
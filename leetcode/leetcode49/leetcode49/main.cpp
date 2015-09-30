#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp1(const char &ch1, const char &ch2) { return ch1 < ch2; }
bool cmp2(const string &s1, const string &s2) { return s1 < s2; }

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> group;
		vector<string>::iterator iter = strs.begin();
		for ( ; iter != strs.end(); ++iter) {
			string backup = *iter;
			sort(iter->begin(), iter->end(), cmp1);
			group[*iter].push_back(backup);
		}
		vector<vector<string>> group_str;
		map<string, vector<string>>::iterator ite = group.begin();
		for ( ; ite != group.end(); ++ite) group_str.push_back(ite->second);

		vector<vector<string>>::iterator it = group_str.begin();
		for ( ; it != group_str.end(); ++it) sort(it->begin(), it->end(), cmp2);
		return group_str;
    }
};

int main()
{
	Solution sol;
	char s[][5] = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<string> str(s, s+6);
	sol.groupAnagrams(str);
	return 0;
}